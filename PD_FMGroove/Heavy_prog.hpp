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

#ifndef _HEAVY_CONTEXT_PROG_HPP_
#define _HEAVY_CONTEXT_PROG_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlDelay.h"
#include "HvControlVar.h"
#include "HvSignalVar.h"
#include "HvControlRandom.h"
#include "HvControlSlice.h"
#include "HvControlSystem.h"
#include "HvSignalDel1.h"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvControlUnop.h"
#include "HvMath.h"
#include "HvControlCast.h"
#include "HvSignalSamphold.h"
#include "HvSignalLine.h"

class Heavy_prog : public HeavyContext {

 public:
  Heavy_prog(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_prog();

  const char *getName() override { return "prog"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_ADKL9mqo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hGoc1iAt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KTmhIyJl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1iqkRX5d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AsVu0ThG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GwIbW466_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rmlfjjx6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rn3L9dMB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DYxKkUGA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HjLvXFgq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wa0Px0MI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aonSVFEV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_OjuF7G9C_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_xc9ihZZ7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KjQ2oqxs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Z8mQvphR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_G5G7ykd3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KVTopYo3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ypzulLQW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9fezAphZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nFQTiStw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Tx9kBLzb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kKg58wPG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_epsq2aN6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KH3hL8kx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Bnd32ijC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zTGEY5xi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JObKqvpp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_esTSk7ab_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ialxwo6T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WAg4VJSa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dzitaD4Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5XK6cLpc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ErRXNR4E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BdnQzHv2_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_ui8QndUZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LQjTK4yz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QlzQqWLo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ViBtgmvt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mapQiBpJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Sv1gi3Qp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_mHAtRiKU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gV8zdsjj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CemfnnFo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_KYdArjVW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RL8wx8Tm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_179PO3x4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S6IcxjoC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aexeQE0l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h9zq6PdA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PUGtgsGg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hH5jvRLa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_01NjLBNA_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_dfh0zNT3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_pZ0nqjGr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_DlmreFi6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gu1DPECm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_r9EqYQCe_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_mxuK7jhK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_D7Jn5DpO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_ohN1pQkX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_W9uX8I73_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_RVJngYva_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_XQTsATFJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_c90PVpRq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_NjCEMX4y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8rvlLtqA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_68gCI6rh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_P73rH3WE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6nLWNYUI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M7Gw6xCA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CLUUCjlL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_OO736RiY_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_4437ONVn;
  SignalPhasor sPhasor_scGQfy2W;
  SignalLine sLine_5RQ9kX34;
  SignalPhasor sPhasor_Rgm0L1rB;
  SignalPhasor sPhasor_YvJE5CWg;
  SignalDel1 sDel1_Rji09wFV;
  SignalSamphold sSamphold_fJfhpIGB;
  SignalLine sLine_j0MqIaZh;
  ControlVar cVar_ADKL9mqo;
  ControlVar cVar_hGoc1iAt;
  ControlVar cVar_KTmhIyJl;
  ControlBinop cBinop_Wa0Px0MI;
  SignalVarf sVarf_7u4TlyMM;
  ControlBinop cBinop_esTSk7ab;
  SignalVarf sVarf_DhRK9Ofo;
  ControlVar cVar_ErRXNR4E;
  ControlDelay cDelay_mHAtRiKU;
  ControlVar cVar_RL8wx8Tm;
  ControlBinop cBinop_S6IcxjoC;
  ControlBinop cBinop_aexeQE0l;
  ControlBinop cBinop_h9zq6PdA;
  ControlVar cVar_PUGtgsGg;
  ControlBinop cBinop_hH5jvRLa;
  ControlBinop cBinop_dfh0zNT3;
  ControlRandom cRandom_DlmreFi6;
  ControlSlice cSlice_gu1DPECm;
  ControlBinop cBinop_mxuK7jhK;
  ControlRandom cRandom_ohN1pQkX;
  ControlSlice cSlice_W9uX8I73;
  ControlBinop cBinop_XQTsATFJ;
  ControlRandom cRandom_NjCEMX4y;
  ControlSlice cSlice_8rvlLtqA;
  ControlBinop cBinop_68gCI6rh;
  ControlBinop cBinop_CLUUCjlL;
  SignalVarf sVarf_tItzKjaA;
  SignalVarf sVarf_CUwBJlgN;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
