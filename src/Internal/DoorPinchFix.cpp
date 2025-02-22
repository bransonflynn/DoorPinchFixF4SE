#include "Internal/DoorPinchFix.hpp"
#include "Internal/Events/Patches/OpenCloseFormPatch.hpp"

#define COLLISION_FLAG 0x10

namespace Internal::DoorPinchFix
{
	void Install() noexcept
	{
		logger::info("Installing...");

		Events::OpenCloseFormPatch::Install();

		logger::info("Installed!");
	}

	bool IsDoorRef(const RE::TESObjectREFR* target)
	{
		if (!target) {
			return false;
		}

		return target->GetBaseObject()->formType == RE::ENUM_FORMTYPE::kDOOR;
	}

	bool IsLoadDoorRef(const RE::TESObjectREFR* target)
	{
		if (!target) {
			return false;
		}

		return target->extraList.get()->HasType(RE::kTeleport);
	}

	bool CanPlayerActivateDoor(RE::TESObjectREFR* target)
	{
		if (!target) {
			return false;
		}

		if (target->GetLock() == nullptr) {
			return true;
		}
		else {
			RE::REFR_LOCK* refLock = new RE::REFR_LOCK; // idfk either
			return RE::GamePlayFormulas::CanPickLockGateCheck(refLock->GetLockLevel(target));
		}
	}

	bool HasCollision(const RE::TESObjectREFR* target)
	{
		if (!target) {
			return false;
		}

		return target->GetBaseObject()->formFlags & COLLISION_FLAG;
	}

	void ToggleCollision(const RE::TESObjectREFR* target, bool enableCollision)
	{
		if (!target) {
			return;
		}

		if (enableCollision) {
			target->GetBaseObject()->formFlags |= COLLISION_FLAG;
		}
		else {
			target->GetBaseObject()->formFlags &= COLLISION_FLAG;
		}

		target->GetBaseObject()->AddChange(RE::CHANGE_TYPE::kFormFlags);
	}
}
