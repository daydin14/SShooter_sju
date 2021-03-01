// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SShooterGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SSHOOTER_API AInfiniteTerrainGameMode : public ASShooterGameMode
{
	GENERATED_BODY()
	
public: 
	AInfiniteTerrainGameMode();


	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulatedBoundsVolumePool(); 

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool; 


private:
	void AddToPool(class AVolume *VolumeToAdd);
	
};
