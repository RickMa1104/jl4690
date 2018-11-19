

/*
GPIO SET:
	PC5-AB/D	
	LED7PIN-PC4_1PA15PA14PC0	PA11-MUTE   PA10-ADK1 PA9-ADKEY  PA3PA4-AUX1	
	PA1PA2-AUX0  PB11-BAT_DET PB10-LED2 PB9-LED1 PB3/PB8-IR 	
	SD1-PB0_DAT_PB1_CMD_PB2_CLK	
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
#define SYS_LVD_EN              0       ///<�������
#define KEY_TONE_EN     	    1       ///<������
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

    #define REC_EN             1   ///<��׼SDK¼������

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

//#define LED_7PIN_MODE
#ifdef LED_7PIN_MODE
#define support_led7_user_pc0pa14pa15pc1pc2pc3pc4
#define LED_7PIN_REVERSE
#define LED_ID_4018D7_1B
#ifdef LED_ID_4018D7_1B
#define LED_COM_MAX 7
#define LED_8NUMS 4
#define LED_8GRIDS 7
#define LED_ICON_NUMS 10
#endif
#endif






#define SUPPORT_TM1628_MODE
#ifdef SUPPORT_TM1628_MODE
#define TM1628_MODE 0x03
#define TM1628_DATA_CLK_STB_USE_PA15PC1PA14



#define LED_ID_DB_51
#ifdef LED_ID_DB_51
#define LED_COM_MAX 15
#define LED_8NUMS 6
#define LED_8GRIDS 14
#define LED_ICON_NUMS 25
#define LED_EQ_NUMS 24
//#define LED_EQ_BAR_GRIDS 6
#endif

#define LED_SHOW_SCREEN_FREQUENCE
#ifdef LED_SHOW_SCREEN_FREQUENCE
//#define LED_EQ_BAR_SHOW
//#define EQ_BAR_MODE_MAX 4
//#define EQ_BAR_MODE_DEFAULT 0
//#define EQ_MODE_CONTROL_WITH_KEY
#define SUPPORT_EQ_FREQUENCE
//#define EQ_ADC_VALUE_DETECT
//#define EQ_DETECT_PIN_USE_PA10
#endif


//#define TEST_PANEL_LED
#ifdef TEST_PANEL_LED
extern u8 bledComValue;
extern u8 bledGridValue;
#endif

//#define TEST_SHOW_ALL

#endif










#define SUPPORT_FLASH_ICON
#define SUPPORT_FLASH_CHAR

#ifdef SUPPORT_FLASH_CHAR
//#define SUPPORT_LED_BLUE_STRING_FLASH
//#define SUPPORT_LED_BLUE_BT_ICON_FLASH_CONNECT
#define SUPPORT_MUTE_FLASH
//#define MUTE_FLASH_ZERO_VOL
//#define MUTE_FLASH_ALL_SCREEN
#endif

#define SUPPORT_BT_LED_PRORAM
#define SUPPORT_LED7_SHOW_V00_MUTE_STATE
#define SUPPORT_EQ_SHOW_VXX

#define SUPPORT_EQ_SHOW_CHAR

#define support_aux_led_disp_line     //������ʾ"LINE"
//#define support_aux_led_disp_CD
#define SUPPORT_BLUE_SHOW_BT_STRING
#define support_led_disp_pause
#define support_mute_led_all_flish    //MUTE����
#define SUPPORT_NO_SHOW_LOAD	
#define SUPPORT_LED7_OFF_BAT_ICON


//#define support_1628_show_vol_v

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
#endif 

#if  0//KEY_IO_EN         ///<IO����ʹ��
#define support_io_scan_user_PR2               //ʹ�� PR2 ɨ�谴��
#define support_poweroff_wakeup_io_PR2   
#define support_k7036_scna_mode
#define support_690x_ic_rtc_stanby    //IC RTC-����ģʽ
#define support_power_off_voice           //�йػ����� 
#endif 

//PLAY:0R;REC:1K  MODE:3k3;REP:10K;EQ:15K;NEXT:20K;PREV:33K;
//#define adk_use_22k_7key_mode_tf
#define adk_use_10key_mode_tf2138_1600B
#define ADK_USE_10KEY_MODE



#ifdef ADK_USE_10KEY_MODE
#define adkey_max_num	10

#define PULL_UP_RESISTANCE 10   //��������22K
#define KEY9_RES 0 // pp
#define KEY8_RES 3.3	  // menu
#define KEY7_RES 5.6  //mode
#define KEY6_RES 15  // eq
#define KEY5_RES 33  // rpt
#define KEY4_RES 47  //next/v+
#define KEY3_RES 100 //prev/v-
#define KEY2_RES 150  // 
#define KEY1_RES 200 //
#define KEY0_NOKEY_RES 220  //

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
//#define  IR_IO_PA_X     14  // PA14
#define  IR_IO_PB_X     3  // PB3
//#define  IR_IO_PC_X     14  // PC14
//#define  IR_IO_PD_X     14  // PD14

//#define IR_USE_DOUBLE_TY_00FF_807F_22KEY
//#define IR_USE_DOUBLE_ZY2119_00FF_807F_22KEY
//#define  ir_max_num     22
//#define  IR_NUMS     2

//#define IR_TF_THREE_GENERAL_FF00_FD02_HD7369_7F80
#ifdef IR_TF_THREE_GENERAL_FF00_FD02_HD7369_7F80
#define  ir_max_num  26
#define IR_NUMS 3	
//-----------------------------------------------

#define   support_msg_stop_key 
#define   SUPPORT_IR_USE_SINGLE_MSG 
#define   support_stanby_mod 
#endif

//#define IR_TF_THREE_GENERAL_FF00_FD02_7F80
#ifdef IR_TF_THREE_GENERAL_FF00_FD02_7F80
#define  ir_max_num  26
#define IR_NUMS 3	
//-----------------------------------------------

#define   support_msg_stop_key 
#define   SUPPORT_IR_USE_SINGLE_MSG 
#define   support_stanby_mod 
#endif

#endif 

//#define IR_TF_THREE_GENERAL_FF00_20DF
#ifdef IR_TF_THREE_GENERAL_FF00_20DF
#define  ir_max_num  30
#define IR_NUMS 2
#define IR_TF_THREE_GENERAL_FF00_20DF_546
//-----------------------------------------------
#define support_100add_is_10add
#define support_fm_key_mode
#define support_music_key_mode
#define support_bt_key_mode
#define support_line_key_mode
#define   support_msg_stop_key 
#define   SUPPORT_IR_USE_SINGLE_MSG 
#define   support_stanby_mod

#endif


#define IR_TF_DB_51_THREE_GENERAL_FF00_20DF
#ifdef IR_TF_DB_51_THREE_GENERAL_FF00_20DF
#define  ir_max_num  30
#define IR_NUMS 2
//-----------------------------------------------
#define support_100add_is_10add
#define support_fm_key_mode
#define support_music_key_mode
#define support_bt_key_mode
#define support_line_key_mode
#define support_dvd_key_mode
#define support_cd_key_mode
#define   support_msg_stop_key 
#define   SUPPORT_IR_USE_SINGLE_MSG 
#define   support_stanby_mod

#endif


//-------LED---------------------------------------

#define LED_EN                  0       ///<LEDָʾʹ��
#define  PP_LED_USER_PB9
//#define  PP_LED_USER_PA3

//-------MUTE---------------------------------------
//MUTE IO 
  //  #define   PA_ENABLE
#ifdef PA_ENABLE   
//        #define  pa_mute_use_pin_PA11_PA10    // pa_mute_use_pin_PR0 //
        #define  pa_mute_use_pin_PA11// pa_mute_use_pin_PR0 //
//       #define   mute_io_L_is_mute   //  ��MUTE   ������Ϊ��MUTE    
      #define support_vol_is_0_mute_amp	//������0 MUTE ����
//      #define support_pause_stop_mute_amp
//      #define  support_bt_pause_mute_amp		  	
//        #define support_xa9901_ab_d_mode

#define support_power_on_dly



#endif 

//���ž���
#define support_power_on_mute
#ifdef support_power_on_mute
#define support_power_on_dly
#define  power_on__mute_use_pin_PA11
#endif




//-------AB/D---------------------------------------
//#define support_amP_ab_d
//#define amp_ab_d_user_PC5


//-------LINE DET---------------------------------------

//LINE INPUT IO SELECT
#define    line_user_PA1PA2  //AUX0 


// AUX DETECT SET
#define AUX_DETECT_EN      0
 #if  AUX_DETECT_EN
    #define  support_line_chack_user_PA3
    #define  support_line_unline_to_next_mode   //CHANGE_WORKMODE AUX UNLINE TO NEXT MODE
  //  #define AUX_OUT_WITHOUT_CNT  //PLUS OUT DELAY    ����
#endif 

//-------POWER ON SET ---------------------------------------
//#define  power_on_no_usb_sd_to_bt 
#define  power_on_no_usb_sd_to_line   
//#define  usb_sd_out_to_bt_mode   
#define  usb_sd_out_to_line_mode   
#define MP3_AUX_BT_FM


//-------GENERAL  SET----------------------------------
#define SUPPORT_BT_AUTO_PLAY	1  // BT MUSIC AUTO PLAY
#define SUPPORT_OFF_PHONE_CALL   1 // OFF PHONE 
//#define SUPPORT_OFF_MODE_VOICE     // OFF MUSIC LINE FM MODE VOICE
#define SUPPORT_REPEAT_ONLY_USE_ONE_ALL


//-------ELSE ---------------------------------------
//#define  support_msg_light_key
#ifdef support_msg_light_key
#define Light_max_mode   2
#define  support_default_light_on
#endif 

#if KEY_TONE_EN
#define  support_vol_max_tone_en  0
#endif 

//-------fm scan mode set-------------------------------------
#define SUPORT_FM_PP_CANEL_SCAN


// Ƶ����ʾ
//#define support_led_eq_disp    //֧�ַ����Ƶ����ʾ
//#define support_led_eq_user_PA14PA15PC0PC1PC2  
//#define support_led_eq_is_5led_user_k7036    //
//----------------------------------------------

#define MEDIA_MODE_USB_SD_DETECT 0
#if  MEDIA_MODE_USB_SD_DETECT	
u32 curr_device_using;
#endif

//disable all key  ,except (mode vol- vol+ standby)
#define SUPPORT_DISABLE_KEY_MUTE_STATE


#define SUPPORT_ENCODER
#ifdef SUPPORT_ENCODER
//#define ENCODE_PIN_USE_PA9PA10
#define ENCODE_PIN_USE_DU_PB11PB10
#define SUPPORT_ENCODE_flash_led
#ifdef SUPPORT_ENCODE_flash_led
//#define ENC_led_io_PB10
#define ENC_led_io_PB12
#endif
#endif

#define SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE //no device but want to under at mp3 mode
#ifdef SUPPORT_MULTIPLE_MODE_IN_LINEIN_MODE
enum{
	mode_aux=0,
	mode_ac3,
	mode_dvd,
	mode_linein_max,
	mode_mp3_nodevice,
	mode_cd,
}MODE_IN_LINEIN;
#define LINEIN_MULTIPLY_DEFAULT_MODE 0
//#define SUPPORT_MP3_IDEL_MODE_IN_LINEIN_MODE
#define SUPPORT_AC3_MODE_IN_LINEIN_MODE
//#define SUPPORT_CD_MODE_IN_LINEIN_MODE
#define SUPPORT_DVD_MODE_IN_LINEIN_MODE
#define support_ac3_show_OPTI_CHAR
#define MODE_KEY_MP3_PREV_MODE "BtStackTask"
#define MODE_KEY_MP3_NEXT_MODE "LineinTask"
#endif


#define support_sound_4052_control
#ifdef support_sound_4052_control
#define sound_4052_io_ab_pc3pa11
#define  sound_4052_io_mode_1
#define support_sound_4052_mute_state_control
#endif



