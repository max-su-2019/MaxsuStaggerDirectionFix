#pragma once

namespace SDFix
{
	class ResetStaggerDireHook
	{
	public:
		static void InstallHook()
		{
			SKSE::AllocTrampoline(1 << 4);

			REL::Relocation<std::uintptr_t> setGraphVarFloatBase{ REL::VariantID(32184, 32933, 32184) };

			auto& trampoline = SKSE::GetTrampoline();
			_SetGraphVarFloat = trampoline.write_call<5>(setGraphVarFloatBase.address() + REL::Relocate(0xA5, 0xC5, 0xA5), SetGraphVarFloat);
		}


	private:
		static bool SetGraphVarFloat(RE::BShkbAnimationGraph* Graph, const RE::BSFixedString& Var_name, float staggerDire);


		static inline REL::Relocation<decltype(SetGraphVarFloat)> _SetGraphVarFloat;
	};


}
