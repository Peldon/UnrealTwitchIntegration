// Copyright 2017 Gerald Schenke

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TwitchConnection.h"

#include "TwitchIntegrationGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TWITCHINTEGRATION_API ATwitchIntegrationGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

private:
	UTwitchConnection* TwitchConnection = nullptr;
	
};
