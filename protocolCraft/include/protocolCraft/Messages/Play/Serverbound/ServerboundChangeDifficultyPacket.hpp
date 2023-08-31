#pragma once

#if PROTOCOL_VERSION > 463 /* > 1.13.2 */
#include "protocolCraft/BaseMessage.hpp"

namespace ProtocolCraft
{
    class ServerboundChangeDifficultyPacket : public BaseMessage<ServerboundChangeDifficultyPacket>
    {
    public:
#if   PROTOCOL_VERSION == 477 /* 1.14 */ || PROTOCOL_VERSION == 480 /* 1.14.1 */ ||  \
      PROTOCOL_VERSION == 485 /* 1.14.2 */ || PROTOCOL_VERSION == 490 /* 1.14.3 */ ||  \
      PROTOCOL_VERSION == 498 /* 1.14.4 */ || PROTOCOL_VERSION == 573 /* 1.15 */ ||  \
      PROTOCOL_VERSION == 575 /* 1.15.1 */ || PROTOCOL_VERSION == 578 /* 1.15.2 */ ||  \
      PROTOCOL_VERSION == 735 /* 1.16 */ || PROTOCOL_VERSION == 736 /* 1.16.1 */ ||  \
      PROTOCOL_VERSION == 751 /* 1.16.2 */ || PROTOCOL_VERSION == 753 /* 1.16.3 */ ||  \
      PROTOCOL_VERSION == 754 /* 1.16.4/5 */ || PROTOCOL_VERSION == 755 /* 1.17 */ ||  \
      PROTOCOL_VERSION == 756 /* 1.17.1 */ || PROTOCOL_VERSION == 757 /* 1.18/.1 */ ||  \
      PROTOCOL_VERSION == 758 /* 1.18.2 */ || PROTOCOL_VERSION == 759 /* 1.19 */ ||  \
      PROTOCOL_VERSION == 760 /* 1.19.1/2 */ || PROTOCOL_VERSION == 761 /* 1.19.3 */ ||  \
      PROTOCOL_VERSION == 762 /* 1.19.4 */ || PROTOCOL_VERSION == 763 /* 1.20/.1 */
        static constexpr int packet_id = 0x02;
#else
#error "Protocol version not implemented"
#endif

        static constexpr std::string_view packet_name = "Change Difficulty";

        virtual ~ServerboundChangeDifficultyPacket() override
        {

        }

        void SetDifficulty(const char difficulty_)
        {
            difficulty = difficulty_;
        }


        char GetDifficulty() const
        {
            return difficulty;
        }


    protected:
        virtual void ReadImpl(ReadIterator& iter, size_t& length) override
        {
            difficulty = ReadData<char>(iter, length);
        }

        virtual void WriteImpl(WriteContainer& container) const override
        {
            WriteData<char>(difficulty, container);
        }

        virtual Json::Value SerializeImpl() const override
        {
            Json::Value output;

            output["difficulty"] = difficulty;

            return output;
        }

    private:
        char difficulty = 0;

    };
} //ProtocolCraft
#endif
