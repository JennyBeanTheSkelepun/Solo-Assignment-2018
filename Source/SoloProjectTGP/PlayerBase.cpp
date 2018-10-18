// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Glass Ball"));
	Ball->SetSimulatePhysics(true);
	RootComponent = Ball;

}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		//FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		//SetActorLocation(NewLocation);
		Ball->AddForce(CurrentVelocity);
	}
	if (!rotationVelocity != 0)
	{
		FRotator NewRotation{ 0,rotationVelocity * DeltaTime, 0 };
		RootComponent->AddWorldRotation(NewRotation);
	}
}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerBase::MoveRight);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerBase::LookRight);
	PlayerInputComponent->BindAxis("Jump", this, &APlayerBase::Jump);
}

void APlayerBase::MoveForward(float value)
{
	CurrentVelocity.X = value * moveSpeed;
}

void APlayerBase::MoveRight(float value)
{
	CurrentVelocity.Y = value * moveSpeed;
}

void APlayerBase::LookRight(float value)
{
	rotationVelocity = value * rotationSpeed;
}

void APlayerBase::Jump(float value)
{
	CurrentVelocity.Z = value * jumpSpeed;
}
