// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/LightComponent.h"
#include "TriggerPlate.generated.h"

UCLASS()
class SOLOPROJECTTGP_API ATriggerPlate : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATriggerPlate();

protected:

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Plate;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnPress();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
