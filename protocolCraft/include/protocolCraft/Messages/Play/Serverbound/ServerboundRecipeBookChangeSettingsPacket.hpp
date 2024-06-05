#pragma once

#if PROTOCOL_VERSION > 736 /* > 1.16.1 */
#include "protocolCraft/BaseMessage.hpp"

namespace ProtocolCraft
{
    class ServerboundRecipeBookChangeSettingsPacket : public BaseMessage<ServerboundRecipeBookChangeSettingsPacket>
    {
    public:
#if   PROTOCOL_VERSION == 751 /* 1.16.2 */ || PROTOCOL_VERSION == 753 /* 1.16.3 */ ||  \
      PROTOCOL_VERSION == 754 /* 1.16.4/5 */ || PROTOCOL_VERSION == 755 /* 1.17 */ ||  \
      PROTOCOL_VERSION == 756 /* 1.17.1 */ || PROTOCOL_VERSION == 757 /* 1.18/.1 */ ||  \
      PROTOCOL_VERSION == 758 /* 1.18.2 */
        static constexpr int packet_id = 0x1E;
#elif PROTOCOL_VERSION == 759 /* 1.19 */
        static constexpr int packet_id = 0x20;
#elif PROTOCOL_VERSION == 760 /* 1.19.1/2 */ || PROTOCOL_VERSION == 761 /* 1.19.3 */ ||  \
      PROTOCOL_VERSION == 762 /* 1.19.4 */ || PROTOCOL_VERSION == 763 /* 1.20/.1 */
        static constexpr int packet_id = 0x21;
#elif PROTOCOL_VERSION == 764 /* 1.20.2 */
        static constexpr int packet_id = 0x24;
#elif PROTOCOL_VERSION == 765 /* 1.20.3/4 */
        static constexpr int packet_id = 0x25;
#elif PROTOCOL_VERSION == 766 /* 1.20.5/6 */
        static constexpr int packet_id = 0x28;
#else
#error "Protocol version not implemented"
#endif

        static constexpr std::string_view packet_name = "Recipe Book Change Settings";

        DECLARE_FIELDS_TYPES(VarInt,   bool,   bool);
        DECLARE_FIELDS_NAMES(BookType, IsOpen, IsFiltering);
        DECLARE_READ_WRITE_SERIALIZE;

        GETTER_SETTER(BookType);
        GETTER_SETTER(IsOpen);
        GETTER_SETTER(IsFiltering);
    };
} //ProtocolCraft
#endif
