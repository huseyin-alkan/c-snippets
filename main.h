/**
  ******************************************************************************
  * @file    c_snippets.h
  * @author  huseyin alkan
  * @brief   This file contains basic c macro snippets
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021.
  *
  * This software component is not protected under any licence 
  * prepared for educational purposes
  * You are free to use with a sincere thanks
  *
  ******************************************************************************
  */

    /*
      Definiton of preprocessor macros for bitwise operation
      This is a safe and human readable way of bit operation
    */

    /*---SET/CLEAR/GET single bit with position values---*/
    #define SET_BIT(REG, BITMASK)       ( (REG) |= (BITMASK) )
    #define CLR_BIT(REG, BITMASK)       ( (REG) &= (~(BITMASK)) )
    #define GET_BIT(REG, BITMASK)       ( (REG) & (BITMASK) )
    #define IS_BIT_SET(REG, BITMASK)    ( ((REG) & (BITMASK)) != 0)
    #define IS_BIT_CLR(REG, BITMASK)    ( ((REG) & (BITMASK)) == 0)

    /*---SET/CLEAR/GET single bit with index of target bit---*/
    #define SET_SH_BIT(REG, POS)       ( (REG) |= (1<<(POS)) )       /*bit shifted by POS*/
    #define CLR_SH_BIT(REG, POS)       ( (REG) &= ~(1<<(POS)) )      /*bit shifted by POS*/
    #define GET_SH_BIT(REG, POS)       ( ((REG)>>(POS)) & 1 )        /*bit shifted by POS*/
    #define IS_SH_BIT_SET(REG, POS)    ( ((REG) & (1<<(POS))) != 0)     /*bit shifted by POS*/
    #define IS_SH_BIT_CLR(REG, POS)    ( ((REG) & (1<<(POS))) == 0)     /*bit shifted by POS*/

    /*---SET/CLEAR/GET a group of bits with mask and position---*/
    #define SET_SH_MASK(REG, MASK, POS)        ( (REG) |= ((MASK)<<(POS)))   /*mask shifted by POS*/
    #define CLR_SH_MASK(REG, MASK, POS)        ( (REG) &= ~((MASK)<<(POS)))  /*mask shifted by POS*/
    #define GET_SH_MASK(REG, MASK, POS)        ( ((REG)>>(POS)) & (MASK))    /*mask shifted by POS*/

    /*---REPLACE a group of bits with mask, position and mask width---*/
    #define REPLACE_SH_MASK(REG, NEWVALUE, POS, LEN)    \
        do {    \
            TMP = (~(0xFFFFFFFF) >> (32 - (LEN)) << (POS));  /*create TMP to clear mask content in REG*/\
            (REG) &= TMP;                   /*clear mask bits*/\
            (REG) |= ((NEWVALUE)<<(POS));   /*update mask content with NEWVALUE*/\
        }while(0)

    /*---REPLACE a group of bits with mask---*/
    #define REPLACE_MASK(REG, MASK, NEWVALUE)    \
        do {                            \
            (REG) &= ~(MASK);           /*clear mask content*/\
            (REG) |= (NEWVALUE);        /*set new value to register*/\
        }while(0)

    /*Create of an ICD or Message List:
    The sequential message id can be given with enumeration
    The enumeration indexes can be controlled under functions
    Ex: is the given message name a member of enum 
    */
    typedef enum {
        SENSOR_WHO_AM_I_REG = 0x00,       /* device identification register */ /*Explanation of every msg is very useful*/
        SENSOR_CONTROL_REG,               /* device control register */
        SENSOR_GYRO_X_REG,                /* gyroscope X-roll angle register */
        SENSOR_GYRO_Y_REG,                /* gyroscope Y-pitch angle register */
        SENSOR_GYRO_Z_REG,                /* gyroscope Z-yaw angle register */
        SENSOR_ACC_X_REG,                 /* accelerometer X-roll angle register */
        SENSOR_ACC_Y_REG,                 /* accelerometer Y-pitch angle register */
        SENSOR_ACC_Z_REG,                 /* accelerometer Z-yaw angle register */
        SENSOR_MAG_X_REG,                 /* magnetometer X-roll angle register */
        SENSOR_MAG_Y_REG,                 /* magnetometer Y-pitch angle register */
        SENSOR_MAG_Z_REG,                 /* magnetometer Z-yaw angle register */
        SENSOR_TEMP_REG,                  /* sensor temperature register*/
    }sensor_reg_typedef_enum;

    /*Creating BIT fields of a register*/

    /*The bit fields of control register*/
    #define SENSOR_CTL_GYRO_STATE_POS           (0)
    #define SENSOR_CTL_GYRO_STATE_MSK           (0x03)
    #define SENSOR_CTL_GYRO_STATE_LEN           (2)
        #define SENSOR_CTL_GYRO_STATE_OFF               0b00000000  /*00: gyroscope in shutdown mode*/
        #define SENSOR_CTL_GYRO_STATE_SLEEP             0b00000001  /*01: gyroscope in hybernate mode*/
        #define SENSOR_CTL_GYRO_STATE_ON                0b00000010  /*10: gyroscope in normal active mode*/
        #define SENSOR_CTL_GYRO_STATE_HIRES             0b00000011  /*11: gyroscope in high sampling mode*/

    #define SENSOR_CTL_ACC_STATE_POS            (2)
    #define SENSOR_CTL_ACC_STATE_MSK            (0x0C)
    #define SENSOR_CTL_ACC_STATE_LEN            (2)
        /*The flags used with ...STATE_POS reg as shift value*/
        #define SENSOR_CTL_ACC_STATE_OFF               0b00000000  /*00: accelerometer in shutdown mode*/ 
        #define SENSOR_CTL_ACC_STATE_SLEEP             0b00000001  /*01: accelerometer in hybernate mode*/
        #define SENSOR_CTL_ACC_STATE_ON                0b00000010  /*10: accelerometer in normal active mode*/
        #define SENSOR_CTL_ACC_STATE_HIRES             0b00000011  /*11: accelerometer in high sampling mode*/

    #define SENSOR_CTL_MAG_STATE_POS            (4)
    #define SENSOR_CTL_MAG_STATE_MSK            (0x30)
    #define SENSOR_CTL_MAG_STATE_LEN            (2)
        /*The flags used with ...STATE_POS reg as shift value*/
        #define SENSOR_CTL_MAG_STATE_OFF               0b00000000  /*00: magnetometer in shutdown mode*/
        #define SENSOR_CTL_MAG_STATE_SLEEP             0b00000001  /*01: magnetometer in hybernate mode*/
        #define SENSOR_CTL_MAG_STATE_ON                0b00000010  /*10: magnetometer in normal active mode*/
        #define SENSOR_CTL_MAG_STATE_HIRES             0b00000011  /*11: magnetometer in high sampling mode*/
