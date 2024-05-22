#pragma once

#include "protocolCraft/Types/Particles/ParticleOptions.hpp"

namespace ProtocolCraft
{
    class EmptyParticleOptions : public ParticleOptions
    {
        DECLARE_EMPTY;
        DECLARE_READ_WRITE_SERIALIZE;
    };
}