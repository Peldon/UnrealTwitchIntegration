// Copyright 2017 Gerald Schenke

#include "TwitchIntegrationGameModeBase.h"

void ATwitchIntegrationGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	TwitchConnection = NewObject<UTwitchConnection>();
	UWorld* world = GetWorld();

	TwitchConnection->Connect(world, "[twitch user name]", "[your oauth (with oauth:)]", "[the channel to join (without #)]");
}
