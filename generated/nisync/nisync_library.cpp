//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-SYNC Metadata
//---------------------------------------------------------------------
#include "nisync_library.h"

#if defined(_MSC_VER)
static const char* kLibraryName = "nisync.dll";
#else
static const char* kLibraryName = "libnisync.so";
#endif

namespace nisync_grpc {

NiSyncLibrary::NiSyncLibrary() : shared_library_(kLibraryName)
{
  shared_library_.load();
  bool loaded = shared_library_.is_loaded();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!loaded) {
    return;
  }
  function_pointers_.init = reinterpret_cast<initPtr>(shared_library_.get_function_pointer("niSync_init"));
  function_pointers_.close = reinterpret_cast<closePtr>(shared_library_.get_function_pointer("niSync_close"));
  function_pointers_.SendSoftwareTrigger = reinterpret_cast<SendSoftwareTriggerPtr>(shared_library_.get_function_pointer("niSync_SendSoftwareTrigger"));
  function_pointers_.ConnectClkTerminals = reinterpret_cast<ConnectClkTerminalsPtr>(shared_library_.get_function_pointer("niSync_ConnectClkTerminals"));
  function_pointers_.DisconnectClkTerminals = reinterpret_cast<DisconnectClkTerminalsPtr>(shared_library_.get_function_pointer("niSync_DisconnectClkTerminals"));
  function_pointers_.ConnectSWTrigToTerminal = reinterpret_cast<ConnectSWTrigToTerminalPtr>(shared_library_.get_function_pointer("niSync_ConnectSWTrigToTerminal"));
  function_pointers_.DisconnectSWTrigFromTerminal = reinterpret_cast<DisconnectSWTrigFromTerminalPtr>(shared_library_.get_function_pointer("niSync_DisconnectSWTrigFromTerminal"));
  function_pointers_.ConnectTrigTerminals = reinterpret_cast<ConnectTrigTerminalsPtr>(shared_library_.get_function_pointer("niSync_ConnectTrigTerminals"));
  function_pointers_.DisconnectTrigTerminals = reinterpret_cast<DisconnectTrigTerminalsPtr>(shared_library_.get_function_pointer("niSync_DisconnectTrigTerminals"));
  function_pointers_.GetAttributeViInt32 = reinterpret_cast<GetAttributeViInt32Ptr>(shared_library_.get_function_pointer("niSync_GetAttributeViInt32"));
  function_pointers_.SetAttributeViInt32 = reinterpret_cast<SetAttributeViInt32Ptr>(shared_library_.get_function_pointer("niSync_SetAttributeViInt32"));
  function_pointers_.GetAttributeViString = reinterpret_cast<GetAttributeViStringPtr>(shared_library_.get_function_pointer("niSync_GetAttributeViString"));
  function_pointers_.SetAttributeViString = reinterpret_cast<SetAttributeViStringPtr>(shared_library_.get_function_pointer("niSync_SetAttributeViString"));
}

NiSyncLibrary::~NiSyncLibrary()
{
}

::grpc::Status NiSyncLibrary::check_function_exists(std::string functionName)
{
  return shared_library_.function_exists(functionName.c_str())
    ? ::grpc::Status::OK
    : ::grpc::Status(::grpc::NOT_FOUND, "Could not find the function " + functionName);
}

ViStatus NiSyncLibrary::init(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViSession* vi)
{
  if (!function_pointers_.init) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_init.");
  }
#if defined(_MSC_VER)
  return niSync_init(resourceName, idQuery, resetDevice, vi);
#else
  return function_pointers_.init(resourceName, idQuery, resetDevice, vi);
#endif
}

ViStatus NiSyncLibrary::close(ViSession vi)
{
  if (!function_pointers_.close) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_close.");
  }
#if defined(_MSC_VER)
  return niSync_close(vi);
#else
  return function_pointers_.close(vi);
#endif
}

ViStatus NiSyncLibrary::SendSoftwareTrigger(ViSession vi, ViConstString srcTerminal)
{
  if (!function_pointers_.SendSoftwareTrigger) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_SendSoftwareTrigger.");
  }
#if defined(_MSC_VER)
  return niSync_SendSoftwareTrigger(vi, srcTerminal);
#else
  return function_pointers_.SendSoftwareTrigger(vi, srcTerminal);
#endif
}

ViStatus NiSyncLibrary::ConnectClkTerminals(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal)
{
  if (!function_pointers_.ConnectClkTerminals) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_ConnectClkTerminals.");
  }
#if defined(_MSC_VER)
  return niSync_ConnectClkTerminals(vi, srcTerminal, destTerminal);
#else
  return function_pointers_.ConnectClkTerminals(vi, srcTerminal, destTerminal);
#endif
}

ViStatus NiSyncLibrary::DisconnectClkTerminals(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal)
{
  if (!function_pointers_.DisconnectClkTerminals) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_DisconnectClkTerminals.");
  }
#if defined(_MSC_VER)
  return niSync_DisconnectClkTerminals(vi, srcTerminal, destTerminal);
#else
  return function_pointers_.DisconnectClkTerminals(vi, srcTerminal, destTerminal);
#endif
}

ViStatus NiSyncLibrary::ConnectSWTrigToTerminal(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal, ViConstString syncClock, ViInt32 invert, ViInt32 updateEdge, ViReal64 delay)
{
  if (!function_pointers_.ConnectSWTrigToTerminal) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_ConnectSWTrigToTerminal.");
  }
#if defined(_MSC_VER)
  return niSync_ConnectSWTrigToTerminal(vi, srcTerminal, destTerminal, syncClock, invert, updateEdge, delay);
#else
  return function_pointers_.ConnectSWTrigToTerminal(vi, srcTerminal, destTerminal, syncClock, invert, updateEdge, delay);
#endif
}

ViStatus NiSyncLibrary::DisconnectSWTrigFromTerminal(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal)
{
  if (!function_pointers_.DisconnectSWTrigFromTerminal) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_DisconnectSWTrigFromTerminal.");
  }
#if defined(_MSC_VER)
  return niSync_DisconnectSWTrigFromTerminal(vi, srcTerminal, destTerminal);
#else
  return function_pointers_.DisconnectSWTrigFromTerminal(vi, srcTerminal, destTerminal);
#endif
}

ViStatus NiSyncLibrary::ConnectTrigTerminals(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal, ViConstString syncClock, ViInt32 invert, ViInt32 updateEdge)
{
  if (!function_pointers_.ConnectTrigTerminals) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_ConnectTrigTerminals.");
  }
#if defined(_MSC_VER)
  return niSync_ConnectTrigTerminals(vi, srcTerminal, destTerminal, syncClock, invert, updateEdge);
#else
  return function_pointers_.ConnectTrigTerminals(vi, srcTerminal, destTerminal, syncClock, invert, updateEdge);
#endif
}

ViStatus NiSyncLibrary::DisconnectTrigTerminals(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal)
{
  if (!function_pointers_.DisconnectTrigTerminals) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_DisconnectTrigTerminals.");
  }
#if defined(_MSC_VER)
  return niSync_DisconnectTrigTerminals(vi, srcTerminal, destTerminal);
#else
  return function_pointers_.DisconnectTrigTerminals(vi, srcTerminal, destTerminal);
#endif
}

ViStatus NiSyncLibrary::GetAttributeViInt32(ViSession vi, ViConstString terminalName, ViAttr attribute, ViInt32* value)
{
  if (!function_pointers_.GetAttributeViInt32) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_GetAttributeViInt32.");
  }
#if defined(_MSC_VER)
  return niSync_GetAttributeViInt32(vi, terminalName, attribute, value);
#else
  return function_pointers_.GetAttributeViInt32(vi, terminalName, attribute, value);
#endif
}

ViStatus NiSyncLibrary::SetAttributeViInt32(ViSession vi, ViConstString terminalName, ViAttr attribute, ViInt32 value)
{
  if (!function_pointers_.SetAttributeViInt32) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_SetAttributeViInt32.");
  }
#if defined(_MSC_VER)
  return niSync_SetAttributeViInt32(vi, terminalName, attribute, value);
#else
  return function_pointers_.SetAttributeViInt32(vi, terminalName, attribute, value);
#endif
}

ViStatus NiSyncLibrary::GetAttributeViString(ViSession vi, ViConstString terminalName, ViAttr attribute, ViInt32 bufferSize, ViChar* value)
{
  if (!function_pointers_.GetAttributeViString) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_GetAttributeViString.");
  }
#if defined(_MSC_VER)
  return niSync_GetAttributeViString(vi, terminalName, attribute, bufferSize, value);
#else
  return function_pointers_.GetAttributeViString(vi, terminalName, attribute, bufferSize, value);
#endif
}

ViStatus NiSyncLibrary::SetAttributeViString(ViSession vi, ViConstString terminalName, ViAttr attribute, ViConstString value)
{
  if (!function_pointers_.SetAttributeViString) {
    throw nidevice_grpc::LibraryLoadException("Could not find niSync_SetAttributeViString.");
  }
#if defined(_MSC_VER)
  return niSync_SetAttributeViString(vi, terminalName, attribute, value);
#else
  return function_pointers_.SetAttributeViString(vi, terminalName, attribute, value);
#endif
}

}  // namespace nisync_grpc
