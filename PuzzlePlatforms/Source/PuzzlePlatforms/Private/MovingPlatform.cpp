// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	StaticMesh = CreateDefaultSubobject <UStaticMesh>(FName("Static Mesh"));
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Move platform in x direction at speed only on the server
	if (HasAuthority())
	{
		FVector NewLocation = GetActorLocation() + FVector(1, 0, 0) * speed * DeltaTime;
		SetActorLocation(NewLocation);
	}
}
