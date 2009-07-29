/*
 *	server/zone/objects/player/PlayerCreature.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLAYERCREATURE_H_
#define PLAYERCREATURE_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

namespace server {
namespace zone {

class ZoneClientSession;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerObject;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class Container;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PlayerDisconnectEvent;

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PlayerRecoveryEvent;

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;

namespace server {
namespace chat {
namespace room {

class ChatRoom;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "engine/util/QuadTreeEntry.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature : public CreatureObject {
public:
	PlayerCreature(LuaObject* templateData);

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	void clearQueueAction(unsigned int actioncntr, float timer = 0, unsigned int tab1 = 0, unsigned int tab2 = 0);

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose = true);

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	ZoneClientSession* getClient();

	byte getRaceID();

	String getFirstName();

	void setClient(ZoneClientSession* cli);

	void setBiography(const UnicodeString& bio);

	void setRaceID(byte id);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

protected:
	PlayerCreature(DummyConstructorParameter* param);

	virtual ~PlayerCreature();

	String _return_getFirstName;

	friend class PlayerCreatureHelper;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreatureImplementation : public CreatureObjectImplementation {
protected:
	ManagedReference<ZoneClientSession* > owner;

	int onlineStatus;

	Time* logoutTimeStamp;

	unsigned long long accountID;

	unsigned long long characterID;

	unsigned long long baseID;

	String raceFile;

	byte raceID;

	String startingLocation;

	String startingProfession;

	UnicodeString biography;

	byte lotsRemaining;

	PlayerDisconnectEvent* disconnectEvent;

	PlayerRecoveryEvent* recoveryEvent;

	Time* nextAction;

	Time* nextTip;

	SortedVector<ChatRoom* >* chatRooms;

	byte incapacitationCounter;

	Time* firstIncapacitationTime;

	int pvpRating;

	int factionStatus;

public:
	static const int ONLINE = 1;

	static const int OFFLINE = 2;

	static const int LINKDEAD = 3;

	static const int LOGGINGIN = 4;

	static const int LOGGINGOUT = 5;

	static const int LOADING = 6;

	PlayerCreatureImplementation(LuaObject* templateData);

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	void clearQueueAction(unsigned int actioncntr, float timer = 0, unsigned int tab1 = 0, unsigned int tab2 = 0);

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose = true);

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	ZoneClientSession* getClient();

	byte getRaceID();

	String getFirstName();

	void setClient(ZoneClientSession* cli);

	void setBiography(const UnicodeString& bio);

	void setRaceID(byte id);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	PlayerCreature* _this;

	operator const PlayerCreature*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~PlayerCreatureImplementation();

	void _setStub(DistributedObjectStub* stub);

	void _serializationHelperMethod();

	friend class PlayerCreature;
};

class PlayerCreatureAdapter : public CreatureObjectAdapter {
public:
	PlayerCreatureAdapter(PlayerCreatureImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	void clearQueueAction(unsigned int actioncntr, float timer, unsigned int tab1, unsigned int tab2);

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose);

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	ZoneClientSession* getClient();

	byte getRaceID();

	String getFirstName();

	void setClient(ZoneClientSession* cli);

	void setRaceID(byte id);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

};

class PlayerCreatureHelper : public DistributedObjectClassHelper, public Singleton<PlayerCreatureHelper> {
	static PlayerCreatureHelper* staticInitializer;

public:
	PlayerCreatureHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlayerCreatureHelper>;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#endif /*PLAYERCREATURE_H_*/
