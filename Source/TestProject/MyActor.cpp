// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder <UStaticMesh> AA(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (AA.Succeeded())
	{
		Mesh->SetStaticMesh(AA.Object);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	

	// 춘잣
	// 카테고리, 로깅 수준, 형식, 인자
	UE_LOG(LogTemp, Warning, TEXT("Begin play %d"), 3);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 카테고리, 로깅 수준, 형식, 인자
	///UE_LOG(LogTemp, Error, TEXT("TICK %d"), DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));

}

