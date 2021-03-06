
#include "svc_fixangle.h"
#include "base/bitfile.h"
#include "base/jsonfile.h"
#include "demofile/demojson.h"
#include <iomanip>

namespace NetHandlers
{
    bool SVC_FixAngle_BitRead_Internal(BitRead& bitbuf, SourceGameContext& context, NetMsg::SVC_FixAngle* data)
    {
        data->relative = bitbuf.ReadOneBit() != 0;
        data->angle.x = bitbuf.ReadBitAngle(16);
        data->angle.y = bitbuf.ReadBitAngle(16);
        data->angle.z = bitbuf.ReadBitAngle(16);
        return !bitbuf.IsOverflowed();
    }

    bool SVC_FixAngle_BitWrite_Internal(BitWrite& bitbuf, const SourceGameContext& context, NetMsg::SVC_FixAngle* data)
    {
        bitbuf.WriteOneBit(data->relative);
        bitbuf.WriteBitAngle(data->angle.x, 16);
        bitbuf.WriteBitAngle(data->angle.y, 16);
        bitbuf.WriteBitAngle(data->angle.z, 16);
        return !bitbuf.IsOverflowed();
    }

    bool SVC_FixAngle_JsonRead_Internal(JsonRead& jsonbuf, SourceGameContext& context, NetMsg::SVC_FixAngle* data)
    {
        base::JsonReaderObject reader = jsonbuf.ParseObject();
        assert(!reader.HasReadError());
        data->relative = reader.ReadBool("relative");
        DemoJsonReader::ReadAngle(reader, "angle", data->angle);
        return !reader.HasReadError();
    }

    bool SVC_FixAngle_JsonWrite_Internal(JsonWrite& jsonbuf, const SourceGameContext& context, NetMsg::SVC_FixAngle* data)
    {
        jsonbuf.Reset();
        jsonbuf.StartObject();
        jsonbuf.WriteBool("relative", data->relative);
        DemoJsonWriter::WriteAngle(jsonbuf, "angle", data->angle);
        jsonbuf.EndObject();
        return jsonbuf.IsComplete();
    }

    void SVC_FixAngle_ToString_Internal(std::ostringstream& out, NetMsg::SVC_FixAngle* data)
    {
        const std::streamsize oldPrecision = out.precision();
        out << "svc_FixAngle: " << (data->relative ? "relative" : "absolute")
            << std::setprecision(1) << std::fixed
            << " " << data->angle.x
            << " " << data->angle.y
            << " " << data->angle.z
            << std::setprecision(oldPrecision);
        out.unsetf(std::ios_base::floatfield);
    }
}
