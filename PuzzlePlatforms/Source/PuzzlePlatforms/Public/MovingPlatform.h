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

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float speed = 5.0f;

	UStaticMesh* StaticMesh = nullptr;

protected:
	virtual void BeginPlay() override;

public:
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;
	
};
