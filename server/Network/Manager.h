#ifndef _mo_network_manager
#define _mo_network_manager

#include <map>
#include <RakPeerInterface.h>
#include "Client.h"
#include "Handler.h"

namespace MOServer {
namespace Network  {

// forward declaration
// class Handler;

class Manager
{
public:
    Manager();
    ~Manager();
    void Init();
    void Tick();

    void Update();
    void Receive();

    RakNet::RakPeerInterface* GetPeer() { return mPeer; }

private:
    RakNet::RakPeerInterface* mPeer;
    RakNet::SocketDescriptor mSocketDescriptor;
    std::map<RakNet::RakNetGUID, Client*> mClients;
    Network::Handler* mHandler;
};


} // Netwrok
} // MOServer

#endif // _mo_network_manager
