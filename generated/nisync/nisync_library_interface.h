//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-SYNC
//---------------------------------------------------------------------
#ifndef NISYNC_GRPC_LIBRARY_WRAPPER_H
#define NISYNC_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <nisync.h>

namespace nisync_grpc {

class NiSyncLibraryInterface {
 public:
  virtual ~NiSyncLibraryInterface() {}

  virtual ViStatus init(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViSession* vi) = 0;
  virtual ViStatus close(ViSession vi) = 0;
  virtual ViStatus ConnectClkTerminals(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal) = 0;
  virtual ViStatus DisconnectClkTerminals(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal) = 0;
  virtual ViStatus ConnectSWTrigToTerminal(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal, ViConstString syncClock, ViInt32 invert, ViInt32 updateEdge, ViReal64 delay) = 0;
  virtual ViStatus DisconnectSWTrigFromTerminal(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal) = 0;
  virtual ViStatus ConnectTrigTerminals(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal, ViConstString syncClock, ViInt32 invert, ViInt32 updateEdge) = 0;
  virtual ViStatus DisconnectTrigTerminals(ViSession vi, ViConstString srcTerminal, ViConstString destTerminal) = 0;
};

}  // namespace nisync_grpc
#endif  // NISYNC_GRPC_LIBRARY_WRAPPER_H
