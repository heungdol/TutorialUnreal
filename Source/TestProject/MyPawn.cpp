// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject <UFloatingPawnMovement>(TEXT("MOVEMENT"));

	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder <UStaticMesh> AA(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (AA.Succeeded())
	{
		Mesh->SetStaticMesh(AA.Object);
	}
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);
}

void AMyPawn::UpDown(float axis)
{
	if (axis == 0.0f)
		return;

	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), axis);
	AddMovementInput(GetActorForwardVector(), axis);
}

void AMyPawn::LeftRight(float axis)
{
	if (axis == 0.0f)
		return;

	//UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), axis);
	AddMovementInput(GetActorRightVector(), axis);
}