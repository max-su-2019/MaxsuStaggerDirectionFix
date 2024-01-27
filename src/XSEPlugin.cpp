#include "SDFix_Events.h"
#include "SDFix_Hooks.h"

void Load()
{
	SDFix::ResetStaggerDireHook::InstallHook();
	SDFix::EffectStartEventHandler::RegisterEffectStartEvent();
}