/*
 * multichanel_framebased.c
 *
 * Code generation for model "multichanel_framebased".
 *
 * Model version              : 1.7
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Sat Feb 28 19:31:38 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "multichanel_framebased.h"
#include <math.h>
#include "rtwtypes.h"
#include <stddef.h>
#include <emmintrin.h>
#include <string.h>
#include "multichanel_framebased_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_multichanel_framebased_T multichanel_framebased_B;

/* Block states (default storage) */
DW_multichanel_framebased_T multichanel_framebased_DW;

/* Real-time model */
static RT_MODEL_multichanel_framebas_T multichanel_framebased_M_;
RT_MODEL_multichanel_framebas_T *const multichanel_framebased_M =
  &multichanel_framebased_M_;

/* Model step function */
void multichanel_framebased_step(void)
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  __m128d tmp_2;
  real_T updateVal;
  int32_T i;
  char_T *sErr;

  /* S-Function (sdspwmmfi2): '<Root>/From Multimedia File' incorporates:
   *  Concatenate: '<Root>/Matrix Concatenate'
   */
  sErr = GetErrorBuffer(&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U]);
  LibOutputs_FromMMFile(&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U],
                        GetNullPointer(), &multichanel_framebased_B.xn[0],
                        GetNullPointer(), GetNullPointer(), GetNullPointer());
  if (*sErr != 0) {
    rtmSetErrorStatus(multichanel_framebased_M, sErr);
    rtmSetStopRequested(multichanel_framebased_M, 1);
  }

  /* End of S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

  /* S-Function (sdspchirp): '<Root>/Chirp' */
  /* DSP System Toolbox Chirp (sdspchirp) - '<Root>/Chirp' */
  /* Bidirectional Linear  */
  {
    real_T *y = &multichanel_framebased_B.xn[500];
    real_T instantPhase = 0.0;
    const int_T samplesPerFrame = 500;
    int_T chirpLoopCount;
    for (chirpLoopCount=0; chirpLoopCount<samplesPerFrame; chirpLoopCount++) {
      /* We are in Bidirectional Linear mode */
      instantPhase = (multichanel_framebased_DW.Chirp_SWEEP_DIRECTION == 0) ?
        multichanel_framebased_DW.Chirp_MIN_FREQ *
        multichanel_framebased_DW.Chirp_CURRENT_STEP +
        multichanel_framebased_DW.Chirp_BETA * pow
        (multichanel_framebased_DW.Chirp_CURRENT_STEP, 2) / 2.0 :
        multichanel_framebased_DW.Chirp_PERIOD_THETA -
        multichanel_framebased_DW.Chirp_MIN_FREQ *
        (multichanel_framebased_P.Chirp_Tsweep -
         multichanel_framebased_DW.Chirp_CURRENT_STEP) -
        multichanel_framebased_DW.Chirp_BETA * pow
        ((multichanel_framebased_P.Chirp_Tsweep -
          multichanel_framebased_DW.Chirp_CURRENT_STEP), 2) / 2.0;
      instantPhase -= (int_T)instantPhase;
      *y++ = cos(DSP_TWO_PI * (instantPhase +
                  multichanel_framebased_DW.Chirp_ACC_PHASE) +
                 multichanel_framebased_P.Chirp_phase);
      multichanel_framebased_DW.Chirp_CURRENT_STEP += 0.000125;/* Go to next time step */
      if (multichanel_framebased_DW.Chirp_CURRENT_STEP >
          (multichanel_framebased_P.Chirp_Tsweep + DBL_EPSILON)) {
        multichanel_framebased_DW.Chirp_CURRENT_STEP =
          multichanel_framebased_DW.Chirp_CURRENT_STEP -
          multichanel_framebased_P.Chirp_Tsweep;
        multichanel_framebased_DW.Chirp_ACC_PHASE += instantPhase;
        if (multichanel_framebased_DW.Chirp_ACC_PHASE > 1.0) {
          multichanel_framebased_DW.Chirp_ACC_PHASE -= floor
            (multichanel_framebased_DW.Chirp_ACC_PHASE);
        }

        /* Reverse direction of sweep */
        multichanel_framebased_DW.Chirp_SWEEP_DIRECTION =
          !multichanel_framebased_DW.Chirp_SWEEP_DIRECTION;
      }
    }
  }

  /* S-Function (sdspsine2): '<Root>/Sine Wave' incorporates:
   *  Concatenate: '<Root>/Matrix Concatenate'
   */
  updateVal = multichanel_framebased_P.SineWave_Frequency *
    0.00078539816339744833;
  for (i = 0; i < 500; i++) {
    multichanel_framebased_B.xn[i + 1000] =
      multichanel_framebased_P.SineWave_Amplitude * sin
      (multichanel_framebased_DW.SineWave_AccFreqNorm);

    /* Update accumulated normalized freq value
       for next sample.  Keep in range [0 2*pi) */
    multichanel_framebased_DW.SineWave_AccFreqNorm += updateVal;
    if (multichanel_framebased_DW.SineWave_AccFreqNorm >= 6.2831853071795862) {
      multichanel_framebased_DW.SineWave_AccFreqNorm -= 6.2831853071795862;
    } else if (multichanel_framebased_DW.SineWave_AccFreqNorm < 0.0) {
      multichanel_framebased_DW.SineWave_AccFreqNorm += 6.2831853071795862;
    }
  }

  /* End of S-Function (sdspsine2): '<Root>/Sine Wave' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Concatenate: '<Root>/Matrix Concatenate'
   */
  for (i = 0; i <= 1498; i += 2) {
    tmp_2 = _mm_loadu_pd(&multichanel_framebased_B.xn[i]);
    _mm_storeu_pd(&multichanel_framebased_B.Gain[i], _mm_mul_pd(_mm_set1_pd
      (multichanel_framebased_P.Gain_Gain), tmp_2));
  }

  /* End of Gain: '<Root>/Gain' */
  for (i = 0; i < 3; i++) {
    /* UnitDelay: '<Root>/Unit Delay' incorporates:
     *  Concatenate: '<Root>/Matrix Concatenate'
     */
    multichanel_framebased_B.prevx[500 * i] =
      multichanel_framebased_DW.UnitDelay_DSTATE[i];
    memcpy(&multichanel_framebased_B.prevx[i * 500 + 1],
           &multichanel_framebased_B.xn[i * 500], 499U * sizeof(real_T));

    /* UnitDelay: '<Root>/Unit Delay2' */
    multichanel_framebased_B.prevprevx[500 * i] =
      multichanel_framebased_DW.UnitDelay2_DSTATE[i];
  }

  /* UnitDelay: '<Root>/Unit Delay3' incorporates:
   *  Sum: '<Root>/Add'
   */
  multichanel_framebased_B.yn[0] = multichanel_framebased_DW.UnitDelay3_DSTATE[0];
  multichanel_framebased_B.yn[500] =
    multichanel_framebased_DW.UnitDelay3_DSTATE[1];
  multichanel_framebased_B.yn[1000] =
    multichanel_framebased_DW.UnitDelay3_DSTATE[2];
  for (i = 0; i < 499; i++) {
    /* UnitDelay: '<Root>/Unit Delay2' incorporates:
     *  UnitDelay: '<Root>/Unit Delay'
     */
    multichanel_framebased_B.prevprevx[i + 1] = multichanel_framebased_B.prevx[i];
    multichanel_framebased_B.prevprevx[i + 501] =
      multichanel_framebased_B.prevx[i + 500];
    multichanel_framebased_B.prevprevx[i + 1001] =
      multichanel_framebased_B.prevx[i + 1000];

    /* UnitDelay: '<Root>/Unit Delay3' incorporates:
     *  Sum: '<Root>/Add'
     *  UnitDelay: '<Root>/Unit Delay2'
     */
    multichanel_framebased_B.yn[i + 1] = multichanel_framebased_B.prevprevx[i];
    multichanel_framebased_B.yn[i + 501] = multichanel_framebased_B.prevprevx[i
      + 500];
    multichanel_framebased_B.yn[i + 1001] = multichanel_framebased_B.prevprevx[i
      + 1000];
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   */
  for (i = 0; i <= 1498; i += 2) {
    /* Gain: '<Root>/Gain1' incorporates:
     *  Gain: '<Root>/Gain'
     *  Sum: '<Root>/Add'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    tmp_2 = _mm_loadu_pd(&multichanel_framebased_B.prevx[i]);
    tmp = _mm_loadu_pd(&multichanel_framebased_B.Gain[i]);

    /* Gain: '<Root>/Gain2' incorporates:
     *  Gain: '<Root>/Gain'
     *  Sum: '<Root>/Add'
     *  UnitDelay: '<Root>/Unit Delay2'
     */
    tmp_0 = _mm_loadu_pd(&multichanel_framebased_B.prevprevx[i]);

    /* Gain: '<Root>/Gain3' incorporates:
     *  Gain: '<Root>/Gain'
     *  Sum: '<Root>/Add'
     */
    tmp_1 = _mm_loadu_pd(&multichanel_framebased_B.yn[i]);
    _mm_storeu_pd(&multichanel_framebased_B.yn[i], _mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_mul_pd(_mm_set1_pd(multichanel_framebased_P.Gain1_Gain),
      tmp_2), tmp), _mm_mul_pd(_mm_set1_pd(multichanel_framebased_P.Gain2_Gain),
      tmp_0)), _mm_mul_pd(_mm_set1_pd(multichanel_framebased_P.Gain3_Gain),
                          tmp_1)));
  }

  /* End of Sum: '<Root>/Add' */
  for (i = 0; i < 500; i++) {
    /* Selector: '<Root>/Selector' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Add'
     */
    multichanel_framebased_B.Selector[i] = multichanel_framebased_B.yn[((int32_T)
      multichanel_framebased_P.Constant_Value - 1) * 500 + i];
  }

  /* S-Function (saudioToAudioDevice): '<Root>/Audio Device Writer' incorporates:
   *  Selector: '<Root>/Selector'
   */
  sErr = GetErrorBuffer
    (&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[0U]);
  LibUpdate_Audio(&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[0U],
                  &multichanel_framebased_B.Selector[0U], 0, 500, 0U);
  if (*sErr != 0) {
    rtmSetErrorStatus(multichanel_framebased_M, sErr);
    rtmSetStopRequested(multichanel_framebased_M, 1);
  }

  /* End of S-Function (saudioToAudioDevice): '<Root>/Audio Device Writer' */
  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Concatenate: '<Root>/Matrix Concatenate'
   */
  multichanel_framebased_DW.UnitDelay_DSTATE[0] = multichanel_framebased_B.xn
    [499];

  /* Update for UnitDelay: '<Root>/Unit Delay2' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  multichanel_framebased_DW.UnitDelay2_DSTATE[0] =
    multichanel_framebased_B.prevx[499];

  /* Update for UnitDelay: '<Root>/Unit Delay3' incorporates:
   *  UnitDelay: '<Root>/Unit Delay2'
   */
  multichanel_framebased_DW.UnitDelay3_DSTATE[0] =
    multichanel_framebased_B.prevprevx[499];

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Concatenate: '<Root>/Matrix Concatenate'
   */
  multichanel_framebased_DW.UnitDelay_DSTATE[1] = multichanel_framebased_B.xn
    [999];

  /* Update for UnitDelay: '<Root>/Unit Delay2' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  multichanel_framebased_DW.UnitDelay2_DSTATE[1] =
    multichanel_framebased_B.prevx[999];

  /* Update for UnitDelay: '<Root>/Unit Delay3' incorporates:
   *  UnitDelay: '<Root>/Unit Delay2'
   */
  multichanel_framebased_DW.UnitDelay3_DSTATE[1] =
    multichanel_framebased_B.prevprevx[999];

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Concatenate: '<Root>/Matrix Concatenate'
   */
  multichanel_framebased_DW.UnitDelay_DSTATE[2] = multichanel_framebased_B.xn
    [1499];

  /* Update for UnitDelay: '<Root>/Unit Delay2' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  multichanel_framebased_DW.UnitDelay2_DSTATE[2] =
    multichanel_framebased_B.prevx[1499];

  /* Update for UnitDelay: '<Root>/Unit Delay3' incorporates:
   *  UnitDelay: '<Root>/Unit Delay2'
   */
  multichanel_framebased_DW.UnitDelay3_DSTATE[2] =
    multichanel_framebased_B.prevprevx[1499];

  /* Matfile logging */
  rt_UpdateTXYLogVars(multichanel_framebased_M->rtwLogInfo,
                      (&multichanel_framebased_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0625s, 0.0s] */
    if ((rtmGetTFinal(multichanel_framebased_M)!=-1) &&
        !((rtmGetTFinal(multichanel_framebased_M)-
           multichanel_framebased_M->Timing.taskTime0) >
          multichanel_framebased_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(multichanel_framebased_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++multichanel_framebased_M->Timing.clockTick0)) {
    ++multichanel_framebased_M->Timing.clockTickH0;
  }

  multichanel_framebased_M->Timing.taskTime0 =
    multichanel_framebased_M->Timing.clockTick0 *
    multichanel_framebased_M->Timing.stepSize0 +
    multichanel_framebased_M->Timing.clockTickH0 *
    multichanel_framebased_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void multichanel_framebased_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)multichanel_framebased_M, 0,
                sizeof(RT_MODEL_multichanel_framebas_T));
  rtmSetTFinal(multichanel_framebased_M, -1);
  multichanel_framebased_M->Timing.stepSize0 = 0.0625;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    multichanel_framebased_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(multichanel_framebased_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(multichanel_framebased_M->rtwLogInfo, (NULL));
    rtliSetLogT(multichanel_framebased_M->rtwLogInfo, "tout");
    rtliSetLogX(multichanel_framebased_M->rtwLogInfo, "");
    rtliSetLogXFinal(multichanel_framebased_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(multichanel_framebased_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(multichanel_framebased_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(multichanel_framebased_M->rtwLogInfo, 0);
    rtliSetLogDecimation(multichanel_framebased_M->rtwLogInfo, 1);
    rtliSetLogY(multichanel_framebased_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(multichanel_framebased_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(multichanel_framebased_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &multichanel_framebased_B), 0,
                sizeof(B_multichanel_framebased_T));

  /* states (dwork) */
  (void) memset((void *)&multichanel_framebased_DW, 0,
                sizeof(DW_multichanel_framebased_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(multichanel_framebased_M->rtwLogInfo, 0.0,
    rtmGetTFinal(multichanel_framebased_M),
    multichanel_framebased_M->Timing.stepSize0, (&rtmGetErrorStatus
    (multichanel_framebased_M)));

  {
    real_T arg;
    char_T *sErr;

    /* Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
    sErr = GetErrorBuffer(&multichanel_framebased_DW.FromMultimediaFile_HostLib
                          [0U]);
    CreateHostLibrary("frommmfile.dll",
                      &multichanel_framebased_DW.FromMultimediaFile_HostLib[0U]);
    createAudioInfo(&multichanel_framebased_DW.FromMultimediaFile_AudioInfo[0U],
                    1U, 0U, 8000.0, 16, 1, 500, 0, GetNullPointer());
    createVideoInfo(&multichanel_framebased_DW.FromMultimediaFile_VideoInfo[0U],
                    0U, 0.0, 0.0, "", 0, 0, 0, 0, 1U, 0, 0, GetNullPointer());
    if (*sErr == 0) {
      LibCreate_FromMMFile
        (&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U], NULL,
         "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\dsp\\dsp\\samples\\speech_dft_8kHz.wav",
         1,
         "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\multimedia\\bin\\win64\\audio\\audiofilesndfilereaderplugin.dll",
         "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\multimedia\\bin\\win64\\audioslconverter",
         &multichanel_framebased_DW.FromMultimediaFile_AudioInfo[0U],
         &multichanel_framebased_DW.FromMultimediaFile_VideoInfo[0U], 0U, 1U, 1U,
         0U, 0U, 1U, 1.0, 9.2233720368547758E+18, 0U);
    }

    if (*sErr == 0) {
      LibStart(&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U]);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&multichanel_framebased_DW.FromMultimediaFile_HostLib
                         [0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(multichanel_framebased_M, sErr);
        rtmSetStopRequested(multichanel_framebased_M, 1);
      }
    }

    /* End of Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

    /* Start for S-Function (sdspsine2): '<Root>/Sine Wave' */
    /* Trigonometric mode: compute accumulated
       normalized trig fcn argument for each channel */
    /* Keep normalized value in range [0 2*pi) */
    arg = fmod(multichanel_framebased_P.SineWave_Phase, 6.2831853071795862);
    if (arg < 0.0) {
      arg += 6.2831853071795862;
    }

    multichanel_framebased_DW.SineWave_AccFreqNorm = arg;

    /* End of Start for S-Function (sdspsine2): '<Root>/Sine Wave' */

    /* Start for S-Function (saudioToAudioDevice): '<Root>/Audio Device Writer' */
    sErr = GetErrorBuffer
      (&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[0U]);
    CreateHostLibrary("hostlibaudio.dll",
                      &multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[
                      0U]);
    if (*sErr == 0) {
      LibCreate_Audio
        (&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[0U], 0,
         "Default", 1, 1, 1, 8000.0, 3, 500, 5000, 500, 0, NULL);
    }

    if (*sErr != 0) {
      DestroyHostLibrary
        (&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(multichanel_framebased_M, sErr);
        rtmSetStopRequested(multichanel_framebased_M, 1);
      }
    }

    /* End of Start for S-Function (saudioToAudioDevice): '<Root>/Audio Device Writer' */
  }

  {
    real_T arg;

    /* InitializeConditions for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
    LibReset(&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U]);

    /* InitializeConditions for S-Function (sdspchirp): '<Root>/Chirp' */

    /* DSP System Toolbox Chirp (sdspchirp) - '<Root>/Chirp' */
    /* Bidirectional Linear  */
    multichanel_framebased_DW.Chirp_BETA = fabs
      (multichanel_framebased_P.Chirp_f1 - multichanel_framebased_P.Chirp_f0) /
      multichanel_framebased_P.Chirp_t1;
    if (multichanel_framebased_P.Chirp_f1 > multichanel_framebased_P.Chirp_f0) {
      multichanel_framebased_DW.Chirp_MIN_FREQ =
        multichanel_framebased_P.Chirp_f0;
    } else {
      multichanel_framebased_DW.Chirp_MIN_FREQ =
        multichanel_framebased_P.Chirp_f0 - multichanel_framebased_DW.Chirp_BETA
        * multichanel_framebased_P.Chirp_Tsweep;
    }

    multichanel_framebased_DW.Chirp_PERIOD_THETA =
      multichanel_framebased_DW.Chirp_MIN_FREQ *
      multichanel_framebased_P.Chirp_Tsweep +
      multichanel_framebased_DW.Chirp_BETA *
      multichanel_framebased_P.Chirp_Tsweep *
      multichanel_framebased_P.Chirp_Tsweep / 2.0;
    multichanel_framebased_DW.Chirp_SWEEP_DIRECTION =
      (multichanel_framebased_P.Chirp_f1 > multichanel_framebased_P.Chirp_f0) ?
      0 : 1;
    multichanel_framebased_DW.Chirp_ACC_PHASE = 0.0;
    multichanel_framebased_DW.Chirp_CURRENT_STEP = 0.0;

    /* InitializeConditions for S-Function (sdspsine2): '<Root>/Sine Wave' */
    /* This code only executes when block is re-enabled in an
       enabled subsystem when the enabled subsystem states on
       re-enabling are set to 'Reset' */
    /* Reset to time zero on re-enable */
    /* Trigonometric mode: compute accumulated
       normalized trig fcn argument for each channel */
    /* Keep normalized value in range [0 2*pi) */
    arg = fmod(multichanel_framebased_P.SineWave_Phase, 6.2831853071795862);
    if (arg < 0.0) {
      arg += 6.2831853071795862;
    }

    multichanel_framebased_DW.SineWave_AccFreqNorm = arg;

    /* End of InitializeConditions for S-Function (sdspsine2): '<Root>/Sine Wave' */

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    multichanel_framebased_DW.UnitDelay_DSTATE[0] =
      multichanel_framebased_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    multichanel_framebased_DW.UnitDelay2_DSTATE[0] =
      multichanel_framebased_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    multichanel_framebased_DW.UnitDelay3_DSTATE[0] =
      multichanel_framebased_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    multichanel_framebased_DW.UnitDelay_DSTATE[1] =
      multichanel_framebased_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    multichanel_framebased_DW.UnitDelay2_DSTATE[1] =
      multichanel_framebased_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    multichanel_framebased_DW.UnitDelay3_DSTATE[1] =
      multichanel_framebased_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    multichanel_framebased_DW.UnitDelay_DSTATE[2] =
      multichanel_framebased_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    multichanel_framebased_DW.UnitDelay2_DSTATE[2] =
      multichanel_framebased_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    multichanel_framebased_DW.UnitDelay3_DSTATE[2] =
      multichanel_framebased_P.UnitDelay3_InitialCondition;
  }
}

/* Model terminate function */
void multichanel_framebased_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
  sErr = GetErrorBuffer(&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U]);
  LibTerminate(&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(multichanel_framebased_M, sErr);
    rtmSetStopRequested(multichanel_framebased_M, 1);
  }

  LibDestroy(&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U], 0);
  DestroyHostLibrary(&multichanel_framebased_DW.FromMultimediaFile_HostLib[0U]);

  /* End of Terminate for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

  /* Terminate for S-Function (saudioToAudioDevice): '<Root>/Audio Device Writer' */
  sErr = GetErrorBuffer
    (&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[0U]);
  LibTerminate(&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(multichanel_framebased_M, sErr);
    rtmSetStopRequested(multichanel_framebased_M, 1);
  }

  LibDestroy_Audio(&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi[0U],
                   1, 1);
  DestroyHostLibrary(&multichanel_framebased_DW.AudioDeviceWriter_AudioDeviceLi
                     [0U]);

  /* End of Terminate for S-Function (saudioToAudioDevice): '<Root>/Audio Device Writer' */
}
