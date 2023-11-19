// YourActor.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YourActor.generated.h"

UCLASS()
class YOURPROJECT_API AYourActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AYourActor();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Function to make the actor fly up
    UFUNCTION(BlueprintCallable, Category = "Flight")
    void FlyUp(float DeltaTime);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
};

// YourActor.cpp
#include "YourActor.h"

// Sets default values
AYourActor::AYourActor()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AYourActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AYourActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Uncomment the line below if you want continuous flying (remove the comment if you want to trigger it using an event)
    // FlyUp(DeltaTime);
}

void AYourActor::FlyUp(float DeltaTime)
{
    // Adjust the Z-axis value based on the desired flying speed
    FVector NewLocation = GetActorLocation() + FVector(0.0f, 0.0f, 100.0f * DeltaTime);

    // Set the new location
    SetActorLocation(NewLocation);
}
