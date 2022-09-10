#ifndef DEFINE_H_
#define DEFINE_H_

typedef char uint8;
typedef short uint16;

/****************************************************/
/*              Frame Header Field                  */
/****************************************************/
#define DPEEPF_FRAMEHEADER_1ST 0x53u
#define DPEEPF_FRAMHEEADER_2ND 0x59u

/****************************************************/
/*              End of Frame Field                  */
/****************************************************/
#define DPEEPF_ENDOFFRAME_1ST 0x54u
#define DPEEPF_ENDOFFRAME_2ND 0x43u

/****************************************************/
/*              Control Character field             */
/****************************************************/
typedef enum {
    HeartPack_identification = 0x01u,
    Product_information,
    OTA_upgrade,
    Radar_sest,
    Operating_status,
    OutOfBoundsPosition_status = 0x07u,
    Human_presenceInformation = 0x80u,
    Breathing_information,
    Sleep_information = 0x84u,
    Heartbeat_information
}DPEEPF_controlCharacters; /* User edit here */

/***********************************************/
/*             Command Word Field              */
/***********************************************/

/* Human Presence Information */
typedef enum {
    HumanPre_presenceInformation = 0x01u,
    HumanPre_motionInformation,
    HumanPre_bodyDynamicParameters,
    HumanPre_activeReportingHuman_Distance,
    HumanPre_activeReportingHumanBody_Orientation
}DPEEPF_commandWords_humanPresenceInformation; /* User edit here */

/* Sleep Information */
typedef enum {
    SleepInf_inOutBedStatus = 0x01u,
    SleepInf_sleepStateMode,
    SleepInf_awakeTime,
    SleepInf_LigthSleepDuration,
    SleepInf_lengthDeepSleep,
    SleepInf_sleepQualityScore
}DPEEPF_commandWords_sleepInformation; /* User edit here */

/* Heartbeat Information */
typedef enum {
    HeartInf_rateInformation = 0x01u,
    HeartInf_heartRateValue,
    HeartInf_heartRateIntensity,
    HeartInf_confidenceLevel,
    HeartInf_heartRateWaveform
}DPEE_commandWords_hearbeatInformation; /* User edit here */

/* Breathing Information */
typedef enum {
    BreathInf_respiratoryInformation = 0x01u,
    BreathInf_respiratoryValue,
    BreathInf_respiratoryRate,
    BreathInf_respiratoryConfidenceLevel,
    BreathInf_respiratoryWaveForm
}DPEE_commandWords_breathingInformation; /* User edit here */

/***********************************************/
/*             Length Marking Field            */
/***********************************************/
typedef enum {
    LengthMarking_1b = (uint16)0x01u,
    LengthMarking_2b,
    LengthMarking_3b,
    LengthMarking_4b,
    LengthMarking_5b
}DPEEPF_lengthMarking; /* User edit here */

/***********************************************/
/*             Checksum Field                  */
/***********************************************/
uint8 dpeepf_dataCheckSum;

#endif