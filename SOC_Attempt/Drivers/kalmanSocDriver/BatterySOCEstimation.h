/*
 * File: BatterySOCEstimation.h
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

#ifndef BatterySOCEstimation_h_
#define BatterySOCEstimation_h_
#ifndef BatterySOCEstimation_COMMON_INCLUDES_
#define BatterySOCEstimation_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* BatterySOCEstimation_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>/SOC Estimator (Kalman Filter)' */
typedef struct {
  real_T Probe[2];                     /* '<S6>/Probe' */
  real_T Delay_DSTATE[2];              /* '<S5>/Delay' */
  real_T UnitDelayP_DSTATE[4];         /* '<S3>/Unit Delay - P' */
  boolean_T icLoad;                    /* '<S5>/Delay' */
} DW_CoreSubsys;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_CoreSubsys CoreSubsys[1];      /* '<Root>/SOC Estimator (Kalman Filter)' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: dV0_mat
   * Referenced by: '<S6>/2-D Lookup Table dV0'
   */
  real_T uDLookupTabledV0_tableData[21];

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table dV0'
   */
  real_T uDLookupTabledV0_bp01Data[7];

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table dV0'
   */
  real_T uDLookupTabledV0_bp02Data[3];

  /* Expression: R1_mat
   * Referenced by: '<S6>/2-D Lookup Table R1'
   */
  real_T uDLookupTableR1_tableData[21];

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table R1'
   */
  real_T uDLookupTableR1_bp01Data[7];

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table R1'
   */
  real_T uDLookupTableR1_bp02Data[3];

  /* Expression: C1_mat
   * Referenced by: '<S6>/2-D Lookup Table C1'
   */
  real_T uDLookupTableC1_tableData[21];

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table C1'
   */
  real_T uDLookupTableC1_bp01Data[7];

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table C1'
   */
  real_T uDLookupTableC1_bp02Data[3];

  /* Expression: Q
   * Referenced by: '<S7>/Constant'
   */
  real_T Constant_Value_n[4];

  /* Expression: V0_mat
   * Referenced by: '<S6>/2-D Lookup Table V0'
   */
  real_T uDLookupTableV0_tableData[21];

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table V0'
   */
  real_T uDLookupTableV0_bp01Data[7];

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table V0'
   */
  real_T uDLookupTableV0_bp02Data[3];

  /* Expression: R0_mat
   * Referenced by: '<S6>/2-D Lookup Table R0'
   */
  real_T uDLookupTableR0_tableData[21];

  /* Expression: SOC_vec
   * Referenced by: '<S6>/2-D Lookup Table R0'
   */
  real_T uDLookupTableR0_bp01Data[7];

  /* Expression: T_vec
   * Referenced by: '<S6>/2-D Lookup Table R0'
   */
  real_T uDLookupTableR0_bp02Data[3];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/2-D Lookup Table C1'
   *   '<S6>/2-D Lookup Table R0'
   *   '<S6>/2-D Lookup Table R1'
   *   '<S6>/2-D Lookup Table V0'
   *   '<S6>/2-D Lookup Table dV0'
   */
  uint32_T pooled3[2];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Current;                      /* '<Root>/Current' */
  real_T CellVoltage;                  /* '<Root>/CellVoltage' */
  real_T CellTemp;                     /* '<Root>/CellTemp' */
  real_T InitialSOC;                   /* '<Root>/InitialSOC' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern ConstP rtConstP;

/* Model entry point functions */
extern void BatterySOCEstimation_initialize(void);
extern void BatterySOCEstimation_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Conversion' : Eliminate redundant data type conversion
 * Block '<S12>/Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition3' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BatterySOCEstimation'
 * '<S1>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)'
 * '<S2>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter'
 * '<S3>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF'
 * '<S4>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Correction'
 * '<S5>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Delay - X'
 * '<S6>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Jacobian'
 * '<S7>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Prediction'
 * '<S8>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Correction/Data Type Conversion Inherited'
 * '<S9>'   : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Correction/Data Type Conversion Inherited1'
 * '<S10>'  : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Delay - X/Data Type Conversion Inherited'
 * '<S11>'  : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Jacobian/Data Type Conversion Inherited'
 * '<S12>'  : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Jacobian/Data Type Conversion Inherited1'
 * '<S13>'  : 'BatterySOCEstimation/SOC Estimator (Kalman Filter)/Kalman Filter/EKF/Jacobian/Data Type Conversion Inherited2'
 */
#endif                                 /* BatterySOCEstimation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
