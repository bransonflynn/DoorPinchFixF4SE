#pragma once

#include "RE/Bethesda/BSContainer.hpp"
#include "RE/Bethesda/BSFixedString.hpp"
#include "RE/Bethesda/BSLock.hpp"
#include "RE/Bethesda/BSScript.hpp"
#include "RE/Bethesda/BSScript/Array.hpp"
#include "RE/Bethesda/BSScript/ArrayWrapper.hpp"
#include "RE/Bethesda/BSScript/CompiledScriptLoader.hpp"
#include "RE/Bethesda/BSScript/ErrorLogger.hpp"
#include "RE/Bethesda/BSScript/ICachedErrorMessage.hpp"
#include "RE/Bethesda/BSScript/IClientVM.hpp"
#include "RE/Bethesda/BSScript/IComplexType.hpp"
#include "RE/Bethesda/BSScript/IFunction.hpp"
#include "RE/Bethesda/BSScript/IHandleReaderWriter.hpp"
#include "RE/Bethesda/BSScript/ILoader.hpp"
#include "RE/Bethesda/BSScript/IMemoryPagePolicy.hpp"
#include "RE/Bethesda/BSScript/IObjectHandlePolicy.hpp"
#include "RE/Bethesda/BSScript/IObjectProcessor.hpp"
#include "RE/Bethesda/BSScript/IProfilePolicy.hpp"
#include "RE/Bethesda/BSScript/ISavePatcherInterface.hpp"
#include "RE/Bethesda/BSScript/IStackCallbackFunctor.hpp"
#include "RE/Bethesda/BSScript/IStackCallbackSaveInterface.hpp"
#include "RE/Bethesda/BSScript/IVMDebugInterface.hpp"
#include "RE/Bethesda/BSScript/IVMObjectBindInterface.hpp"
#include "RE/Bethesda/BSScript/IVMSaveLoadInterface.hpp"
#include "RE/Bethesda/BSScript/IVirtualMachine.hpp"
#include "RE/Bethesda/BSScript/Internal/AttachedScript.hpp"
#include "RE/Bethesda/BSScript/Internal/CodeTasklet.hpp"
#include "RE/Bethesda/BSScript/Internal/EventRelay.hpp"
#include "RE/Bethesda/BSScript/Internal/FunctionMessage.hpp"
#include "RE/Bethesda/BSScript/Internal/IFuncCallQuery.hpp"
#include "RE/Bethesda/BSScript/Internal/RawFuncCallQuery.hpp"
#include "RE/Bethesda/BSScript/Internal/ReadableStringTable.hpp"
#include "RE/Bethesda/BSScript/Internal/ReadableTypeTable.hpp"
#include "RE/Bethesda/BSScript/Internal/ScriptFunction.hpp"
#include "RE/Bethesda/BSScript/Internal/SuspendedStack.hpp"
#include "RE/Bethesda/BSScript/Internal/VDescTable.hpp"
#include "RE/Bethesda/BSScript/Internal/VirtualMachine.hpp"
#include "RE/Bethesda/BSScript/Internal/WritableStringTable.hpp"
#include "RE/Bethesda/BSScript/Internal/WritableTypeTable.hpp"
#include "RE/Bethesda/BSScript/LinkerProcessor.hpp"
#include "RE/Bethesda/BSScript/LogEvent.hpp"
#include "RE/Bethesda/BSScript/MergedBoundScript.hpp"
#include "RE/Bethesda/BSScript/NF_util/NativeFunctionBase.hpp"
#include "RE/Bethesda/BSScript/Object.hpp"
#include "RE/Bethesda/BSScript/ObjectBindPolicy.hpp"
#include "RE/Bethesda/BSScript/ObjectTypeInfo.hpp"
#include "RE/Bethesda/BSScript/PackedInstructionStream.hpp"
#include "RE/Bethesda/BSScript/PropertyGroupInfo.hpp"
#include "RE/Bethesda/BSScript/PropertyTypeInfo.hpp"
#include "RE/Bethesda/BSScript/SimpleAllocMemoryPagePolicy.hpp"
#include "RE/Bethesda/BSScript/Stack.hpp"
#include "RE/Bethesda/BSScript/StackFrame.hpp"
#include "RE/Bethesda/BSScript/StatsEvent.hpp"
#include "RE/Bethesda/BSScript/Struct.hpp"
#include "RE/Bethesda/BSScript/StructTypeInfo.hpp"
#include "RE/Bethesda/BSScript/TypeInfo.hpp"
#include "RE/Bethesda/BSScript/Variable.hpp"
#include "RE/Bethesda/BSTArray.hpp"
#include "RE/Bethesda/BSTEvent.hpp"
#include "RE/Bethesda/BSTHashMap.hpp"
#include "RE/Bethesda/BSTObjectArena.hpp"
#include "RE/Bethesda/BSTSmartPointer.hpp"
#include "RE/Bethesda/BSTTuple.hpp"
#include "RE/Bethesda/MemoryManager.hpp"
