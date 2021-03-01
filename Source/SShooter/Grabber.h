// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "DrawDebugHelpers.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SSHOOTER_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



private:
	// How far player can reach in CM
	float Reach = 250.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr; 

	// Ray-cast and grab what is in reach
	void Grab();

	// Called when grab is released 
	void Release(); 

	// Find attached physics
	void FindPhysicsHandleComponent();

	// Setup attached input component 
	void SetupInputComponent(); 

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns current start of reach line
	FVector GetReachLineStart();
	
	// Returns current end of reach line 
	FVector GetReachLineEnd();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
