// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TutorialGameInstance.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnWindowResizedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWindowResizedMultiDelegate);

/**
 * 
 */
UCLASS()
class UNREALTUTORIAL_API UTutorialGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UTutorialGameInstance();

	void Init() override;

	void Shutdown() override;

	// Will be used to register within the ViewportResizeEvent delegate. In other words,
	// this function will be called whenever the game window is resized
	
	virtual void OnViewportResize(class FViewport* Viewport, uint32 ID);

	// Adds an event listener that will be called whenever the game window is resized
	UFUNCTION(BlueprintCallable, Category = "Event Binding")
	void ListenWindowResized(FOnWindowResizedDelegate WindowResizedDelegate) { mOnWindowResizedEvent.Add(WindowResizedDelegate); }

private:

	// Holds information necessary to un-register the OnViewportResize function from the ViewportResizedEvent delegate.
	FDelegateHandle mViewportHandle;

	// Used to relay the resized event to any listener
	UPROPERTY()
	FOnWindowResizedMultiDelegate mOnWindowResizedEvent;
};
