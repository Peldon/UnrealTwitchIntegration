// Copyright 2017 Gerald Schenke

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Networking.h"
#include "TimerManager.h"

#include "TwitchConnection.generated.h"


/**
 * 
 */
UCLASS()
class TWITCHINTEGRATION_API UTwitchConnection : public UObject
{
	GENERATED_BODY()
	
public:
	void Connect(UWorld* world, FString user, FString oauth, FString channel);

private:
	FSocket* ListenerSocket;
	FSocket* ConnectionSocket;
	FTimerHandle timerHandle;

	void SocketListener();

	void SendLogin(FString user, FString oauth, FString channel);

	bool SendString(FString msg);

	void ParseMessage(FString msg);

	void ReceivedChatMessage(FString UserName, FString message);

};
