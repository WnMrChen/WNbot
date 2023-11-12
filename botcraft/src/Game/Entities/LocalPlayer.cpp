#include "botcraft/Game/Entities/LocalPlayer.hpp"

#include <mutex>

#define PI 3.14159265359

namespace Botcraft
{
    LocalPlayer::LocalPlayer()
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);

        position = Vector3<double>(0.0, 1000.0, 0.0);
        frontVector = Vector3<double>(0.0, 0.0, 1.0);
        rightVector = Vector3<double>(1.0, 0.0, 0.0);

        flying_speed = 1.0f;
        walking_speed = 1.0f;
        is_flying = false;
        is_running = false;
        is_climbing = false;

        is_invulnerable = false;
        health = 0.0f;
        food = 20;
        food_saturation = 5.0f;

        has_moved = true;
    }

    LocalPlayer::~LocalPlayer()
    {

    }


    Vector3<double> LocalPlayer::GetFrontVector() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return frontVector;
    }

    Vector3<double> LocalPlayer::GetXZVector() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return xzVector;
    }

    Vector3<double> LocalPlayer::GetRightVector() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return rightVector;
    }

    Vector3<double> LocalPlayer::GetPlayerInputs() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return player_inputs;
    }

    double LocalPlayer::GetPlayerInputsX() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return player_inputs.x;
    }

    double LocalPlayer::GetPlayerInputsY() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return player_inputs.y;
    }

    double LocalPlayer::GetPlayerInputsZ() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return player_inputs.z;
    }


    float LocalPlayer::GetFlyingSpeed() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return flying_speed;
    }

    float LocalPlayer::GetWalkingSpeed() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return walking_speed;
    }

    bool LocalPlayer::GetIsFlying() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return is_flying;
    }

    bool LocalPlayer::GetIsRunning() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return is_running;
    }

    bool LocalPlayer::GetIsClimbing() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return is_climbing;
    }

    bool LocalPlayer::GetIsInvulnerable() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return is_invulnerable;
    }

    float LocalPlayer::GetHealth() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return health;
    }

    int LocalPlayer::GetFood() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return food;
    }

    float LocalPlayer::GetFoodSaturation() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return food_saturation;
    }

    bool LocalPlayer::GetHasMoved() const
    {
        std::shared_lock<std::shared_mutex> lock(entity_mutex);
        return has_moved;
    }


    void LocalPlayer::SetFlyingSpeed(const float flying_speed_)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        flying_speed = flying_speed_;
    }

    void LocalPlayer::SetWalkingSpeed(const float walking_speed_)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        walking_speed = walking_speed_;
    }

    void LocalPlayer::SetIsFlying(const bool b)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        is_flying = b;
    }

    void LocalPlayer::SetIsRunning(const bool b)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        is_running = b;
    }

    void LocalPlayer::SetIsClimbing(const bool b)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        is_climbing = b;
    }

    void LocalPlayer::SetIsInvulnerable(const bool b)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        is_invulnerable = b;
    }

    void LocalPlayer::SetHealth(const float health_)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        health = health_;
    }

    void LocalPlayer::SetFood(const int food_)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        food = food_;
    }

    void LocalPlayer::SetFoodSaturation(const float food_saturation_)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        food_saturation = food_saturation_;
    }

    void LocalPlayer::SetHasMoved(const bool has_moved_)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        has_moved = has_moved_;
    }


    void LocalPlayer::SetPosition(const Vector3<double>& pos)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        has_moved |= position != pos;
        position = pos;
    }

    void LocalPlayer::SetX(const double x)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        has_moved |= position.x != x;
        position.x = x;
    }

    void LocalPlayer::SetY(const double y)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        has_moved |= position.y != y;
        position.y = y;
    }

    void LocalPlayer::SetZ(const double z)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        has_moved |= position.z != z;
        position.z = z;
    }

    void LocalPlayer::SetYaw(const float yaw_)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        if (yaw != yaw_)
        {
            has_moved = true;
            yaw = yaw_;
            UpdateVectors();
        }
    }

    void LocalPlayer::SetPitch(const float pitch_)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        if (pitch != pitch_)
        {
            has_moved = true;
            pitch = pitch_;
            UpdateVectors();
        }
    }

    void LocalPlayer::SetPlayerInputs(const Vector3<double>& p)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs = p;
    }

    void LocalPlayer::SetPlayerInputsX(const double x)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.x = x;
    }

    void LocalPlayer::SetPlayerInputsY(const double y)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.y = y;
    }

    void LocalPlayer::SetPlayerInputsZ(const double z)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.z = z;
    }

    void LocalPlayer::SetPlayerInputsTargetX(const double x)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.x = x - position.x - speed.x;
    }

    void LocalPlayer::SetPlayerInputsTargetY(const double y)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.y = y - position.y - speed.y;
    }

    void LocalPlayer::SetPlayerInputsTargetZ(const double z)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.z = z - position.z - speed.z;
    }

    void LocalPlayer::AddPlayerInputs(const Vector3<double>& p)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs += p;
    }

    void LocalPlayer::AddPlayerInputsX(const double x)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.x += x;
    }

    void LocalPlayer::AddPlayerInputsY(const double y)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.y += y;
    }

    void LocalPlayer::AddPlayerInputsZ(const double z)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        player_inputs.z += z;
    }

    bool LocalPlayer::IsLocalPlayer() const
    {
        return true;
    }

    bool LocalPlayer::IsRemotePlayer() const
    {
        return false;
    }

    void LocalPlayer::LookAt(const Vector3<double>& pos, const bool set_pitch)
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        Vector3<double> direction = (pos - position);
        // We want to set the orientation from the eyes, not the feet
        direction.y -= GetEyeHeightImpl();
        direction.Normalize();
        const float new_pitch = static_cast<float>(-std::asin(direction.y) * 180.0 / PI);
        float new_yaw = static_cast<float>(-std::atan2(direction.x, direction.z) * 180.0 / PI);
        if (new_yaw < 0)
        {
            new_yaw += 360.0f;
        }
        if (new_yaw != yaw ||
            (set_pitch && new_pitch != pitch))
        {
            if (set_pitch)
            {
                pitch = new_pitch;
            }
            yaw = new_yaw;
            has_moved = true;
            UpdateVectors();
        }
    }

    void LocalPlayer::Jump()
    {
        std::scoped_lock<std::shared_mutex> lock(entity_mutex);
        if (!on_ground)
        {
            return;
        }
        speed.y = 0.42;
    }

    void LocalPlayer::UpdateVectors()
    {
        const double rad_yaw = yaw * PI / 180.0;
        const double rad_pitch = pitch * PI / 180.0;
        frontVector = Vector3<double>(-sin(rad_yaw) * cos(rad_pitch), -sin(rad_pitch), cos(rad_yaw) * cos(rad_pitch));

        frontVector.Normalize();

        xzVector = frontVector;
        xzVector.y = 0.0;
        xzVector.Normalize();

        //Right = crossproduct(front, (0, 1.0, 0))
        const double norm = sqrt(frontVector.x * frontVector.x + frontVector.z * frontVector.z);
        rightVector = Vector3<double>(-frontVector.z / norm, 0.0, frontVector.x / norm);
    }
} //Botcraft
