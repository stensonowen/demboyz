
#include "dem_synctick.h"

namespace DemHandlers
{
    bool Dem_SyncTick_FileRead_Internal(FileRead& demofile, DemMsg::Dem_SyncTick* data)
    {
        return true;
    }

    bool Dem_SyncTick_FileWrite_Internal(FileWrite& demofile, DemMsg::Dem_SyncTick* data)
    {
        return true;
    }

    bool Dem_SyncTick_JsonRead_Internal(JsonRead& jsonbuf, DemMsg::Dem_SyncTick* data)
    {
        return true;
    }

    bool Dem_SyncTick_JsonWrite_Internal(JsonWrite& jsonbuf, DemMsg::Dem_SyncTick* data)
    {
        return true;
    }
}
