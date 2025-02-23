#include "Internal/Events/Patches/OpenCloseFormPatch.hpp"
#include "Internal/DoorPinchFix.hpp"
#include "Internal/Events/Patches/VTables.hpp"

#define PLAYERREF_FORMID 0x14

namespace Internal::Events::OpenCloseFormPatch
{
	// a_senderRef = the door that was activated
	// a_actionRef = the ref that activated the door (the player for this)
	// a_isOpening

	static auto _HandleOpenStart = REL::Relocation<decltype(&RE::BGSOpenCloseForm::HandleOpenStart)>();
	static auto _HandleCloseStart = REL::Relocation<decltype(&RE::BGSOpenCloseForm::HandleCloseStart)>();
	static auto _HandleOpenFinish = REL::Relocation<decltype(&RE::BGSOpenCloseForm::HandleOpenFinish)>();
	// static auto _HandleCloseFinish = REL::Relocation<decltype(&RE::BGSOpenCloseForm::HandleCloseFinish)>();

	static void HandleOpenStart(RE::BGSOpenCloseForm* a_this, RE::TESObjectREFR* a_senderRef, RE::TESObjectREFR* a_actionRef, bool a_isOpening)
	{
		if(a_actionRef == nullptr) {
			logger::info("HandleOpenStart a_actionRef was null"sv);
			return _HandleOpenStart(a_this, a_senderRef, a_actionRef, a_isOpening);
		}
		if(a_senderRef == nullptr) {
			logger::info("HandleOpenStart a_senderRef was null"sv);
			return _HandleOpenStart(a_this, a_senderRef, a_actionRef, a_isOpening);
		}
		if (a_actionRef->GetBaseObject()->formID != PLAYERREF_FORMID) {
			logger::info("HandleOpenStart was not player"sv);
			return _HandleOpenStart(a_this, a_senderRef, a_actionRef, a_isOpening);
		}

		logger::info("HandleOpenStart ran"sv);

		// disable collision
		// Internal::DoorPinchFix::ToggleCollision(a_senderRef, false);

		return _HandleOpenStart(a_this, a_senderRef, a_actionRef, a_isOpening);
	}

	static void HandleCloseStart(RE::BGSOpenCloseForm* a_this, RE::TESObjectREFR* a_senderRef, RE::TESObjectREFR* a_actionRef, bool a_isOpening)
	{
		if(a_actionRef == nullptr) {
			logger::info("HandleCloseStart a_actionRef was null"sv);
			return _HandleCloseStart(a_this, a_senderRef, a_actionRef, a_isOpening);
		}
		if(a_senderRef == nullptr) {
			logger::info("HandleCloseStart a_senderRef was null"sv);
			return _HandleCloseStart(a_this, a_senderRef, a_actionRef, a_isOpening);
		}
		if (a_actionRef->GetBaseObject()->formID != PLAYERREF_FORMID) {
			logger::info("HandleCloseStart was not player"sv);
			return _HandleCloseStart(a_this, a_senderRef, a_actionRef, a_isOpening);
		}

		logger::info("HandleCloseStart ran"sv);

		// enable collision
		// Internal::DoorPinchFix::ToggleCollision(a_senderRef, true);

		return _HandleCloseStart(a_this, a_senderRef, a_actionRef, a_isOpening);
	}

	static void HandleOpenFinish(RE::BGSOpenCloseForm* a_this, RE::TESObjectREFR* a_senderRef, RE::TESObjectREFR* a_actionRef)
	{
		if(a_actionRef == nullptr) {
			logger::info("HandleOpenFinish a_actionRef was null"sv);
			return _HandleOpenFinish(a_this, a_senderRef, a_actionRef);
		}
		if(a_senderRef == nullptr) {
			logger::info("HandleCloseStart a_senderRef was null"sv);
			return _HandleOpenFinish(a_this, a_senderRef, a_actionRef);
		}
		if (a_actionRef->GetBaseObject()->formID != PLAYERREF_FORMID) {
			logger::info("HandleOpenFinish was not player"sv);
			return _HandleOpenFinish(a_this, a_senderRef, a_actionRef);
		}

		logger::info("HandleOpenFinish ran"sv);

		// enable collision
		// Internal::DoorPinchFix::ToggleCollision(a_senderRef, true);

		return _HandleOpenFinish(a_this, a_senderRef, a_actionRef);
	}

	// static void HandleCloseFinish(RE::TESObjectDOOR* a_this, RE::TESObjectREFR* a_senderRef, RE::TESObjectREFR* a_actionRef)
	// {
	// 	logger::info("HandleCloseFinish ran, arg1={}, arg2={}", a_senderRef->GetFormEditorID(), a_actionRef->GetFormEditorIDLength());

	// 	// enable collision
	// 	//Internal::DoorPinchFix::ToggleCollision(a_senderRef, true);

	// 	return _HandleCloseFinish(a_this, a_senderRef, a_actionRef);
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
