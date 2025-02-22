#pragma once

namespace Internal::DoorPinchFix
{
	void Install() noexcept;

	bool IsDoorRef(const RE::TESObjectREFR* target);

	bool IsLoadDoorRef(const RE::TESObjectREFR* target);

	bool CanPlayerActivateDoor(RE::TESObjectREFR* target);

	bool HasCollision(const RE::TESObjectREFR* target);

	void ToggleCollision(const RE::TESObjectREFR* target, bool enableCollision);
}
