// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float speed = 5.0f;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
};
