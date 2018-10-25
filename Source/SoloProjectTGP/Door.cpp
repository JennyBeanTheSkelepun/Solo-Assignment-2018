// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"


// Sets default values
ADoor::ADoor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	doorComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	doorComponent->SetSimulatePhysics(true);
	RootComponent = doorComponent;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADoor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

