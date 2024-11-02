#if PROTOCOL_VERSION > 767 /* > 1.21.1 */
#include "botcraft/Game/Entities/entities/monster/creaking/CreakingEntity.hpp"

#include <mutex>

namespace Botcraft
{
    const std::array<std::string, CreakingEntity::metadata_count> CreakingEntity::metadata_names{ {
        "can_move",
        "is_active",
    } };

    CreakingEntity::CreakingEntity()
    {
        // Initialize all metadata with default values
        SetCanMove(true);
        SetIsActive(false);

        // Initialize all attributes with default values
        attributes.insert({ EntityAttribute::Type::MaxHealth, EntityAttribute(EntityAttribute::Type::MaxHealth, 1.0) });
        attributes.insert({ EntityAttribute::Type::MovementSpeed, EntityAttribute(EntityAttribute::Type::MovementSpeed, 0.3) });
        attributes.insert({ EntityAttribute::Type::AttackDamage, EntityAttribute(EntityAttribute::Type::AttackDamage, 2.0) });
        attributes.insert({ EntityAttribute::Type::FollowRange, EntityAttribute(EntityAttribute::Type::FollowRange, 32.0) });
        attributes.insert({ EntityAttribute::Type::StepHeight, EntityAttribute(EntityAttribute::Type::StepHeight, 1.0) });
    }

    CreakingEntity::~CreakingEntity()
    {

    }


    std::string CreakingEntity::GetName() const
    {
        return "creaking";
    }

    EntityType CreakingEntity::GetType() const
    {
        return EntityType::Creaking;
    }


    std::string CreakingEntity::GetClassName()
    {
        return "creaking";
    }

    EntityType CreakingEntity::GetClassType()
    {
        return EntityType::Creaking;
    }


    ProtocolCraft::Json::Value CreakingEntity::Serialize() const
    {
        ProtocolCraft::Json::Value output = MonsterEntity::Serialize();

        output["metadata"]["can_move"] = GetCanMove();
        output["metadata"]["is_active"] = GetIsActive();


        return output;
    }


    void CreakingEntity::SetMetadataValue(const int index, const std::any& value)
    {
        if (index < hierarchy_metadata_count)
        {
            MonsterEntity::SetMetadataValue(index, value);
        }
        else if (index - hierarchy_metadata_count < metadata_count)
        {
            metadata[metadata_names[index - hierarchy_metadata_count]] = value;
        }
    }

    bool CreakingEntity::GetCanMove() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return std::any_cast<bool>(metadata.at("can_move"));
    }

    bool CreakingEntity::GetIsActive() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return std::any_cast<bool>(metadata.at("is_active"));
    }


    void CreakingEntity::SetCanMove(const bool can_move)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        metadata["can_move"] = can_move;
    }

    void CreakingEntity::SetIsActive(const bool is_active)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        metadata["is_active"] = is_active;
    }




    double CreakingEntity::GetWidthImpl() const
    {
        return 0.9;
    }

    double CreakingEntity::GetHeightImpl() const
    {
        return 2.7;
    }

}
#endif
