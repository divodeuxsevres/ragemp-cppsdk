#include <iostream>
#include <Windows.h>

#include "rage_sdk.hpp"
#include "rage_log.hpp"

#include "examples/ExampleEntityEventHandler.hpp"
#include "examples/ExamplePlayerEventHandler.hpp"
#include "examples/ExampleVehicleEventHandler.hpp"
#include "examples/ExampleColshapeEventHandler.hpp"
#include "examples/ExampleCheckpointEventHandler.hpp"
#include "examples/ExampleBlipEventHandler.hpp"
#include "examples/ExampleTickEventHandler.hpp"
#include "examples/ExampleLocalEventEventHandler.hpp"
#include "examples/ExampleConnectionEventHandler.hpp"
#include "examples/ExampleServerEventHandler.hpp"

EXTERN uint32_t GetPluginVersion()
{
	return rage::IMultiplayer::SDK_VERSION;
}

EXTERN const char* GetPluginName()
{
	return "rage:MP SDK";
}

EXTERN bool InitializePlugin(rage::IMultiplayer* _mp)
{
	rage::IMultiplayer::SetInstance(_mp);
	rage::Log::Push(new rage::Log::ConsoleStream);

	rage::Log::Done("Initialized plugin.", ">>", GetPluginName());

	rage::IMultiplayer::Instance().SetEventHandler(new ExampleEntityEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExamplePlayerEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleVehicleEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleColshapeEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleCheckpointEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleBlipEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleTickEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleLocalEventEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleConnectionEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleServerEventHandler);

	return true;
}