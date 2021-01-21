// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialGameInstance.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

UTutorialGameInstance::UTutorialGameInstance() {

}

void UTutorialGameInstance::Init()
{
	Super::Init();

	// Register the on viewport resize event to our function and store the delegate handle
	mViewportHandle = FViewport::ViewportResizedEvent.AddUObject(this, &UTutorialGameInstance::OnViewportResize);
}

void UTutorialGameInstance::Shutdown()
{
	// Unregister the viewport resize event.
	FViewport::ViewportResizedEvent.Remove(mViewportHandle);

	Super::Shutdown();
}

void UTutorialGameInstance::OnViewportResize(FViewport* Viewport, uint32 ID)
{
	// Broadcast to any bound function
	mOnWindowResizedEvent.Broadcast();
}