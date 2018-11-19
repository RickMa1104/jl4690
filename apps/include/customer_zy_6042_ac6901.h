

/*

GPIO SET:
  	encoder: V+PR1  V1-PR3  
	PA11-MUTE	PB13-MIC PA9-ADKEY PA10-MIC_PR  PB10-IR	AUX2-PB11PB12
	SD1-PB0_DAT_PB1_CMD_PB2_CLK	
	LED7_TY_IO		RGB:PA1PA4PB3
*/


/*
*********************************************************************
                        DEBUG MACRO
*********************************************************************
*/

  #define __DEBUG         ////<����ϵͳ��ӡ���Թ���

/*
*********************************************************************
                        APPLICATION FUNCTION
*********************************************************************
*/
#define AC6901A_OFF_IO  // JSUO ADD  20161111


#define EARPHONE_MODE_EN    0

/*
*********************************************************************
                        COMMON MACRO
*********************************************************************
*/



#define EQ_EN			        1       ///<EQģ�鿪��
#define EQ_UART_BDG	    		0       ///<EQ uart online dbg switch
#define DAC_SOUNDTRACK_COMPOUND 0       ///<dac�����ϲ�
#define DAC_AUTO_MUTE_EN		1       ///<�Զ�mute
#define SYS_LVD_EN              1       ///<�������
#define KEY_TONE_EN     	    0       ///<������
#define UART_UPDATA_EN          0      ///<��������
#ifdef  MINI
    #define KEY_DOUBLE_CLICK                ///<����˫������
#endif

//=================================================
// 1-VOL SET JSUO
#define SYS_DEFAULT_VOL        30      ///<��0��ʾʹ��Ĭ������
#if  SYS_DEFAULT_VOL
#else 
#define RESET_DEFAULT_VOL   25 
#define RESET_MIN_VOL             10
#endif 

/*
*********************************************************************
                        DEVICE MACRO
*********************************************************************
*/
// 2- SD USB PC  EN	JSUO

    #define SDMMC0_EN       0
    #define SDMMC1_EN       1
    #define USB_DISK_EN     1
    #define USB_PC_EN        1


#if EARPHONE_MODE_EN
    #define VCOMO_EN 	1	//�Ƿ�ѡ��VCMOֱ�ƶ���
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#else
    #define VCOMO_EN 	0	//�Ƿ�ѡ��VCMOֱ�ƶ���
    #define DAC_CHANNEL_SLECT  DAC_L_R_CHANNEL
#endif


/*
*********************************************************************
                        APP MACRO
*********************************************************************
*/

  #define SUPPORT_APP_RCSP_EN         0   ///<��׼SDK���ֻ�app ������ʱ��֧��

#if SUPPORT_APP_RCSP_EN
    #define RCSP_LIGHT_HW               1   //light hardware support
#else
    #define RCSP_LIGHT_HW               0
#endif


/*
*********************************************************************
                        BT MACRO
*********************************************************************
*/
#include "bluetooth/bluetooth_api.h"

#define BT_MODE      NORMAL_MODE

#if BT_MODE==TEST_FCC_MODE
  #undef UART_UPDATA_EN
  #define UART_UPDATA_EN  0
#endif

#define BT_ANALOG_CFG   0//ģ������
#define BT_XOSC         0//

#define BT_BACKMODE         0             ///<������̨


#if !BT_BACKMODE
    #define BT_HID_INDEPENDENT_MODE  0    ///<HID���յĶ���ģʽֻ֧�ַǺ�̨
#endif

#define BT_PHONE_NUMBER                    0          ///<���籨��
#if EARPHONE_MODE_EN
	#define AUTO_SHUT_DOWN_TIME 3*2*60          ///�����������Զ��ػ���ʱ��u16���ͣ�0��ʾ���Զ��ػ�
#else
	#define AUTO_SHUT_DOWN_TIME 0          ///�����������Զ��ػ���ʱ��u16���ͣ�0��ʾ���Զ��ػ�
#endif

/*
*********************************************************************
                       ��Դ���� 
*********************************************************************
*/
#define    PWR_NO_CHANGE     0     //   0:  no change   
#define    PWR_LDO33         1     //   1:  LDOIN 5v -> VDDIO 3.3v -> DVDD 1.2v
#define    PWR_LDO15         2     //   2:  LDOIN 5v -> LDO   1.5v -> DVDD 1.2v, support bluetooth
#define    PWR_DCDC15        3     //   3:  LDOIN 5v -> DCDC  1.5v -> DVDD 1.2v, support bluetooth

#if EARPHONE_MODE_EN
	#define PWR_MODE_SELECT      PWR_DCDC15 
#else
	#define PWR_MODE_SELECT      PWR_LDO15
#endif

/*
*********************************************************************
                       �͹������� 
*********************************************************************
*/
#define    BT_OSC           0
#define    RTC_OSCH         1
#define    RTC_OSCL         2

#if EARPHONE_MODE_EN
    #define SNIFF_MODE_CONF    SNIFF_EN
    #define BT_LOW_POWER_MODE  BT_POWER_DOWN_EN //BT_POWER_OFF_EN
    #define LOWPOWER_OSC_TYPE  BT_OSC
    #define LOWPOWER_OSC_HZ    24000000L
#else
    #define SNIFF_MODE_CONF    0//SNIFF_EN
    #define BT_LOW_POWER_MODE  0//BT_POWER_DOWN_EN //BT_POWER_OFF_EN
    #define LOWPOWER_OSC_TYPE  BT_OSC//RTC_OSCL//BT_OSC
    #define LOWPOWER_OSC_HZ    24000000L//32768L//24000000L
#endif

#define D2SH_DIS_SW         0          //d2sh dis sw  rtcvdd��û��������Ҫ��1
#define BLE_BREDR_MODE      BT_BREDR_EN


/*
*********************************************************************
                       оƬ��װ���� 
*********************************************************************
*/

#define RTCVDD_TYPE              0          //RTCVDD��û�а����Ҫ��1,Ŀǰ��Ӧ��װоƬAC6905
#define BTAVDD_TYPE              0          //BTAVDDû�а����Ҫ��1 ��Ŀǰ��Ӧ��װоƬAC6907A,AC6908A

/*
*********************************************************************
    MUSIC MACRO
*********************************************************************
*/
#define MUSIC_DECRYPT_EN 		0	//SMP�����ļ�֧��
#define MUSIC_AB_RPT_EN 		1	//AB�ϵ�֧��


#define DEC_TYPE_MP3_ENABLE         ///<MP3
#define DEC_TYPE_SBC_ENABLE         ///<SBC

#ifndef MINI
    #define DEC_TYPE_WAV_ENABLE     ///<3K_code_space
    #define DEC_TYPE_FLAC_ENABLE    ///<5K_code_space
    #define DEC_TYPE_APE_ENABLE     ///<8K_code_space
    #define DEC_TYPE_WMA_ENABLE     ///<30K_code_space
    // #define DEC_TYPE_F1A_ENABLE     ///<30K_code_space
#endif



/*
*********************************************************************
                        FM MACRO
*********************************************************************
*/
// 3- FM EN	JSUO

#ifdef MINI
    #define FM_RADIO_EN         0       ///<MINI_BT
#else
    #define FM_RADIO_EN         1       ///<��׼SDK
#endif

#if FM_RADIO_EN
    #define RDA5807                 0       ///<RDA5807FM
    #define BK1080                  0       ///<BK1080FM
    #define QN8035                  0       ///<QN8035FM
    #define FM_INSIDE               1       ///<оƬ�ڲ�FM
#endif

/*
*********************************************************************
                        RTC MACRO
*********************************************************************
*/
  #define RTC_CLK_EN          0       ///<��׼SDK RTCʱ��ģʽ

#if RTC_CLK_EN
    #define RTC_ALM_EN          1       ///<RTC����ģʽ
    #define RTC_CLK_CHECK_EN    0       ///<RTC������
#endif

/*
*********************************************************************
                        ECHO MACRO
*********************************************************************
*/
  #define ECHO_EN                      0       ///<���칦�� ��׼SDK
  #define ECHO_TASK_EN        0       ///<����ģʽ ��׼SDK

/*
*********************************************************************
                        REC MACRO
*********************************************************************
*/
// 4- REC EN	JSUO

    #define REC_EN             0   ///<��׼SDK¼������

#if REC_EN

#define support_rec_stop_to_music
#define support_only_rec_key_to_rec_mode
#define support_music_key_mode
#define SUPPORT_RECPLAY_STATE

#define SUPPORT_REC_SHOW_TIME_BUG // SDK  NO SHOWTIME

//#define support_off_mode_change_voice
//#define support_fm_key_mode
//#define support_bt_key_mode
//#define support_line_key_mode

extern u16 rec_file_startcnt;
extern u16 rec_file_endcnt;
extern bool  muisc_to_rec_flag;
#ifdef support_rec_line_fm_rec_return_line_fm
extern u8   play_rec_last_file;   
#else 
extern  bool  play_rec_last_file;   
#endif 
#endif


#if 0 //SUPPORT_APP_RCSP_EN
    #undef  REC_EN
    #define REC_EN         0         ///<�ֻ�APPģʽ��֧��¼��
#endif

#if REC_EN
	#define BT_REC_EN		0       ///<����¼��ʹ��
	#define MIC_REC_EN		1       ///<MIC¼��ʹ��
	#define FM_REC_EN		0       ///<FM¼��ʹ��
	#define AUX_REC_EN		0       ///<AUX¼��ʹ��
#endif


/*
*********************************************************************
                        UI MACRO
*********************************************************************
*/

// 5- UI	EN	JSUO

   #define UI_ENABLE                1     ///<UI_��ʾ
 

#if  UI_ENABLE
    ///��ѡһ
    #define LCD_128X64_EN         0      ///<lcd ֧��
    #define LED_7_EN                       1      ///<led ֧��     
    #define LCD_SUPPORT_MENU     0       ///�˵���ʾ
    #define LRC_LYRICS_EN                 0       ///LRC�����ʾ


//#define LCD_4x9_MODE
#ifdef LCD_4x9_MODE
#define support_lcd_4x9_use_pc5432_pa1514111094321
//#define LCD_COM_REVERSE

#define LCD_ID_ZSLCD
#ifdef LCD_ID_ZSLCD
#define LED_COM_MAX 4
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 8
#endif
//#define LCD_ID_HL_21716HNT
#ifdef LCD_ID_HL_21716HNT
#define LED_COM_MAX 4
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 8
#endif
	
//#define LCD_ID_JXH_S6002A
#ifdef LCD_ID_JXH_S6002A
#define LED_COM_MAX 4
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 8
#endif
#endif


#define LED_7PIN_MODE
#ifdef LED_7PIN_MODE
#define support_led7_user_pc0pa14pa15pc1pc2pc3pc4
#define LED_7PIN_REVERSE
	
#define LED_ID_SD88N27SRB_30
#ifdef LED_ID_SD88N27SRB_30
#define LED_COM_MAX 7
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 8
#endif

#endif

#define SUPPORT_FLASH_ICON
#define SUPPORT_FLASH_CHAR

#define SUPPORT_BT_LED_PRORAM
#define SUPPORT_IDLE_MODE_SHOW_2POINT_FLASH


#ifdef SUPPORT_FLASH_CHAR
#define SUPPORT_LED_BLUE_STRING_FLASH
#define SUPPORT_MUTE_FLASH
//#define MUTE_FLASH_ZERO_VOL
#endif
#define SUPPORT_EQ_SHOW_CHAR

//#define support_aux_led_disp_line     //������ʾ"LINE"
#define support_led_disp_pause
#define support_mute_led_all_flish    //MUTE����
#define SUPPORT_NO_SHOW_LOAD	
 #endif 


//*********************************************************************
 

//-------ADKEY--------------------------------------------------------


#define muteh_key_mode   1

#if muteh_key_mode
#define KEY_AD_EN       1   ///<AD����ʹ��
#define KEY_IO_EN       0   ///<IO����ʹ��
#define KEY_IR_EN       1   ///<����ң��ʹ��,PA9
#define KEY_TCH_EN      0   ///<��������ʹ��
#endif 

#if KEY_AD_EN  
#define adk_user_pa9
//#define adk_user_pb9
#endif 

#if  0//KEY_IO_EN         ///<IO����ʹ��
#define support_io_scan_user_PR2               //ʹ�� PR2 ɨ�谴��
#define support_poweroff_wakeup_io_PR2   
#define support_k7036_scna_mode
#define support_690x_ic_rtc_stanby    //IC RTC-����ģʽ
#define support_power_off_voice           //�йػ����� 
#endif 


#define adk_10k_15key_mode_zy_rgb_led

//--------------------------
#define support_bt_key_mode


#define ADK_USE_15KEY_MODE

#ifdef ADK_USE_15KEY_MODE
#define adkey_max_num	15

#define PULL_UP_RESISTANCE 20   //��������
#define KEYE_RES 0  //prev
#define KEYD_RES 1 	 // 
#define KEYC_RES 2  	 // 
#define KEYB_RES 3 //next		0.8
#define KEYA_RES 4.7  //standby
#define KEY9_RES 5.6 // 		1.2
#define KEY8_RES 7.5 //   		1.4
#define KEY7_RES 10   // 		1.65
#define KEY6_RES 15  // 			1.8
#define KEY5_RES 24  // 			2.0
#define KEY4_RES 33 //pp		2.2	
#define KEY3_RES 51 // mode		2.5
#define KEY2_RES 75 // 		2.8
#define KEY1_RES 100 // ledmode	2.87
#define KEY0_NOKEY_RES 220	 //null	 3v
#endif

//#define adk_user_6_key_mode_and_power
//#define adk_use_22k_6key_mode
#ifdef adk_use_22k_6key_mode
//#define LONG_PP_KEY_AS_FM_SCAN
//#define SUPOORT_LONG_PP_AS_BT_CALL_REJECT
//#define SUPOORT_LONG_MODE_AS_BT_CONNECT_CTL
//#define SUPOORT_LONG_PP_AS_BT_CONNECT_CTL
#endif

//-------IR---------------------------------------

#if KEY_IR_EN         ///<����ң��ʹ��,PA9
//#define  IR_IO_PA_X     1  // PA1
#define  IR_IO_PB_X     10  // PB3
//#define  IR_IO_PC_X     14  // PC14
//#define  IR_IO_PD_X     14  // PD14

//#define IR_USE_DOUBLE_TY_00FF_807F_22KEY
//#define IR_USE_DOUBLE_ZY2119_00FF_807F_22KEY
//#define  ir_max_num     22
//#define  IR_NUMS     2

#define IR_ZY_THREE_GENERAL_YK2119_00FF_807F_01FE_25KEY
#define  ir_max_num     25
#define IR_NUMS 3

#define   support_msg_stop_key 
#define   SUPPORT_IR_USE_SINGLE_MSG 
#define   support_stanby_mod 

#endif 

//-------LED---------------------------------------

#define LED_EN                  0       ///<LEDָʾʹ��
//#define  PP_LED_USER_PB9
//#define  PP_LED_USER_PB10

//-------MUTE---------------------------------------
//MUTE IO 
//    #define   PA_ENABLE
#ifdef PA_ENABLE   
        #define  pa_mute_use_pin_PA11	// pa_mute_use_pin_PR0 //
//        #define  pa_mute_use_pin_PC1  // pa_mute_use_pin_PR0 //
//       #define   mute_io_L_is_mute   //  ��MUTE   ������Ϊ��MUTE    
      #define support_vol_is_0_mute_amp	//������0 MUTE ����
//      #define support_pause_stop_mute_amp
//      #define  support_bt_pause_mute_amp		  	
//        #define support_xa9901_ab_d_mode
#endif 


//-------AB/D---------------------------------------
//#define support_amP_ab_d
//#define amp_ab_d_user_PB6  


//-------LINE DET---------------------------------------

//LINE INPUT IO SELECT
//#define    line_user_PA1PA2  //AUX0 
//#define    line_user_extern  //extern  pt2313
#define    line_user_PB11PB12 //AUX2

// AUX DETECT SET
#define AUX_DETECT_EN      0
 #if  AUX_DETECT_EN
    #define  support_line_chack_user_PA3
    #define  support_line_unline_to_next_mode   //CHANGE_WORKMODE AUX UNLINE TO NEXT MODE
  //  #define AUX_OUT_WITHOUT_CNT  //PLUS OUT DELAY    ����
#endif 

//#define  SUPPORT_MULTI_INPUT_MODE
#ifdef SUPPORT_MULTI_INPUT_MODE
extern u8 bMultiExternInputSel;
#define    line2_user_PA3PA4  //AUX1
#define    SUPPOR_INPUT_AUX1  //AUX1\
//#define    SUPPOR_INPUT_AUX2  //AUX2
//#define    SUPPOR_MP3_NOP_IN_AUX_MODE
enum
{
    INPUT_AUX0_MODE=0,
    INPUT_AUX1_MODE,
    INPUT_MAX_MODE,
    INPUT_AUX2_MODE,
    INPUT_NOP_MODE,
};

#endif

//-------POWER ON SET ---------------------------------------
//#define  power_on_no_usb_sd_to_bt 
#define  power_on_no_usb_sd_to_line   
//#define  usb_sd_out_to_bt_mode   
#define  usb_sd_out_to_line_mode   



//-------GENERAL  SET----------------------------------
#define SUPPORT_BT_AUTO_PLAY	1  // BT MUSIC AUTO PLAY
#define SUPPORT_OFF_PHONE_CALL   1 // OFF PHONE 
#define SUPPORT_OFF_MODE_VOICE     // OFF MUSIC LINE FM MODE VOICE
#define SUPPORT_REPEAT_ONLY_USE_ONE_ALL
#define SUPPORT_POWER_ON_IN_IDLE_MODE
#define POWERUP_DEV_IGNORE

//-------ELSE ---------------------------------------
//#define  support_msg_light_key
#ifdef support_msg_light_key
#define Light_max_mode   2
#define  support_default_light_on
#endif 

#if KEY_TONE_EN
#define  support_vol_max_tone_en  0
#endif 

// Ƶ����ʾ
//#define support_led_eq_disp    //֧�ַ����Ƶ����ʾ
//#define support_led_eq_user_PA14PA15PC0PC1PC2  
//#define support_led_eq_is_5led_user_k7036    //
//----------------------------------------------

#define MEDIA_MODE_USB_SD_DETECT 0
#if  MEDIA_MODE_USB_SD_DETECT	
u32 curr_device_using;
#endif

//---FM  STATION  ADJUST-------------------------
#define FM_SCAN_MODE_ZY_DATA_AMP

//----------------------------------------------

//MIC���
#define MIC_CHECK_ENABLE	0
#if MIC_CHECK_ENABLE
 #define MIC_ONOFF_KEY	1
// #define  support_mic_check_user_PB11
 #define  support_mic_check_user_PA9
//#define   KOK_DETECT_USE_IO_ADC_VALUE
// #define  support_on_io_dn_10k
// #define  support_high_mic_in
//#define MIC_CHECK_OFF_DELAY_TIME  
#define MIC_CHECK_TIMER  20


#define KOK_DETECT_AUTO_VOL_SET
#define AUTO_VOL_SET_DEC  15

#define SUPPORT_MIC_ONOFF_SHOW  
#ifdef SUPPORT_MIC_ONOFF_SHOW
extern u8 bLedShowOnoffTimer;
#endif
//  #define support_high_mic_in 
extern bool mic_sw;  // 0-off  1-on
 extern bool auto_vol_sw; // 0 off   1 on
 extern  u8 store_vol; // 
 extern  u8 bPowerOnAmpMuteTimer; // 

#endif 


//----------------------------------------------
	
//*****BAT DETECT *****//
// #define SUPPORT_BAT_DETECT
#ifdef SUPPORT_BAT_DETECT
#define SUPPORT_BAT_DETECT_USE_IO
#define DETECT_EXTERNAL_BAT_USE_PB11
#define LED_SCREEN_SHOW_BAT_STATUS

//#define SUPPORT_BAT_DETECT_LOW_POWER_MODE_1
#define SUPPORT_BAT_DETECT_LOW_POWER_MODE_2


#define SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
#ifdef SUPPORT_LOW_POWER_OFF_USE_EXTERN_IO_CONTROL
#define LOW_POWER_OFF_USE_EXTERN_IO_PB12
//#define SUPPORT_LOW_POWER_LED_SHOW_BAT_FLASH
#define SUPPORT_LOW_POWER_USE_LED_SHOW
#define SUPPORT_LOW_POWER_LED_ALL_SCREEN_FLASH
#define SUPPORT_LOW_POWER_DISABLE_MUTE_KEY
#define LOW_POER_VOLTOGE_VAL   19
extern u16 low_off_cnt;
extern volatile u8 low_power_flag;
#endif

//-----------AMP POWER ON OFF------------------------------------
#define   AMP_POWER_ENABLE
#ifdef AMP_POWER_ENABLE   
        #define  AMP_POWER_IO_PA10
#endif 
//---------POWER ON  MUTE 1S  AND LOW POWER MUTE 5S--------------------
#define   AMP_MUTE_ENABLE
#ifdef AMP_MUTE_ENABLE   
#define  AMP_POWER_ON_MUTE_TIMER  3
#define  AMP_MUTE_IO_PA11
#endif 

#define  SUPPORT_LOW_POWER_DELAY_DET
#define  POWER_ON_LOW_POWER_DELAY_VAL	16

#endif

///---------------------------------------------

/* ���ù���IC����ͲIC*/
//#define SUPPORT_PT2313
#ifdef SUPPORT_PT2313
//#define PT2313_CLK_DATA_USE_PA15PA14
//#define PT2313_CLK_DATA_USE_PB10PB9
//#define PT2313_CLK_DATA_USE_PB9PB10
#define PT2313_CLK_DATA_USE_PC0PB10

// #define pt2313_use_rf_lf_as_sub

/*
 PIN9-R3 PIN10-R2 PIN11-R1 
 PIN13-L3 PIN14-L2 PIN15-L1 
 0X02 	    0X01 		0X00
 */
 
	
	//����2313 ͨ������
	
#define Aud_SwRadio				0x00		//Stereo 2
#define Aud_SwMP3				0x00		//Stereo 2
#define Aud_SwBt			       0x00		//Stereo 2
#define Aud_SwAUX				0x02		//Stereo 3
#define Aud_SwCD				0x01		//Stereo 3
#define Aud_SwVcd				0x03		//Stereo 3
#define Aud_SwNoting			0x03		//Stereo 4  *
	
#define MAIN_VOL_MAX         62
#define VOLUME_DEFUALT       62
#define SWVOL_DEFUALT        22
#define  FLFR_DEFUALT           28  //��� ֵ���� �������ȵ� ��ʼֵ  ������û�м������ֵ  �������������Լ�С���ֵ  ���31 
#define BASS_DEFAULT 7
#define TREBLE_DEFAULT 9
	
	//#define support_mute_key
//#define Support_MSG_RESET
	//#define Support_MSG_MUSIC_STOP
//#define SUPPORT_MSG_FRONT_LEFT
//#define SUPPORT_MSG_FRONT_RIGHT
#define Support_MSG_BASS
#define Support_MSG_TREBLE
#define Support_MSG_SWVOL
//#define Support_MSG_MIC_ECO_VOL_KEY
	
	//#define Support_MSG_DSP
	//#define Support_MSG_LOUDNESS
#define SUPPORT_MAIN_VOL_KEY  
#define supper_user_pt2313_ctrl_main_vol
#define support_menu_mode     //���ģʽ MENU���л�  ��VOL +- ����
#ifdef support_menu_mode
extern u8 menumode;
#endif

#define supper_bass_treble_max_28
	//#define MENU_NOT_SWTICH_MAIN_VOL
#define LED_TREBLE_SHOW_H
#define LED_SWVOL_SHOW_b
#define LINE_IN_USE_PT2313
#ifdef support_menu_mode
	enum
	{
		MENU_MAIN_VOL_MODE=0,
		MENU_TREBLE_MODE,		   
		MENU_BASS_MODE,
		MENU_MAX_MODE,
		MENU_SWVOLL_MODE,
		MENU_FRONT_LEFT_MODE,
		MENU_FRONT_RIGHT_MODE,
		MENU_OK_VOL_MODE,
		MENU_ECHO_MODE,
		MENU_SL_MODE, //surround L
		MENU_SR_MODE //surround R
	};
#endif 
	
#endif

//#define SUPPORT_RGB_LED_MODE
#ifdef SUPPORT_RGB_LED_MODE
#define SUPPORT_RGB_IO_PA1PA2PB3
//#define SUPPORT_IO_ANGLOG_OUTPUT_PWM
//#define SUPPORT_TIME3_AS_RGB
#endif

//---------POWER ON  MUTE 1S  AND STANDBY  MUTE --------------------
#define   AMP_MUTE_ENABLE
#ifdef AMP_MUTE_ENABLE   
#define  AMP_POWER_ON_MUTE_TIMER  3
#define  AMP_MUTE_IO_PA11
#define SUPPORT_AMP_STANDBY_MUTE
#define AMP_IDLE_MUTE_DELAY_DISABLE_TIMER 5
#endif 

///---------------------------------------------

#define SUPPORT_ENCODER
#ifdef SUPPORT_ENCODER
#define ENCODE_PIN_USE_PR3PR1
//#define SUPPORT_ENCODE_flash_led
#ifdef SUPPORT_ENCODE_flash_led
 extern u8    ENCODE_flash_led_time;
#define ENC_LED_IO_USE_PA3
#endif
#endif
///---------------------------------------------

