/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include "CHIPClusters.h"

#include <cstdint>

#include <app-common/zap-generated/ids/Attributes.h>
#include <app/InteractionModelEngine.h>
#include <app/chip-zcl-zpro-codec.h>
#include <app/util/basic-types.h>
#include <lib/core/CHIPSafeCasts.h>
#include <lib/support/BufferWriter.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/SafeInt.h>
#include <lib/support/logging/CHIPLogging.h>
#include <system/SystemPacketBuffer.h>
#include <zap-generated/CHIPClientCallbacks.h>

namespace chip {

using namespace app::Clusters;
using namespace System;
using namespace Encoding::LittleEndian;

namespace Controller {

// TODO(#4502): onCompletion is not used by IM for now.
// TODO(#4503): length should be passed to commands when byte string is in argument list.
// TODO(#4503): Commands should take group id as an argument.

// GeneralCommissioning Cluster Commands
CHIP_ERROR GeneralCommissioningCluster::ArmFailSafe(Callback::Cancelable * onSuccessCallback,
                                                    Callback::Cancelable * onFailureCallback, uint16_t expiryLengthSeconds,
                                                    uint64_t breadcrumb, uint32_t timeoutMs)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId, GeneralCommissioning::Commands::ArmFailSafe::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // expiryLengthSeconds: int16u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), expiryLengthSeconds));
    // breadcrumb: int64u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), breadcrumb));
    // timeoutMs: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), timeoutMs));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR GeneralCommissioningCluster::CommissioningComplete(Callback::Cancelable * onSuccessCallback,
                                                              Callback::Cancelable * onFailureCallback)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         GeneralCommissioning::Commands::CommissioningComplete::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    // Command takes no arguments.

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR GeneralCommissioningCluster::SetRegulatoryConfig(Callback::Cancelable * onSuccessCallback,
                                                            Callback::Cancelable * onFailureCallback, uint8_t location,
                                                            chip::ByteSpan countryCode, uint64_t breadcrumb, uint32_t timeoutMs)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         GeneralCommissioning::Commands::SetRegulatoryConfig::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // location: regulatoryLocationType
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), location));
    // countryCode: charString
    SuccessOrExit(err = writer->PutString(TLV::ContextTag(argSeqNumber++),
                                          Span<const char>(Uint8::to_const_char(countryCode.data()), countryCode.size())));
    // breadcrumb: int64u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), breadcrumb));
    // timeoutMs: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), timeoutMs));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

// GeneralCommissioning Cluster Attributes
CHIP_ERROR GeneralCommissioningCluster::ReadAttributeBreadcrumb(Callback::Cancelable * onSuccessCallback,
                                                                Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000000;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int64uAttributeCallback>);
}

CHIP_ERROR GeneralCommissioningCluster::WriteAttributeBreadcrumb(Callback::Cancelable * onSuccessCallback,
                                                                 Callback::Cancelable * onFailureCallback, uint64_t value)
{
    app::WriteClientHandle handle;
    chip::app::AttributePathParams attributePath;
    attributePath.mNodeId     = mDevice->GetDeviceId();
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000000;
    attributePath.mFlags.Set(chip::app::AttributePathParams::Flags::kFieldIdValid);

    ReturnErrorOnFailure(app::InteractionModelEngine::GetInstance()->NewWriteClient(handle));
    ReturnErrorOnFailure(handle.EncodeScalarAttributeWritePayload(attributePath, value));

    return mDevice->SendWriteAttributeRequest(std::move(handle), onSuccessCallback, onFailureCallback);
}

CHIP_ERROR GeneralCommissioningCluster::ReadAttributeBasicCommissioningInfoList(Callback::Cancelable * onSuccessCallback,
                                                                                Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000001;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             GeneralCommissioningClusterBasicCommissioningInfoListListAttributeFilter);
}

CHIP_ERROR GeneralCommissioningCluster::ReadAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                                     Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x0000FFFD;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

// NetworkCommissioning Cluster Commands
CHIP_ERROR NetworkCommissioningCluster::DisableNetwork(Callback::Cancelable * onSuccessCallback,
                                                       Callback::Cancelable * onFailureCallback, chip::ByteSpan networkID,
                                                       uint64_t breadcrumb, uint32_t timeoutMs)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         NetworkCommissioning::Commands::DisableNetwork::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // networkID: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), networkID));
    // breadcrumb: int64u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), breadcrumb));
    // timeoutMs: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), timeoutMs));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR NetworkCommissioningCluster::EnableNetwork(Callback::Cancelable * onSuccessCallback,
                                                      Callback::Cancelable * onFailureCallback, chip::ByteSpan networkID,
                                                      uint64_t breadcrumb, uint32_t timeoutMs)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId, NetworkCommissioning::Commands::EnableNetwork::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // networkID: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), networkID));
    // breadcrumb: int64u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), breadcrumb));
    // timeoutMs: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), timeoutMs));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR NetworkCommissioningCluster::GetLastNetworkCommissioningResult(Callback::Cancelable * onSuccessCallback,
                                                                          Callback::Cancelable * onFailureCallback,
                                                                          uint32_t timeoutMs)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         NetworkCommissioning::Commands::GetLastNetworkCommissioningResult::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // timeoutMs: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), timeoutMs));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR NetworkCommissioningCluster::RemoveNetwork(Callback::Cancelable * onSuccessCallback,
                                                      Callback::Cancelable * onFailureCallback, chip::ByteSpan networkID,
                                                      uint64_t breadcrumb, uint32_t timeoutMs)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId, NetworkCommissioning::Commands::RemoveNetwork::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // networkID: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), networkID));
    // breadcrumb: int64u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), breadcrumb));
    // timeoutMs: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), timeoutMs));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR NetworkCommissioningCluster::ScanNetworks(Callback::Cancelable * onSuccessCallback,
                                                     Callback::Cancelable * onFailureCallback, chip::ByteSpan ssid,
                                                     uint64_t breadcrumb, uint32_t timeoutMs)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId, NetworkCommissioning::Commands::ScanNetworks::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // ssid: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), ssid));
    // breadcrumb: int64u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), breadcrumb));
    // timeoutMs: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), timeoutMs));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

// NetworkCommissioning Cluster Attributes
CHIP_ERROR NetworkCommissioningCluster::ReadAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                                     Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x0000FFFD;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

// OperationalCredentials Cluster Commands
CHIP_ERROR OperationalCredentialsCluster::AddNOC(Callback::Cancelable * onSuccessCallback, Callback::Cancelable * onFailureCallback,
                                                 chip::ByteSpan NOCValue, chip::ByteSpan ICACValue, chip::ByteSpan IPKValue,
                                                 chip::NodeId caseAdminNode, uint16_t adminVendorId)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId, OperationalCredentials::Commands::AddNOC::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // NOCValue: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), NOCValue));
    // ICACValue: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), ICACValue));
    // IPKValue: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), IPKValue));
    // caseAdminNode: nodeId
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), caseAdminNode));
    // adminVendorId: int16u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), adminVendorId));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR OperationalCredentialsCluster::AddTrustedRootCertificate(Callback::Cancelable * onSuccessCallback,
                                                                    Callback::Cancelable * onFailureCallback,
                                                                    chip::ByteSpan rootCertificate)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OperationalCredentials::Commands::AddTrustedRootCertificate::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // rootCertificate: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), rootCertificate));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR OperationalCredentialsCluster::AttestationRequest(Callback::Cancelable * onSuccessCallback,
                                                             Callback::Cancelable * onFailureCallback,
                                                             chip::ByteSpan attestationNonce)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OperationalCredentials::Commands::AttestationRequest::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // attestationNonce: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), attestationNonce));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR OperationalCredentialsCluster::CertificateChainRequest(Callback::Cancelable * onSuccessCallback,
                                                                  Callback::Cancelable * onFailureCallback, uint8_t certificateType)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OperationalCredentials::Commands::CertificateChainRequest::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // certificateType: int8u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), certificateType));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR OperationalCredentialsCluster::OpCSRRequest(Callback::Cancelable * onSuccessCallback,
                                                       Callback::Cancelable * onFailureCallback, chip::ByteSpan CSRNonce)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OperationalCredentials::Commands::OpCSRRequest::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // CSRNonce: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), CSRNonce));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR OperationalCredentialsCluster::RemoveFabric(Callback::Cancelable * onSuccessCallback,
                                                       Callback::Cancelable * onFailureCallback, uint8_t fabricIndex)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OperationalCredentials::Commands::RemoveFabric::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // fabricIndex: int8u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), fabricIndex));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR OperationalCredentialsCluster::UpdateFabricLabel(Callback::Cancelable * onSuccessCallback,
                                                            Callback::Cancelable * onFailureCallback, chip::ByteSpan label)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OperationalCredentials::Commands::UpdateFabricLabel::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // label: charString
    SuccessOrExit(err = writer->PutString(TLV::ContextTag(argSeqNumber++),
                                          Span<const char>(Uint8::to_const_char(label.data()), label.size())));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

// OperationalCredentials Cluster Attributes
CHIP_ERROR OperationalCredentialsCluster::ReadAttributeFabricsList(Callback::Cancelable * onSuccessCallback,
                                                                   Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000001;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             OperationalCredentialsClusterFabricsListListAttributeFilter);
}

CHIP_ERROR OperationalCredentialsCluster::ReadAttributeSupportedFabrics(Callback::Cancelable * onSuccessCallback,
                                                                        Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000002;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int8uAttributeCallback>);
}

CHIP_ERROR OperationalCredentialsCluster::ReadAttributeCommissionedFabrics(Callback::Cancelable * onSuccessCallback,
                                                                           Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000003;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int8uAttributeCallback>);
}

CHIP_ERROR OperationalCredentialsCluster::ReadAttributeTrustedRootCertificates(Callback::Cancelable * onSuccessCallback,
                                                                               Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000004;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             OperationalCredentialsClusterTrustedRootCertificatesListAttributeFilter);
}

CHIP_ERROR OperationalCredentialsCluster::ReadAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                                       Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x0000FFFD;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

} // namespace Controller
} // namespace chip
