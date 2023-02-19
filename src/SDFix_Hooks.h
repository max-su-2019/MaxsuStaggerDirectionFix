#pragma once

namespace SDFix
{
	class ResetStaggerDireHook
	{
	public:
		static void InstallHook()
		{
			SKSE::AllocTrampoline(14);
			REL::Relocation<std::uintptr_t> setGraphVarFloatBase{ REL::RelocationID(36700, 37710) };
			auto& trampoline = SKSE::GetTrampoline();
			_SetGraphVarFloat = trampoline.write_call<5>(setGraphVarFloatBase.address() + REL::Relocate(0x163, 0x17E), SetGraphVarFloat);
		}

	private:
		static bool SetGraphVarFloat(RE::BShkbAnimationGraph* Graph, const RE::BSFixedString& Var_name, float staggerDire);

		static inline REL::Relocation<decltype(SetGraphVarFloat)> _SetGraphVarFloat;
	};
}
