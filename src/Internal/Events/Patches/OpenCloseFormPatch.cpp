#include "Internal/Events/Patches/OpenCloseFormPatch.hpp"
#include "Internal/DoorPinchFix.hpp"
#include "Internal/Events/Patches/VTables.hpp"

namespace Internal::Events::OpenCloseFormPatch
{
	static auto _HandleOpenStart = REL::Relocation<decltype(&RE::BGSOpenCloseForm::HandleOpenStart)>();
	static auto _HandleCloseStart = REL::Relocation<decltype(&RE::BGSOpenCloseForm::HandleCloseStart)>();
	static auto _HandleOpenFinish = REL::Relocation<decltype(&RE::BGSOpenCloseForm::HandleOpenFinish)>();
	// static auto _HandleCloseFinish = REL::Relocation<decltype(&RE::BGSOpenCloseForm::HandleCloseFinish)>();

	static void HandleOpenStart(RE::BGSOpenCloseForm* a_this, RE::TESObjectREFR* a_arg1, RE::TESObjectREFR* a_arg2, bool a_arg3)
	{
		if (a_arg1 != RE::PlayerCharacter::GetSingleton()) {
			return _HandleOpenStart(a_this, a_arg1, a_arg2, a_arg3);
		}

		logger::info("HandleOpenStart ran"sv);

		// disable collision
		// Internal::DoorPinchFix::ToggleCollision(a_arg1, false);

		return _HandleOpenStart(a_this, a_arg1, a_arg2, a_arg3);
	}

	static void HandleCloseStart(RE::BGSOpenCloseForm* a_this, RE::TESObjectREFR* a_arg1, RE::TESObjectREFR* a_arg2, bool a_arg3)
	{
		if (a_arg1 != RE::PlayerCharacter::GetSingleton()) {
			return _HandleCloseStart(a_this, a_arg1, a_arg2, a_arg3);
		}

		logger::info("HandleCloseStart ran"sv);

		// enable collision
		// Internal::DoorPinchFix::ToggleCollision(a_arg1, true);

		return _HandleCloseStart(a_this, a_arg1, a_arg2, a_arg3);
	}

	static void HandleOpenFinish(RE::BGSOpenCloseForm* a_this, RE::TESObjectREFR* a_arg1, RE::TESObjectREFR* a_arg2)
	{
		if (a_arg1 != RE::PlayerCharacter::GetSingleton()) {
			return _HandleOpenFinish(a_this, a_arg1, a_arg2);
		}

		logger::info("HandleOpenFinish ran"sv);

		// enable collision
		// Internal::DoorPinchFix::ToggleCollision(a_arg1, true);

		return _HandleOpenFinish(a_this, a_arg1, a_arg2);
	}

	// static void HandleCloseFinish(RE::TESObjectDOOR* a_this, RE::TESObjectREFR* a_arg1, RE::TESObjectREFR* a_arg2)
	// {
	// 	logger::info("HandleCloseFinish ran, arg1={}, arg2={}", a_arg1->GetFormEditorID(), a_arg2->GetFormEditorIDLength());

	// 	// enable collision
	// 	//Internal::DoorPinchFix::ToggleCollision(a_arg1, true);

	// 	return _HandleCloseFinish(a_this, a_arg1, a_arg2);
	// }

	void Install() noexcept
	{
		logger::info("OpenCloseFormPatch installing...");

		auto vtable = REL::Relocation<std::uintptr_t>{ RE::VTABLE::TESObjectDOOR[6] };
		_HandleOpenStart = vtable.write_vfunc(0x1, HandleOpenStart);
		_HandleCloseStart = vtable.write_vfunc(0x2, HandleCloseStart);
		_HandleOpenFinish = vtable.write_vfunc(0x3, HandleOpenFinish);
		//_HandleCloseFinish = vtable.write_vfunc(0x4, HandleCloseFinish);

		logger::info("OpenCloseFormPatch installed!");
	}
}
