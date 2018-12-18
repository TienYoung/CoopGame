// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"

void ASProjectileWeapon::Fire()
{
	AActor* MyOwner = GetOwner();
	if (MyOwner&&ProjectileClass) {
		// Trace the world, from pawn eyes to crosshair location
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);

		//Set Spawn Collision Handling Override
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		// spawn the projectile at the muzzle
		GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzleLocation, EyeRotation, SpawnParams);
	}
}
