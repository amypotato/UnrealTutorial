#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ColPlayerController.generated.h"

UCLASS()
class UCOLUMNSTUTORIAL_API AColPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AColPlayerController(const FObjectInitializer& ObjectInitializer);
};