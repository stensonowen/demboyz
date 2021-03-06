
#include "net_stringcmd.h"
#include "base/bitfile.h"
#include "base/jsonfile.h"

namespace NetHandlers
{
    bool Net_StringCmd_BitRead_Internal(BitRead& bitbuf, SourceGameContext& context, NetMsg::Net_StringCmd* data)
    {
        bitbuf.ReadString(data->command, sizeof(data->command));
        return !bitbuf.IsOverflowed();
    }

    bool Net_StringCmd_BitWrite_Internal(BitWrite& bitbuf, const SourceGameContext& context, NetMsg::Net_StringCmd* data)
    {
        bitbuf.WriteString(data->command);
        return !bitbuf.IsOverflowed();
    }

    bool Net_StringCmd_JsonRead_Internal(JsonRead& jsonbuf, SourceGameContext& context, NetMsg::Net_StringCmd* data)
    {
        base::JsonReaderObject reader = jsonbuf.ParseObject();
        assert(!reader.HasReadError());
        reader.ReadString("command", data->command, sizeof(data->command));
        return !reader.HasReadError();
    }

    bool Net_StringCmd_JsonWrite_Internal(JsonWrite& jsonbuf, const SourceGameContext& context, NetMsg::Net_StringCmd* data)
    {
        jsonbuf.Reset();
        jsonbuf.StartObject();
        jsonbuf.WriteString("command", data->command);
        jsonbuf.EndObject();
        return jsonbuf.IsComplete();
    }

    void Net_StringCmd_ToString_Internal(std::ostringstream& out, NetMsg::Net_StringCmd* data)
    {
        out << "net_StringCmd: \"" << data->command << '"';
    }
}
