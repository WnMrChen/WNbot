#pragma once

#include "botcraft/Game/Entities/entities/monster/AbstractIllagerEntity.hpp"

namespace Botcraft
{
    class VindicatorEntity : public AbstractIllagerEntity
    {
    protected:
        static constexpr int metadata_count = 0;
        static constexpr int hierarchy_metadata_count = AbstractIllagerEntity::metadata_count + AbstractIllagerEntity::hierarchy_metadata_count;

    public:
        VindicatorEntity();
        virtual ~VindicatorEntity();

        // Object related stuff
        virtual std::string GetName() const override;
        virtual EntityType GetType() const override;

        // Static stuff, for easier comparison
        static std::string GetClassName();
        static EntityType GetClassType();

    protected:
        virtual double GetWidthImpl() const override;
        virtual double GetHeightImpl() const override;

    };
}
