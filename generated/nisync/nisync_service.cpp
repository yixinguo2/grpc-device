
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-SYNC Metadata
//---------------------------------------------------------------------
#include "nisync_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>

namespace nisync_grpc {

  NiSyncService::NiSyncService(NiSyncLibraryInterface* library, nidevice_grpc::SessionRepository* session_repository)
      : library_(library), session_repository_(session_repository)
  {
  }

  NiSyncService::~NiSyncService()
  {
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::Init(::grpc::ServerContext* context, const InitRequest* request, InitResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      ViRsrc resource_name = (ViRsrc)request->resource_name().c_str();
      ViBoolean id_query = request->id_query();
      ViBoolean reset_device = request->reset_device();

      auto init_lambda = [&] () -> std::tuple<int, uint32_t> {
        ViSession vi;
        int status = library_->init(resource_name, id_query, reset_device, &vi);
        return std::make_tuple(status, vi);
      };
      uint32_t session_id = 0;
      const std::string& session_name = request->session_name();
      auto cleanup_lambda = [&] (uint32_t id) { library_->close(id); };
      int status = session_repository_->add_session(session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status == 0) {
        response->mutable_vi()->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      session_repository_->remove_session(vi);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SendSoftwareTrigger(::grpc::ServerContext* context, const SendSoftwareTriggerRequest* request, SendSoftwareTriggerResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      auto status = library_->SendSoftwareTrigger(vi, src_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::ConnectClkTerminals(::grpc::ServerContext* context, const ConnectClkTerminalsRequest* request, ConnectClkTerminalsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      auto status = library_->ConnectClkTerminals(vi, src_terminal, dest_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::DisconnectClkTerminals(::grpc::ServerContext* context, const DisconnectClkTerminalsRequest* request, DisconnectClkTerminalsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      auto status = library_->DisconnectClkTerminals(vi, src_terminal, dest_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::ConnectSWTrigToTerminal(::grpc::ServerContext* context, const ConnectSWTrigToTerminalRequest* request, ConnectSWTrigToTerminalResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      ViConstString sync_clock = request->sync_clock().c_str();
      ViInt32 invert = request->invert();
      ViInt32 update_edge = request->update_edge();
      ViReal64 delay = request->delay();
      auto status = library_->ConnectSWTrigToTerminal(vi, src_terminal, dest_terminal, sync_clock, invert, update_edge, delay);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::DisconnectSWTrigFromTerminal(::grpc::ServerContext* context, const DisconnectSWTrigFromTerminalRequest* request, DisconnectSWTrigFromTerminalResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      auto status = library_->DisconnectSWTrigFromTerminal(vi, src_terminal, dest_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::ConnectTrigTerminals(::grpc::ServerContext* context, const ConnectTrigTerminalsRequest* request, ConnectTrigTerminalsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      ViConstString sync_clock = request->sync_clock().c_str();
      ViInt32 invert = request->invert();
      ViInt32 update_edge = request->update_edge();
      auto status = library_->ConnectTrigTerminals(vi, src_terminal, dest_terminal, sync_clock, invert, update_edge);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::DisconnectTrigTerminals(::grpc::ServerContext* context, const DisconnectTrigTerminalsRequest* request, DisconnectTrigTerminalsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      auto status = library_->DisconnectTrigTerminals(vi, src_terminal, dest_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::GetAttributeViInt32(::grpc::ServerContext* context, const GetAttributeViInt32Request* request, GetAttributeViInt32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      ViAttr attribute = request->attribute();
      ViInt32 value {};
      auto status = library_->GetAttributeViInt32(vi, terminal_name, attribute, &value);
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetAttributeViInt32(::grpc::ServerContext* context, const SetAttributeViInt32Request* request, SetAttributeViInt32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      ViAttr attribute = request->attribute();
      ViInt32 value = request->value();
      auto status = library_->SetAttributeViInt32(vi, terminal_name, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::GetAttributeViString(::grpc::ServerContext* context, const GetAttributeViStringRequest* request, GetAttributeViStringResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      ViAttr attribute = request->attribute();
      ViInt32 buffer_size = request->buffer_size();
      ViChar value {};
      auto status = library_->GetAttributeViString(vi, terminal_name, attribute, buffer_size, &value);
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetAttributeViString(::grpc::ServerContext* context, const SetAttributeViStringRequest* request, SetAttributeViStringResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      ViAttr attribute = request->attribute();
      ViConstString value = request->value().c_str();
      auto status = library_->SetAttributeViString(vi, terminal_name, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

} // namespace nisync_grpc

