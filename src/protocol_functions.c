#include "platform_config.h"

#include "protocol.h"

#include <string.h>


bool protocolEvaluatePacket(protocolPacket_t *packet)
{
    switch(packet->msgId)
    {
    case PROTOCOL_MSG_ID_TIM_UTC:
        if(packet->payloadLength == 0)
        {
            protocolMsgPollCallbackTimUtc();
        }
        else
        {
            protocolMsgTimUtc_t msg;
            memcpy(&msg, packet->payload, sizeof(protocolMsgTimUtc_t));
            protocolMsgCallbackTimUtc(&msg);
        }
        break;

    case PROTOCOL_MSG_ID_TIM_STD:
        if(packet->payloadLength == 0)
        {
            protocolMsgPollCallbackTimStd();
        }
        else
        {
            protocolMsgTimStd_t msg;
            memcpy(&msg, packet->payload, sizeof(protocolMsgTimStd_t));
            protocolMsgCallbackTimStd(&msg);
        }
        break;

    case PROTOCOL_MSG_ID_TIM_DST:
        if(packet->payloadLength == 0)
        {
            protocolMsgPollCallbackTimDst();
        }
        else
        {
            protocolMsgTimDst_t msg;
            memcpy(&msg, packet->payload, sizeof(protocolMsgTimDst_t));
            protocolMsgCallbackTimDst(&msg);
        }
        break;

    case PROTOCOL_MSG_ID_TIM_SRC:
        if(packet->payloadLength == 0)
        {
            //protocolMsgPollCallbackTimSrc();
        }
        else
        {
            protocolMsgTimSrc_t msg;
            memcpy(&msg, packet->payload, sizeof(protocolMsgTimSrc_t));
            //protocolMsgCallbackTimSrc(&msg);
        }
        break;


    case PROTOCOL_MSG_ID_FPD_TST:
        if(packet->payloadLength == sizeof(protocolMsgFpdTst_t))
        {
            protocolMsgFpdTst_t msg;
            memcpy(&msg, packet->payload, sizeof(protocolMsgFpdTst_t));
            protocolMsgCallbackFpdTst(&msg);
        }
        break;

    case PROTOCOL_MSG_ID_FPD_TYP:
    	if(packet->payloadLength == 0)
		{
			protocolMsgPollCallbackFpdTyp();
		}
		else
		{
			protocolMsgFpdTyp_t msg;
			memcpy(&msg, packet->payload, sizeof(protocolMsgFpdTyp_t));
			protocolMsgCallbackFpdTyp(&msg);
		}
        break;

    case PROTOCOL_MSG_ID_FPD_MOD:
    	if(packet->payloadLength == 0)
		{
			protocolMsgPollCallbackFpdMod();
		}
		else
		{
			protocolMsgFpdMod_t msg;
			memcpy(&msg, packet->payload, sizeof(protocolMsgFpdMod_t));
			protocolMsgCallbackFpdMod(&msg);
		}
		break;

    case PROTOCOL_MSG_ID_FPD_R12:
        if(packet->payloadLength == sizeof(protocolMsgFpdR12_t))
        {
            protocolMsgFpdR12_t msg;
            memcpy(&msg, packet->payload, sizeof(protocolMsgFpdR12_t));
            protocolMsgCallbackFpdR12(&msg);
        }
        break;

    default:
        return false;
    }

    // msg got handled
    return true;
}

void protocolMsgSendTimUtc(protocolMsgTimUtc_t *msg)
{
    protocolPacket_t packet;
    packet.sync[0] = PROTOCOL_SYNC_0;
    packet.sync[1] = PROTOCOL_SYNC_1;
    packet.msgId = PROTOCOL_MSG_ID_TIM_UTC;
    packet.payloadLength = sizeof(protocolMsgTimUtc_t);
    memcpy(packet.payload, msg, sizeof(protocolMsgTimUtc_t));
    packet.checksum = protocolCalculateChecksum(&packet);
    protocolSendPacket(&packet);
}

void protocolMsgSendTimStd(protocolMsgTimStd_t *msg)
{
    protocolPacket_t packet;
    packet.sync[0] = PROTOCOL_SYNC_0;
    packet.sync[1] = PROTOCOL_SYNC_1;
    packet.msgId = PROTOCOL_MSG_ID_TIM_STD;
    packet.payloadLength = sizeof(protocolMsgTimStd_t);
    memcpy(packet.payload, msg, sizeof(protocolMsgTimStd_t));
    packet.checksum = protocolCalculateChecksum(&packet);
    protocolSendPacket(&packet);
}

void protocolMsgSendTimDst(protocolMsgTimDst_t *msg)
{
    protocolPacket_t packet;
    packet.sync[0] = PROTOCOL_SYNC_0;
    packet.sync[1] = PROTOCOL_SYNC_1;
    packet.msgId = PROTOCOL_MSG_ID_TIM_DST;
    packet.payloadLength = sizeof(protocolMsgTimDst_t);
    memcpy(packet.payload, msg, sizeof(protocolMsgTimDst_t));
    packet.checksum = protocolCalculateChecksum(&packet);
    protocolSendPacket(&packet);
}

void protocolMsgSendTimSrc(protocolMsgTimSrc_t *msg)
{
    protocolPacket_t packet;
    packet.sync[0] = PROTOCOL_SYNC_0;
    packet.sync[1] = PROTOCOL_SYNC_1;
    packet.msgId = PROTOCOL_MSG_ID_TIM_SRC;
    packet.payloadLength = sizeof(protocolMsgTimSrc_t);
    memcpy(packet.payload, msg, sizeof(protocolMsgTimSrc_t));
    packet.checksum = protocolCalculateChecksum(&packet);
    protocolSendPacket(&packet);
}

void protocolMsgSendFpdTyp(protocolMsgFpdTyp_t *msg)
{
    protocolPacket_t packet;
    packet.sync[0] = PROTOCOL_SYNC_0;
    packet.sync[1] = PROTOCOL_SYNC_1;
    packet.msgId = PROTOCOL_MSG_ID_FPD_TYP;
    packet.payloadLength = sizeof(protocolMsgFpdTyp_t);
    memcpy(packet.payload, msg, sizeof(protocolMsgFpdTyp_t));
    packet.checksum = protocolCalculateChecksum(&packet);
    protocolSendPacket(&packet);
}

void protocolMsgSendFpdMod(protocolMsgFpdMod_t *msg)
{
    protocolPacket_t packet;
    packet.sync[0] = PROTOCOL_SYNC_0;
    packet.sync[1] = PROTOCOL_SYNC_1;
    packet.msgId = PROTOCOL_MSG_ID_FPD_MOD;
    packet.payloadLength = sizeof(protocolMsgFpdMod_t);
    memcpy(packet.payload, msg, sizeof(protocolMsgFpdMod_t));
    packet.checksum = protocolCalculateChecksum(&packet);
    protocolSendPacket(&packet);
}
