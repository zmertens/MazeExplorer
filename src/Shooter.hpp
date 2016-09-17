#ifndef SHOOTER_HPP
#define SHOOTER_HPP

#include <unordered_map>

#include <glm/glm.hpp>

#include "IGame.hpp"

#include "engine/SdlWindow.hpp"
#include "engine/ResourceManager.hpp"
#include "engine/Logger.hpp"
#include "engine/Camera.hpp"
#include "engine/RenderText.hpp"
#include "engine/graphics/Entity.hpp"
#include "engine/graphics/Skybox.hpp"
#include "engine/graphics/Light.hpp"
#include "engine/graphics/PostProcessorImpl.hpp"
#include "engine/graphics/Sprite.hpp"
#include "engine/audio/SdlMixer.hpp"

#include "Level.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

class Shooter final : public IGame
{
public:
    Shooter();
    virtual void start() override;

protected:
    virtual void loop() override;
    virtual void handleEvents() override;
    virtual void update(float dt, double timeSinceInit) override;
    virtual void render() override;
    virtual void finish() override;

private:
    static const float sTimePerFrame;
    static const unsigned int sWindowWidth;
    static const unsigned int sWindowHeight;
    static const std::string sTitle;
    static std::unordered_map<uint8_t, bool> sKeyInputs;

    SdlWindow mSdlWindow;
    ResourceManager mResources;
    Logger mLogger;

    bool mAppIsRunning;
    unsigned int mFrameCounter;
    float mTimeSinceLastUpdate;
    float mAccumulator;

    Entity mCube;
    Camera mCamera;
    Level mLevel;
    Player mPlayer;
    Skybox mSkybox;
    PostProcessorImpl mPostProcessor;
    Light mLight;
    Sprite mTestSprite;
    RenderText mRenderText;
    std::vector<Enemy::Ptr> mEnemies;
    std::vector<Sprite::Ptr> mPowerUps;

    // exits
    // power ups

    SdlMixer mSdlMixer;

private:
    void init();
    void initResources();
    void initPositions();
    void calcFrameRate(const float dt);
    void sdlEvents(SDL_Event& event, float& mouseWheelDy);
};

#endif // SHOOTER_HPP
