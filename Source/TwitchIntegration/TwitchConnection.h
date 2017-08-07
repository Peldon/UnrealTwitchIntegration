// Copyright 2017 Gerald Schenke

#pragma once

#include "TwitchConnection.generated.h"

class FSocket;
struct FTimerHandle;

/**
 * Example class to connect to the twitch irc server, join a channel, receive and send messages.
 * 
 * Add "Sockets" and "Networking" to [projectname].Build.cs
 * and call for example from your GameMode:
 * TwitchConnection = NewObject<UTwitchConnection>();
 * TwitchConnection->Connect(GetWorld(), "[twitch user name]", "[your oauth (with oauth:)]", "[the channel to join (without #)]");
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
