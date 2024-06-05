#if PROTOCOL_VERSION > 765 /* > 1.20.4 */
#pragma once

#include "protocolCraft/BaseMessage.hpp"

namespace ProtocolCraft
{
    class ClientboundProjectilePowerPacket : public BaseMessage<ClientboundProjectilePowerPacket>
    {
    public:
#if   PROTOCOL_VERSION == 766 /* 1.20.5/6 */
        static constexpr int packet_id = 0x79;
#else
#error "Protocol version not implemented"
#endif

        static constexpr std::string_view packet_name = "Projectile Power";

        DECLARE_FIELDS_TYPES(VarInt, double, double, double);
        DECLARE_FIELDS_NAMES(Id_,    XPower, YPower, ZPower);
        DECLARE_READ_WRITE_SERIALIZE;

        GETTER_SETTER(Id_);
        GETTER_SETTER(XPower);
        GETTER_SETTER(YPower);
        GETTER_SETTER(ZPower);
    };
} //ProtocolCraft
#endif
