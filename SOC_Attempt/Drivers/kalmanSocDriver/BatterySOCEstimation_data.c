/*
 * File: BatterySOCEstimation_data.c
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

/* Constant parameters (default storage) */
//ConstP rtConstP = {
//  /* Expression: dV0_mat
//   * Referenced by: '<S6>/2-D Lookup Table dV0'
//   */
//  { 0.0, 0.59999999999999609, 0.46666666666666856, 0.35999999999999943,
//    0.80000000000000071, 1.0666666666666675, 1.2000000000000013, 0.0,
//    0.6999999999999984, 0.40000000000000036, 0.32000000000000028,
//    0.88000000000000078, 0.99999999999999922, 1.1000000000000034, 0.0,
//    0.50000000000000266, 0.53333333333333388, 0.32000000000000028,
//    0.879999999999999, 0.933333333333334, 1.1000000000000034 },
//
//  /* Expression: SOC_vec
//   * Referenced by: '<S6>/2-D Lookup Table dV0'
//   */
//  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },
//
//  /* Expression: T_vec
//   * Referenced by: '<S6>/2-D Lookup Table dV0'
//   */
//  { 278.0, 293.0, 313.0 },
//
//  /* Expression: R1_mat
//   * Referenced by: '<S6>/2-D Lookup Table R1'
//   */
//  { 0.0109, 0.0069, 0.0047, 0.0034, 0.0033, 0.0033, 0.0028, 0.0029, 0.0024,
//    0.0026, 0.0016, 0.0023, 0.0018, 0.0017, 0.0013, 0.0012, 0.0013, 0.001,
//    0.0014, 0.0011, 0.0011 },
//
//  /* Expression: SOC_vec
//   * Referenced by: '<S6>/2-D Lookup Table R1'
//   */
//  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },
//
//  /* Expression: T_vec
//   * Referenced by: '<S6>/2-D Lookup Table R1'
//   */
//  { 278.0, 293.0, 313.0 },
//
//  /* Expression: C1_mat
//   * Referenced by: '<S6>/2-D Lookup Table C1'
//   */
//  { 1834.8623853211009, 4492.753623188406, 23191.489361702126,
//    10588.235294117647, 17878.78787878788, 12121.212121212122, 8928.57142857143,
//    12413.793103448277, 18750.0, 40384.615384615383, 18125.0, 33478.260869565216,
//    18333.333333333332, 22941.176470588238, 30000.0, 32500.000000000004,
//    46923.076923076922, 26000.0, 47857.142857142855, 26363.63636363636, 30000.0
//  },
//
//  /* Expression: SOC_vec
//   * Referenced by: '<S6>/2-D Lookup Table C1'
//   */
//  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },
//
//  /* Expression: T_vec
//   * Referenced by: '<S6>/2-D Lookup Table C1'
//   */
//  { 278.0, 293.0, 313.0 },
//
//  /* Expression: Q
//   * Referenced by: '<S7>/Constant'
//   */
//  { 0.0001, 0.0, 0.0, 0.0001 },
//
//  /* Expression: V0_mat
//   * Referenced by: '<S6>/2-D Lookup Table V0'
//   */
//  { 3.49, 3.55, 3.62, 3.71, 3.91, 4.07, 4.19, 3.5, 3.57, 3.63, 3.71, 3.93, 4.08,
//    4.19, 3.51, 3.56, 3.64, 3.72, 3.94, 4.08, 4.19 },
//
//  /* Expression: SOC_vec
//   * Referenced by: '<S6>/2-D Lookup Table V0'
//   */
//  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },
//
//  /* Expression: T_vec
//   * Referenced by: '<S6>/2-D Lookup Table V0'
//   */
//  { 278.0, 293.0, 313.0 },
//
//  /* Expression: R0_mat
//   * Referenced by: '<S6>/2-D Lookup Table R0'
//   */
//  { 0.0117, 0.011, 0.0114, 0.0107, 0.0107, 0.0113, 0.0116, 0.0085, 0.0085,
//    0.0087, 0.0082, 0.0083, 0.0085, 0.0085, 0.009, 0.009, 0.0092, 0.0088, 0.0091,
//    0.0089, 0.0089 },
//
//  /* Expression: SOC_vec
//   * Referenced by: '<S6>/2-D Lookup Table R0'
//   */
//  { 0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0 },
//
//  /* Expression: T_vec
//   * Referenced by: '<S6>/2-D Lookup Table R0'
//   */
//  { 278.0, 293.0, 313.0 },
//
//  /* Pooled Parameter (Expression: )
//   * Referenced by:
//   *   '<S6>/2-D Lookup Table C1'
//   *   '<S6>/2-D Lookup Table R0'
//   *   '<S6>/2-D Lookup Table R1'
//   *   '<S6>/2-D Lookup Table V0'
//   *   '<S6>/2-D Lookup Table dV0'
//   */
//  { 6U, 2U }
//};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
