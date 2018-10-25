// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "PlayerBase.generated.h"


class StaticMeshComponent;

UCLASS()
class SOLOPROJECTTGP_API APlayerBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Ball;
	/*UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Hamster;*/

	UPROPERTY(VisibleAnywhere)
	FVector CurrentVelocity;
	UPROPERTY(EditAnywhere)
	FVector StartPosition;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float moveSpeed = 20000;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float jumpSpeed = 50000;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float rotationSpeed = 100;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	float rotationVelocity;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveForward(float value);
	virtual void MoveRight(float value);
	virtual void LookRight(float value);
	virtual void Jump(float value);
};
