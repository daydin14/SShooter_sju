// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGameMode.h"
#include "GameFramework/Volume.h"
#include "Navmesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"


/**
*
*/
AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
		
}

void AInfiniteTerrainGameMode::PopulatedBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<AVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
		
	}
}


void AInfiniteTerrainGameMode::AddToPool(class AVolume *VolumeToAdd)
{
	NavMeshBoundsVolumePool->Add(VolumeToAdd); 
}

