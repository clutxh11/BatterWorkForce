/*
 * File: BatterySOCEstimation.c
 *
 * Code generated for Simulink model 'BatterySOCEstimation'.
 *
 * Model version                  : 13.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Jul 10 19:13:26 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "BatterySOCEstimation.h"
#include "BatterySOCEstimation_data.c"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

ConstP rtConstP = {
  /* Expression: dV0_mat
   * Referenced by: '<S6>/2-D Lookup Table dV0'
   */
  { 0.0, 0.59999999999999609, 0.46666666666666856, 0.35999999999999943,
    0.80000000000000071, 1.0666666666666675, 1.2000000000000013, 0.0,
    0.6999999999999984, 0.40000000000000036, 0.32000000000000028,
    0.88000000000000078, 0.99999999999999922, 1.1000000000000034, 0.0,
    0.50000000000000266, 0.53333333333333388, 0.32000000000000028,
    0.879999999999999, 0.933333333333334, 1.1000000000000034 },

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table dV0'
   */
  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table dV0'
   */
  { 278.0, 293.0, 313.0 },

  /* Expression: R1_mat
   * Referenced by: '<S6>/2-D Lookup Table R1'
   */
  { 0.0109, 0.0069, 0.0047, 0.0034, 0.0033, 0.0033, 0.0028, 0.0029, 0.0024,
    0.0026, 0.0016, 0.0023, 0.0018, 0.0017, 0.0013, 0.0012, 0.0013, 0.001,
    0.0014, 0.0011, 0.0011 },

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table R1'
   */
  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table R1'
   */
  { 278.0, 293.0, 313.0 },

  /* Expression: C1_mat
   * Referenced by: '<S6>/2-D Lookup Table C1'
   */
  { 1834.8623853211009, 4492.753623188406, 23191.489361702126,
    10588.235294117647, 17878.78787878788, 12121.212121212122, 8928.57142857143,
    12413.793103448277, 18750.0, 40384.615384615383, 18125.0, 33478.260869565216,
    18333.333333333332, 22941.176470588238, 30000.0, 32500.000000000004,
    46923.076923076922, 26000.0, 47857.142857142855, 26363.63636363636, 30000.0
  },

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table C1'
   */
  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table C1'
   */
  { 278.0, 293.0, 313.0 },

  /* Expression: Q
   * Referenced by: '<S7>/Constant'
   */
  { 0.0001, 0.0, 0.0, 0.0001 },

  /* Expression: V0_mat
   * Referenced by: '<S6>/2-D Lookup Table V0'
   */
  { 3.49, 3.55, 3.62, 3.71, 3.91, 4.07, 4.19, 3.5, 3.57, 3.63, 3.71, 3.93, 4.08,
    4.19, 3.51, 3.56, 3.64, 3.72, 3.94, 4.08, 4.19 },

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table V0'
   */
  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table V0'
   */
  { 278.0, 293.0, 313.0 },

  /* Expression: R0_mat
   * Referenced by: '<S6>/2-D Lookup Table R0'
   */
  { 0.0117, 0.011, 0.0114, 0.0107, 0.0107, 0.0113, 0.0116, 0.0085, 0.0085,
    0.0087, 0.0082, 0.0083, 0.0085, 0.0085, 0.009, 0.009, 0.0092, 0.0088, 0.0091,
    0.0089, 0.0089 },

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table R0'
   */
  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table R0'
   */
  { 278.0, 293.0, 313.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/2-D Lookup Table C1'
   *   '<S6>/2-D Lookup Table R0'
   *   '<S6>/2-D Lookup Table R1'
   *   '<S6>/2-D Lookup Table V0'
   *   '<S6>/2-D Lookup Table dV0'
   */
  { 6U, 2U }
};
static real_T look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
static real_T look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

/* Model step function */
void BatterySOCEstimation_step(void)
{
  real_T rtb_Assignment[4];
  real_T rtb_Sum1[4];
  real_T tmp[4];
  real_T rtb_Product3[2];
  real_T rtb_TmpSignalConversionAtProduc[2];
  real_T UnitDelayP_DSTATE;
  real_T rtb_Assignment_0;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_i;
  real_T rtb_MathFunction;
  real_T rtb_Sum_g_idx_0;
  real_T rtb_Sum_p;
  real_T rtb_TmpSignalConversionAtProd_0;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  int32_T i;
  int32_T rtb_Assignment_1;

  /* Outputs for Iterator SubSystem: '<Root>/SOC Estimator (Kalman Filter)' incorporates:
   *  ForEach: '<S1>/For Each'
   */
  /* Delay: '<S5>/Delay' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Inport: '<Root>/InitialSOC'
   *  SignalConversion generated from: '<S5>/Delay'
   */
  if (rtDW.CoreSubsys[0].icLoad) {
    rtDW.CoreSubsys[0].Delay_DSTATE[0] = rtU.InitialSOC;
    rtDW.CoreSubsys[0].Delay_DSTATE[1] = 0.0;
  }

  /* Lookup_n-D: '<S6>/2-D Lookup Table dV0' incorporates:
   *  Delay: '<S5>/Delay'
   *  Inport: '<Root>/CellTemp'
   */
  tmp_3 = look2_binlx(rtDW.CoreSubsys[0].Delay_DSTATE[0], rtU.CellTemp,
                      rtConstP.uDLookupTabledV0_bp01Data,
                      rtConstP.uDLookupTabledV0_bp02Data,
                      rtConstP.uDLookupTabledV0_tableData, rtConstP.pooled3, 7U);

  /* SignalConversion generated from: '<S6>/Transpose1' incorporates:
   *  Constant: '<S6>/Constant4'
   */
  rtb_Product3[0] = tmp_3;
  rtb_Product3[1] = -1.0;

  /* Lookup_n-D: '<S6>/2-D Lookup Table R1' incorporates:
   *  Delay: '<S5>/Delay'
   *  Inport: '<Root>/CellTemp'
   */
  rtb_ImpAsg_InsertedFor_SOC_at_i = look2_binlx(rtDW.CoreSubsys[0].Delay_DSTATE
    [0], rtU.CellTemp, rtConstP.uDLookupTableR1_bp01Data,
    rtConstP.uDLookupTableR1_bp02Data, rtConstP.uDLookupTableR1_tableData,
    rtConstP.pooled3, 7U);

  /* Math: '<S6>/Math Function' incorporates:
   *  Delay: '<S5>/Delay'
   *  Gain: '<S6>/-Ts'
   *  Inport: '<Root>/CellTemp'
   *  Lookup_n-D: '<S6>/2-D Lookup Table C1'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product2'
   *
   * About '<S6>/Math Function':
   *  Operator: exp
   */
  rtb_MathFunction = exp(1.0 / (rtb_ImpAsg_InsertedFor_SOC_at_i * look2_binlx
    (rtDW.CoreSubsys[0].Delay_DSTATE[0], rtU.CellTemp,
     rtConstP.uDLookupTableC1_bp01Data, rtConstP.uDLookupTableC1_bp02Data,
     rtConstP.uDLookupTableC1_tableData, rtConstP.pooled3, 7U)) *
    -rtDW.CoreSubsys[0].Probe[0]);

  /* SignalConversion generated from: '<S6>/Assignment' incorporates:
   *  Assignment: '<S6>/Assignment'
   *  Constant: '<S6>/Constant'
   */
  rtb_Assignment[0] = 1.0;
  rtb_Assignment[1] = 0.0;
  rtb_Assignment[2] = 0.0;

  /* Assignment: '<S6>/Assignment' */
  rtb_Assignment[3] = rtb_MathFunction;

  /* Product: '<S7>/Product2' incorporates:
   *  Assignment: '<S6>/Assignment'
   *  Math: '<S7>/Transpose'
   *  UnitDelay: '<S3>/Unit Delay - P'
   */
  for (i = 0; i < 2; i++) {
    rtb_Sum_p = rtDW.CoreSubsys[0].UnitDelayP_DSTATE[i + 2];
    UnitDelayP_DSTATE = rtDW.CoreSubsys[0].UnitDelayP_DSTATE[i];
    tmp[i] = rtb_Sum_p * 0.0 + UnitDelayP_DSTATE;
    tmp[i + 2] = rtb_Sum_p * rtb_MathFunction + UnitDelayP_DSTATE * 0.0;
  }

  /* Product: '<S4>/Product2' */
  rtb_Sum_g_idx_0 = 0.0;

  /* Product: '<S7>/Product2' */
  rtb_Sum_p = tmp[1];
  tmp_0 = tmp[0];
  tmp_1 = tmp[3];
  tmp_2 = tmp[2];
  for (i = 0; i < 2; i++) {
    /* Sum: '<S7>/Sum1' incorporates:
     *  Assignment: '<S6>/Assignment'
     *  Constant: '<S7>/Constant'
     *  Product: '<S7>/Product2'
     */
    rtb_Assignment_0 = rtb_Assignment[i + 2];
    rtb_Assignment_1 = (int32_T)rtb_Assignment[i];
    UnitDelayP_DSTATE = (rtb_Assignment_0 * rtb_Sum_p + (real_T)rtb_Assignment_1
                         * tmp_0) + rtConstP.Constant_Value_n[i];
    rtb_Sum1[i] = UnitDelayP_DSTATE;

    /* Product: '<S4>/Product2' incorporates:
     *  Lookup_n-D: '<S6>/2-D Lookup Table dV0'
     *  Product: '<S4>/Product'
     */
    rtb_TmpSignalConversionAtProd_0 = UnitDelayP_DSTATE * tmp_3;

    /* Sum: '<S7>/Sum1' incorporates:
     *  Constant: '<S7>/Constant'
     *  Product: '<S7>/Product2'
     */
    UnitDelayP_DSTATE = (rtb_Assignment_0 * tmp_1 + (real_T)rtb_Assignment_1 *
                         tmp_2) + rtConstP.Constant_Value_n[i + 2];
    rtb_Sum1[i + 2] = UnitDelayP_DSTATE;

    /* Product: '<S4>/Product2' incorporates:
     *  Product: '<S4>/Product'
     *  Product: '<S4>/Product3'
     */
    rtb_TmpSignalConversionAtProd_0 -= UnitDelayP_DSTATE;
    rtb_TmpSignalConversionAtProduc[i] = rtb_TmpSignalConversionAtProd_0;
    rtb_Sum_g_idx_0 += rtb_Product3[i] * rtb_TmpSignalConversionAtProd_0;
  }

  /* Product: '<S4>/Divide' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Product: '<S4>/Product2'
   *  Sum: '<S4>/Sum2'
   */
  rtb_Sum_p = 1.0 / (rtb_Sum_g_idx_0 + 0.7);

  /* Product: '<S4>/Product1' incorporates:
   *  Product: '<S4>/Product'
   *  SignalConversion generated from: '<S7>/Product1'
   */
  rtb_TmpSignalConversionAtProduc[0] *= rtb_Sum_p;
  rtb_TmpSignalConversionAtProduc[1] *= rtb_Sum_p;

  /* Sum: '<S3>/Sum' incorporates:
   *  Delay: '<S5>/Delay'
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/CellTemp'
   *  Inport: '<Root>/CellVoltage'
   *  Inport: '<Root>/Current'
   *  Lookup_n-D: '<S6>/2-D Lookup Table R0'
   *  Lookup_n-D: '<S6>/2-D Lookup Table V0'
   *  Product: '<S6>/Product6'
   *  Sum: '<S6>/Sum2'
   */
  rtb_Sum_p = rtU.CellVoltage - ((look2_binlx(rtDW.CoreSubsys[0].Delay_DSTATE[0],
    rtU.CellTemp, rtConstP.uDLookupTableV0_bp01Data,
    rtConstP.uDLookupTableV0_bp02Data, rtConstP.uDLookupTableV0_tableData,
    rtConstP.pooled3, 7U) - look2_binlx(rtDW.CoreSubsys[0].Delay_DSTATE[0],
    rtU.CellTemp, rtConstP.uDLookupTableR0_bp01Data,
    rtConstP.uDLookupTableR0_bp02Data, rtConstP.uDLookupTableR0_tableData,
    rtConstP.pooled3, 7U) * -rtU.Current) - rtDW.CoreSubsys[0].Delay_DSTATE[1]);

  /* Sum: '<S4>/Sum' incorporates:
   *  Delay: '<S5>/Delay'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S6>/-Ts'
   *  Gain: '<S6>/Gain'
   *  Inport: '<Root>/Current'
   *  Product: '<S4>/Product3'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  SignalConversion generated from: '<S7>/Product1'
   *  Sum: '<S7>/Sum'
   */
  rtb_Sum_g_idx_0 = ((rtDW.CoreSubsys[0].Delay_DSTATE[1] * 0.0 +
                      rtDW.CoreSubsys[0].Delay_DSTATE[0]) + 1.02880658436214E-5 *
                     -rtDW.CoreSubsys[0].Probe[0] * -rtU.Current) +
    rtb_TmpSignalConversionAtProduc[0] * rtb_Sum_p;

  /* Product: '<S7>/Product' incorporates:
   *  Assignment: '<S6>/Assignment'
   *  Delay: '<S5>/Delay'
   */
  rtb_Assignment_0 = rtDW.CoreSubsys[0].Delay_DSTATE[0] * 0.0 + rtDW.CoreSubsys
    [0].Delay_DSTATE[1] * rtb_MathFunction;

  /* Update for Delay: '<S5>/Delay' */
  rtDW.CoreSubsys[0].icLoad = false;
  rtDW.CoreSubsys[0].Delay_DSTATE[0] = rtb_Sum_g_idx_0;

  /* Sum: '<S4>/Sum3' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Product: '<S4>/Product4'
   *  SignalConversion generated from: '<S7>/Product1'
   */
  tmp[0] = 1.0 - rtb_TmpSignalConversionAtProduc[0] * tmp_3;
  tmp[1] = 0.0 - tmp_3 * rtb_TmpSignalConversionAtProduc[1];

  /* Update for Delay: '<S5>/Delay' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/Current'
   *  Product: '<S4>/Product3'
   *  Product: '<S6>/Product4'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  SignalConversion generated from: '<S7>/Product1'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S7>/Sum'
   */
  rtDW.CoreSubsys[0].Delay_DSTATE[1] = ((1.0 - rtb_MathFunction) *
    rtb_ImpAsg_InsertedFor_SOC_at_i * -rtU.Current + rtb_Assignment_0) +
    rtb_TmpSignalConversionAtProduc[1] * rtb_Sum_p;

  /* Sum: '<S4>/Sum3' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Product: '<S4>/Product4'
   *  SignalConversion generated from: '<S7>/Product1'
   */
  tmp[2] = 0.0 - (-rtb_TmpSignalConversionAtProduc[0]);
  tmp[3] = 1.0 - (-rtb_TmpSignalConversionAtProduc[1]);

  /* Product: '<S4>/Product5' incorporates:
   *  Sum: '<S7>/Sum1'
   */
  UnitDelayP_DSTATE = rtb_Sum1[0];
  rtb_ImpAsg_InsertedFor_SOC_at_i = rtb_Sum1[1];
  rtb_MathFunction = rtb_Sum1[2];
  rtb_Assignment_0 = rtb_Sum1[3];

  /* Update for UnitDelay: '<S3>/Unit Delay - P' */
  for (i = 0; i < 2; i++) {
    /* Product: '<S4>/Product5' */
    tmp_3 = tmp[i];
    rtb_Sum_p = tmp[i + 2];
    rtDW.CoreSubsys[0].UnitDelayP_DSTATE[i] = rtb_Sum_p *
      rtb_ImpAsg_InsertedFor_SOC_at_i + tmp_3 * UnitDelayP_DSTATE;
    rtDW.CoreSubsys[0].UnitDelayP_DSTATE[i + 2] = rtb_Sum_p * rtb_Assignment_0 +
      tmp_3 * rtb_MathFunction;
  }

  /* End of Update for UnitDelay: '<S3>/Unit Delay - P' */

  /* Outport: '<Root>/Out1' incorporates:
   *  ForEachSliceAssignment generated from: '<S1>/SOC'
   */
  rtY.Out1 = rtb_Sum_g_idx_0;

  /* End of Outputs for SubSystem: '<Root>/SOC Estimator (Kalman Filter)' */
}

/* Model initialize function */
void BatterySOCEstimation_initialize(void)
{
  /* SystemInitialize for Iterator SubSystem: '<Root>/SOC Estimator (Kalman Filter)' */
  /* Start for Probe: '<S6>/Probe' */
  rtDW.CoreSubsys[0].Probe[0] = 1.0;
  rtDW.CoreSubsys[0].Probe[1] = 0.0;

  /* InitializeConditions for Delay: '<S5>/Delay' */
  rtDW.CoreSubsys[0].icLoad = true;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay - P' */
  rtDW.CoreSubsys[0].UnitDelayP_DSTATE[0] = 1.0E-5;
  rtDW.CoreSubsys[0].UnitDelayP_DSTATE[1] = 0.0;
  rtDW.CoreSubsys[0].UnitDelayP_DSTATE[2] = 0.0;
  rtDW.CoreSubsys[0].UnitDelayP_DSTATE[3] = 1.0;

  /* End of SystemInitialize for SubSystem: '<Root>/SOC Estimator (Kalman Filter)' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
