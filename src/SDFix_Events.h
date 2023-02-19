#pragma once

namespace SDFix
{
	using EventResult = RE::BSEventNotifyControl;

	class EffectStartEventHandler : public RE::BSTEventSink<RE::TESMagicEffectApplyEvent>
	{
	public:
		virtual EventResult ProcessEvent(const RE::TESMagicEffectApplyEvent* a_event, RE::BSTEventSource<RE::TESMagicEffectApplyEvent>* a_eventSource);

		static bool RegisterEffectStartEvent();

	private:
		EffectStartEventHandler() = default;

		~EffectStartEventHandler() = default;

		EffectStartEventHandler(const EffectStartEventHandler&) = delete;

		EffectStartEventHandler(EffectStartEventHandler&&) = delete;

		EffectStartEventHandler& operator=(const EffectStartEventHandler&) = delete;

		EffectStartEventHandler& operator=(EffectStartEventHandler&&) = delete;
	};
}
