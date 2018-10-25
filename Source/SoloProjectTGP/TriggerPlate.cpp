// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerPlate.h"
#include "Components/StaticMeshComponent.h"



// Sets default values
ATriggerPlate::ATriggerPlate()
{

	Plate = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	Plate->SetSimulatePhysics(true);
	RootComponent = Plate;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATriggerPlate::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATriggerPlate::OnPress()
{
	FVector Location = GetActorLocation() + FVector(0, 0, -5);
	SetActorLocation(Location);
}

// Called every frame
void ATriggerPlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATriggerPlate::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

