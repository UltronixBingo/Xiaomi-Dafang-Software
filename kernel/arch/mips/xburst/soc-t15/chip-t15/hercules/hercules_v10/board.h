#ifndef __BOARD_H__
#define __BOARD_H__
#include <gpio.h>
#include <soc/gpio.h>
#include <linux/jz_dwc.h>

#include "pmu.h"

/* ****************************GPIO LCD START******************************** */
#ifdef CONFIG_LCD_BYD_8991FTGF
#define GPIO_LCD_DISP		GPIO_PB(0)
#define GPIO_LCD_DE		0
#define GPIO_LCD_VSYNC		0
#define GPIO_LCD_HSYNC		0
#define GPIO_LCD_CS		GPIO_PA(11)
#define GPIO_LCD_CLK	        GPIO_PD(28)
#define GPIO_LCD_SDO		GPIO_PE(3)
#define GPIO_LCD_SDI		GPIO_PE(0)
#define GPIO_LCD_BACK_SEL	GPIO_PC(20)
#endif
#ifdef CONFIG_LCD_BYD_BM8766U
#define GPIO_LCD_DISP		GPIO_PB(0)
#endif
#ifdef CONFIG_LCD_TRULY_TFT240240_2_E
#define GPIO_LCD_RD				GPIO_PC(3)
#define GPIO_LCD_BLK            GPIO_PC(19)
#define GPIO_LCD_RST            GPIO_PC(20)
#define GPIO_LCD_CS				GPIO_PC(21)
#endif
#ifdef CONFIG_LCD_TRULY_TDO_HD0499K
#define GPIO_MIPI_RST_N         GPIO_PA(12)
#define GPIO_MIPI_PWR           GPIO_PC(17)
#endif
#ifdef CONFIG_LCD_BYD_9177AA
#define GPIO_MIPI_RST_N         GPIO_PC(3)
#define GPIO_MIPI_PWR           GPIO_PC(2)
#define GPIO_MIPI_ID			GPIO_PC(5)
#define GPIO_MIPI_TE			GPIO_PC(4)
#endif
#ifdef CONFIG_BACKLIGHT_PWM
#define GPIO_LCD_PWM		GPIO_PE(1)
#endif
#ifdef CONFIG_BACKLIGHT_DIGITAL_PULSE
#define GPIO_GIGITAL_PULSE      GPIO_PE(1)
#endif
#ifdef CONFIG_LCD_CV90_M5377_P30
#define GPIO_LCD_BLK		GPIO_PC(17)
#define GPIO_LCD_RST            GPIO_PA(12)
#define GPIO_LCD_NRD_E		GPIO_PC(8)
#define GPIO_LCD_NWR_SCL	GPIO_PC(25)
#define GPIO_LCD_DNC		GPIO_PC(26)
#define SLCD_NBUSY_PIN		GPIO_PA(11)
#endif
/* ****************************GPIO LCD END********************************** */

/* ****************************GPIO I2C START******************************** */
#ifdef CONFIG_SOFT_I2C0_GPIO_V12_JZ
#define GPIO_I2C0_SDA GPIO_PF(8)
#define GPIO_I2C0_SCK GPIO_PF(9)
#endif
#ifdef CONFIG_SOFT_I2C1_GPIO_V12_JZ
#define GPIO_I2C1_SDA GPIO_PE(18)
#define GPIO_I2C1_SCK GPIO_PE(19)
#endif
/* ****************************GPIO I2C END********************************** */

/* ****************************GPIO SPI START******************************** */
#ifndef CONFIG_SPI_GPIO
#define GPIO_SPI_SCK  GPIO_PA(18)
#define GPIO_SPI_MOSI GPIO_PA(1)
#define GPIO_SPI_MISO GPIO_PA(2)
#endif
/* ****************************GPIO SPI END********************************** */

/* ****************************GPIO KEY START******************************** */
#define GPIO_POWER_KEY			GPIO_PA(30)
#define ACTIVE_LOW_POWER		1

/* ****************************GPIO KEY END********************************** */

/******************************GPIO PCA9539 START***********************************/
/*GPIO PCA9593*/
#ifdef CONFIG_GPIO_PCA953X
#define PCA9539_IRQ_N       GPIO_PD(19)
#define PCA9539_RST_N       GPIO_PA(14)
#define PCA9539_GPIO_BASE   177
#define PCA9539_EXT_GPIO(x)   (PCA9539_GPIO_BASE + (x))
#endif /* CONFIG_PCA9539 */
/* ****************************GPIO PCA9539 END********************************** */

/* ****************************GPIO GSENSOR START**************************** */
#define GPIO_GSENSOR_INT     GPIO_PA(15)
/* ****************************GPIO GSENSOR END****************************** */

/* ****************************GPIO EFUSE START****************************** */
#define GPIO_EFUSE_VDDQ      PCA9539_EXT_GPIO(6)
/* ****************************GPIO EFUSE END******************************** */

/* ****************************GPIO MMC START******************************** */
#define GPIO_MMC_RST_N			GPIO_PA(29)
#define GPIO_MMC_RST_N_LEVEL	LOW_ENABLE
/* ****************************GPIO MMC END******************************** */

/* ****************************GPIO USB START******************************** */
#define GPIO_USB_ID			GPIO_PB(23)
#define GPIO_USB_ID_LEVEL		LOW_ENABLE
#define GPIO_USB_DETE			GPIO_PB(22)
#define GPIO_USB_DETE_LEVEL		LOW_ENABLE
#define GPIO_USB_DRVVBUS		GPIO_PE(11)
#define GPIO_USB_DRVVBUS_LEVEL		HIGH_ENABLE
/* ****************************GPIO USB END********************************** */

/* ****************************GPIO CAMERA START***************************** */
#define CAMERA_RST		       PCA9539_EXT_GPIO(4)
#define CAMERA_PWDN_N           PCA9539_EXT_GPIO(3)//GPIO_PA(13) /* pin conflict with USB_ID */
#define CAMERA_MCLK		GPIO_PE(2) /* no use */
/* ****************************GPIO CAMERA END******************************* */

/* ****************************GPIO AUDIO START****************************** */
#define GPIO_HP_MUTE		-1	/*hp mute gpio*/
#define GPIO_HP_MUTE_LEVEL	-1	/*vaild level*/

#define GPIO_SPEAKER_EN	   -1	      /*speaker enable gpio*/
#define GPIO_SPEAKER_EN_LEVEL	-1

#define GPIO_HANDSET_EN		-1	/*handset enable gpio*/
#define GPIO_HANDSET_EN_LEVEL   -1

#define	GPIO_HP_DETECT	-1		/*hp detect gpio*/
#define GPIO_HP_INSERT_LEVEL    1
#define GPIO_MIC_SELECT		-1	/*mic select gpio*/
#define GPIO_BUILDIN_MIC_LEVEL	-1	/*builin mic select level*/
#define GPIO_MIC_DETECT		-1
#define GPIO_MIC_INSERT_LEVEL   -1
#define GPIO_MIC_DETECT_EN	-1  /*mic detect enable gpio*/
#define GPIO_MIC_DETECT_EN_LEVEL -1 /*mic detect enable gpio*/

#define HP_SENSE_ACTIVE_LEVEL	1
#define HOOK_ACTIVE_LEVEL		-1
/* ****************************GPIO AUDIO END******************************** */

/* ****************************GPIO GMAC START******************************* */
#ifdef CONFIG_JZ_MAC
#ifndef CONFIG_MDIO_GPIO
#ifdef CONFIG_JZGPIO_PHY_RESET
#define GMAC_PHY_PORT_GPIO GPIO_PE(11)
#define GMAC_PHY_PORT_START_FUNC GPIO_OUTPUT0
#define GMAC_PHY_PORT_END_FUNC GPIO_OUTPUT1
#define GMAC_PHY_DELAYTIME 100000
#endif
#else /* CONFIG_MDIO_GPIO */
#define MDIO_MDIO_MDC_GPIO GPIO_PF(13)
#define MDIO_MDIO_GPIO GPIO_PF(14)
#endif
#endif /* CONFIG_JZ4775_MAC */
/* ****************************GPIO GMAC END********************************* */

/* ****************************GPIO WIFI START******************************* */
#define HOST_WAKE_WL	GPIO_PA(10)
#define WL_WAKE_HOST	GPIO_PA(9)
#define WL_REG_EN	GPIO_PA(8)
#if 0
#define GPIO_WLAN_REG_ON	GPIO_PG(7)
#define GPIO_WLAN_INT	        GPIO_PG(8)
#define GPIO_WLAN_WAKE	        GPIO_PB(28)
#define GPIO_WIFI_RST_N     GPIO_PB(20)
#endif

#define WLAN_PWR_EN	(-1)
//#define WLAN_PWR_EN	GPIO_PE(3)
/* ****************************GPIO WIFI END********************************* */

/* ****************************GPIO BLUETOOTH START************************** */
/* BT gpio */
#define HOST_WAKE_BT	GPIO_PA(1)
#define BT_WAKE_HOST	GPIO_PA(0)
#define BT_REG_EN	GPIO_PA(2)
#define BT_UART_RTS	GPIO_PF(2)
#define BLUETOOTH_UPORT_NAME  "ttyS0"
#if 0
#define BLUETOOTH_UPORT_NAME  "ttyS1"
#define BLUETOOTH_UPORT_NAME  "ttyS2"
#define BLUETOOTH_UPORT_NAME  "ttyS3"
#endif
#if 0
#define GPIO_BT_REG_ON      GPIO_PB(30)
#define GPIO_BT_WAKE        GPIO_PB(20)
#define GPIO_BT_INT    	    GPIO_PB(31)
//#define GPIO_BT_RST_N       GPIO_PB(28)
#define GPIO_BT_UART_RTS    GPIO_PF(2)
#define GPIO_PB_FLGREG      (0x10010158)
#define GPIO_BT_INT_BIT	    (1 << (GPIO_BT_INT % 32))
#endif
/* ****************************GPIO BLUETOOTH END**************************** */

#endif /* __BOARD_H__ */