#include <uv.h>

#include "shared.h"

namespace librg
{
    namespace core
    {
        void client(int argc, char * argv[]);
        void client_tick(uv_loop_t* loop = nullptr);
    }
}
