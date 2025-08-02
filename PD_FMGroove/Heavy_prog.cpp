/**
 * Copyright (c) 2025 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_prog.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_prog *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_prog_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_prog));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_prog(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_prog_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_prog));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_prog(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_prog_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_prog();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_4437ONVn);
  numBytes += sPhasor_k_init(&sPhasor_scGQfy2W, 700.0f, sampleRate);
  numBytes += sLine_init(&sLine_5RQ9kX34);
  numBytes += sPhasor_k_init(&sPhasor_Rgm0L1rB, 0.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_YvJE5CWg, sampleRate);
  numBytes += sDel1_init(&sDel1_Rji09wFV);
  numBytes += sSamphold_init(&sSamphold_fJfhpIGB);
  numBytes += sLine_init(&sLine_j0MqIaZh);
  numBytes += cVar_init_f(&cVar_ADKL9mqo, 0.0f);
  numBytes += cVar_init_f(&cVar_hGoc1iAt, 0.0f);
  numBytes += cVar_init_f(&cVar_KTmhIyJl, 0.0f);
  numBytes += cBinop_init(&cBinop_Wa0Px0MI, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_7u4TlyMM, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_esTSk7ab, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_DhRK9Ofo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ErRXNR4E, 0.0f);
  numBytes += cDelay_init(this, &cDelay_mHAtRiKU, 0.0f);
  numBytes += cVar_init_f(&cVar_RL8wx8Tm, 120.0f);
  numBytes += cBinop_init(&cBinop_h9zq6PdA, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_PUGtgsGg, 1.0f);
  numBytes += cRandom_init(&cRandom_DlmreFi6, -2017458501);
  numBytes += cSlice_init(&cSlice_gu1DPECm, 1, 1);
  numBytes += cRandom_init(&cRandom_ohN1pQkX, 785627074);
  numBytes += cSlice_init(&cSlice_W9uX8I73, 1, 1);
  numBytes += cRandom_init(&cRandom_NjCEMX4y, -790393766);
  numBytes += cSlice_init(&cSlice_8rvlLtqA, 1, 1);
  numBytes += cBinop_init(&cBinop_CLUUCjlL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_tItzKjaA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_CUwBJlgN, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  // nothing to free
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OO736RiY_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_prog::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_prog::cVar_ADKL9mqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CUwBJlgN, m);
}

void Heavy_prog::cVar_hGoc1iAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Rgm0L1rB, 0, m);
}

void Heavy_prog::cVar_KTmhIyJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tItzKjaA, m);
}

void Heavy_prog::cCast_1iqkRX5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DYxKkUGA_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_AsVu0ThG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wa0Px0MI, HV_BINOP_DIVIDE, 0, m, &cBinop_Wa0Px0MI_sendMessage);
}

void Heavy_prog::cCast_GwIbW466_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aonSVFEV_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_rmlfjjx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_rn3L9dMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HjLvXFgq_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_DYxKkUGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_j0MqIaZh, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_j0MqIaZh, 0, m, NULL);
}

void Heavy_prog::cMsg_HjLvXFgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 110.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1iqkRX5d_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AsVu0ThG_sendMessage);
}

void Heavy_prog::cBinop_Wa0Px0MI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7u4TlyMM, m);
}

void Heavy_prog::cMsg_aonSVFEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 32.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wa0Px0MI, HV_BINOP_DIVIDE, 1, m, &cBinop_Wa0Px0MI_sendMessage);
}

void Heavy_prog::cSwitchcase_OjuF7G9C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xc9ihZZ7_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KjQ2oqxs_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z8mQvphR_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_xc9ihZZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zTGEY5xi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KH3hL8kx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bnd32ijC_sendMessage);
}

void Heavy_prog::cCast_KjQ2oqxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_epsq2aN6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kKg58wPG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tx9kBLzb_sendMessage);
}

void Heavy_prog::cCast_Z8mQvphR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nFQTiStw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ypzulLQW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9fezAphZ_sendMessage);
}

void Heavy_prog::cCast_G5G7ykd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JObKqvpp_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_KVTopYo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_esTSk7ab, HV_BINOP_DIVIDE, 0, m, &cBinop_esTSk7ab_sendMessage);
}

void Heavy_prog::cCast_ypzulLQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WAg4VJSa_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_9fezAphZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ialxwo6T_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_nFQTiStw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_Tx9kBLzb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ialxwo6T_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_kKg58wPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5XK6cLpc_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_epsq2aN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_KH3hL8kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dzitaD4Y_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Bnd32ijC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ialxwo6T_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_zTGEY5xi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cMsg_JObKqvpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_4437ONVn, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_4437ONVn, 0, m, NULL);
}

void Heavy_prog::cBinop_esTSk7ab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DhRK9Ofo, m);
}

void Heavy_prog::cMsg_Ialxwo6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 110.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_G5G7ykd3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KVTopYo3_sendMessage);
}

void Heavy_prog::cMsg_WAg4VJSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 15.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_esTSk7ab, HV_BINOP_DIVIDE, 1, m, &cBinop_esTSk7ab_sendMessage);
}

void Heavy_prog::cMsg_dzitaD4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_esTSk7ab, HV_BINOP_DIVIDE, 1, m, &cBinop_esTSk7ab_sendMessage);
}

void Heavy_prog::cMsg_5XK6cLpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 12.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_esTSk7ab, HV_BINOP_DIVIDE, 1, m, &cBinop_esTSk7ab_sendMessage);
}

void Heavy_prog::cVar_ErRXNR4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_68gCI6rh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_UNIPOLAR, 4.0f, 0, m, &cBinop_M7Gw6xCA_sendMessage);
}

void Heavy_prog::cSwitchcase_BdnQzHv2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ui8QndUZ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_ui8QndUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rmlfjjx6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GwIbW466_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rn3L9dMB_sendMessage);
}

void Heavy_prog::cCast_LQjTK4yz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ViBtgmvt_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_QlzQqWLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mapQiBpJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_ViBtgmvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 40.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5RQ9kX34, 0, m, NULL);
}

void Heavy_prog::cMsg_mapQiBpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  sLine_onMessage(_c, &Context(_c)->sLine_5RQ9kX34, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_Sv1gi3Qp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_179PO3x4_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_179PO3x4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gV8zdsjj_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_mHAtRiKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mHAtRiKU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mHAtRiKU, 0, m, &cDelay_mHAtRiKU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6nLWNYUI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P73rH3WE_sendMessage);
}

void Heavy_prog::cCast_gV8zdsjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_179PO3x4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mHAtRiKU, 0, m, &cDelay_mHAtRiKU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6nLWNYUI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P73rH3WE_sendMessage);
}

void Heavy_prog::cMsg_CemfnnFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KYdArjVW_sendMessage);
}

void Heavy_prog::cSystem_KYdArjVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aexeQE0l_sendMessage);
}

void Heavy_prog::cVar_RL8wx8Tm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h9zq6PdA, HV_BINOP_MULTIPLY, 0, m, &cBinop_h9zq6PdA_sendMessage);
}

void Heavy_prog::cMsg_179PO3x4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mHAtRiKU, 0, m, &cDelay_mHAtRiKU_sendMessage);
}

void Heavy_prog::cBinop_S6IcxjoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mHAtRiKU, 2, m, &cDelay_mHAtRiKU_sendMessage);
}

void Heavy_prog::cBinop_aexeQE0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h9zq6PdA, HV_BINOP_MULTIPLY, 1, m, &cBinop_h9zq6PdA_sendMessage);
}

void Heavy_prog::cBinop_h9zq6PdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_S6IcxjoC_sendMessage);
}

void Heavy_prog::cVar_PUGtgsGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_hH5jvRLa_sendMessage);
  cSwitchcase_Sv1gi3Qp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_hH5jvRLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PUGtgsGg, 1, m, &cVar_PUGtgsGg_sendMessage);
}

void Heavy_prog::cSwitchcase_01NjLBNA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gu1DPECm, 0, m, &cSlice_gu1DPECm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DlmreFi6, 0, m, &cRandom_DlmreFi6_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_dfh0zNT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pZ0nqjGr_sendMessage);
}

void Heavy_prog::cUnop_pZ0nqjGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OjuF7G9C_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CLUUCjlL, HV_BINOP_MULTIPLY, 1, m, &cBinop_CLUUCjlL_sendMessage);
}

void Heavy_prog::cRandom_DlmreFi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_dfh0zNT3_sendMessage);
}

void Heavy_prog::cSlice_gu1DPECm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DlmreFi6, 1, m, &cRandom_DlmreFi6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_r9EqYQCe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_W9uX8I73, 0, m, &cSlice_W9uX8I73_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ohN1pQkX, 0, m, &cRandom_ohN1pQkX_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_mxuK7jhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_D7Jn5DpO_sendMessage);
}

void Heavy_prog::cUnop_D7Jn5DpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QlzQqWLo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LQjTK4yz_sendMessage);
}

void Heavy_prog::cRandom_ohN1pQkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.0f, 0, m, &cBinop_mxuK7jhK_sendMessage);
}

void Heavy_prog::cSlice_W9uX8I73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ohN1pQkX, 1, m, &cRandom_ohN1pQkX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_RVJngYva_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8rvlLtqA, 0, m, &cSlice_8rvlLtqA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NjCEMX4y, 0, m, &cRandom_NjCEMX4y_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_XQTsATFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_c90PVpRq_sendMessage);
}

void Heavy_prog::cUnop_c90PVpRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KTmhIyJl, 0, m, &cVar_KTmhIyJl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hGoc1iAt, 0, m, &cVar_hGoc1iAt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CLUUCjlL, HV_BINOP_MULTIPLY, 0, m, &cBinop_CLUUCjlL_sendMessage);
}

void Heavy_prog::cRandom_NjCEMX4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 220.0f, 0, m, &cBinop_XQTsATFJ_sendMessage);
}

void Heavy_prog::cSlice_8rvlLtqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NjCEMX4y, 1, m, &cRandom_NjCEMX4y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_68gCI6rh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ErRXNR4E, 1, m, &cVar_ErRXNR4E_sendMessage);
}

void Heavy_prog::cCast_P73rH3WE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_01NjLBNA_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_r9EqYQCe_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_RVJngYva_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_6nLWNYUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ErRXNR4E, 0, m, &cVar_ErRXNR4E_sendMessage);
}

void Heavy_prog::cBinop_M7Gw6xCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BdnQzHv2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_CLUUCjlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ADKL9mqo, 0, m, &cVar_ADKL9mqo_sendMessage);
}

void Heavy_prog::cReceive_OO736RiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CemfnnFo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RL8wx8Tm, 0, m, &cVar_RL8wx8Tm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PUGtgsGg, 0, m, &cVar_PUGtgsGg_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_prog::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14, Bf15, Bf16;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_line_f(&sLine_4437ONVn, VOf(Bf0));
    __hv_varread_f(&sVarf_DhRK9Ofo, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf7), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_phasor_k_f(&sPhasor_scGQfy2W, VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf2));
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf3), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_5RQ9kX34, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_phasor_k_f(&sPhasor_Rgm0L1rB, VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_tItzKjaA, VOf(Bf6));
    __hv_varread_f(&sVarf_CUwBJlgN, VOf(Bf9));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_phasor_f(&sPhasor_YvJE5CWg, VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf9), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_del1_f(&sDel1_Rji09wFV, VIf(Bf4), VOf(Bf5));
    __hv_lt_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_samphold_f(&sSamphold_fJfhpIGB, VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_line_f(&sLine_j0MqIaZh, VOf(Bf9));
    __hv_varread_f(&sVarf_7u4TlyMM, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf8));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf8), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf8), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf14), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf15), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf10), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf12), VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf15), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf8), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf4), VIf(Bf9), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));
    __hv_var_k_f(VOf(Bf0), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_var_k_f(VOf(Bf4), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf7), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf6), VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_prog::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_prog::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
