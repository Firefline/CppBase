// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/Engine.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	ShowActorInformation();
	SetActorLocation(InitialLocation);
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
}

void ACppBaseActor::ShowActorInformation()
{
	UE_LOG(LogTemp, Display, TEXT("PlayerName: %s"), *PlayerName);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, PlayerName, true, FVector2D(2.0f, 2.0f));

	UE_LOG(LogTemp, Display, TEXT("CppBase is here"));
	UE_LOG(LogTemp, Warning, TEXT("CppBase class made a mistake"));
	UE_LOG(LogTemp, Error, TEXT("CppBase error"));

	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %f"), IsAlive);
}

void ACppBaseActor::SinMovement()
{
	FVector NewLocation = GetActorLocation();

	NewLocation.Z = Amplitude * FMath::Sin(Frequency * RunningTime);

	SetActorLocation(FVector(NewLocation));
}