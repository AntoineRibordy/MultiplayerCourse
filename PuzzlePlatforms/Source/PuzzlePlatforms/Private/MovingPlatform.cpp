// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Move platform in x direction at speed only on the server
	if (HasAuthority()) 
	{
		
		FVector Location = GetActorLocation();
		FVector TargetDirection;
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (Location - GlobalStartLocation).Size();

		// Swap GlobalStartLocation for GlobalTargetLocation if we've moved past out target
		if (JourneyTravelled >= JourneyLength) 
		{
			// Swap our start and target location as we want to change moving direction
			FVector TempGlobalTargetLocation = GlobalTargetLocation;
			GlobalTargetLocation = GlobalStartLocation;
			GlobalStartLocation = TempGlobalTargetLocation;
		}
		TargetDirection = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += TargetDirection * speed * DeltaTime;
		SetActorLocation(Location);
	}
}
