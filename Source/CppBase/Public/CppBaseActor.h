// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	FString PlayerName;

	UPROPERTY(EditAnywhere)
	int EnemyNum;

	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	float Amplitude = 70.0;

	UPROPERTY(EditAnywhere)
	float Frequency = 4.0;

	UPROPERTY(EditInstanceOnly)
	FVector InitialLocation = FVector(0.0f, 0.0f, 0.0f);

	float RunningTime = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	void ShowActorInformation();

	UFUNCTION(BlueprintCallable)
	void SinMovement();
};
