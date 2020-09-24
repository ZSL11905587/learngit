#include "Usertask.h"
#include "cmsis_os.h"


extern osMessageQueueId_t myQueue01Handle;
    /**********************************************************************
  * @ ������  �� LED_Task
  * @ ����˵���� LED_Task��������
  * @ ����    ��   
  * @ ����ֵ  �� ��
  ********************************************************************/
 void LEDR_Task(void * parameter)
{	
//	uint16_t SendData = 0x1234;
//	osStatus_t SendStatus = osOK;
	
	while(1)
{
//		SendStatus = osMessageQueuePut(myQueue01Handle, &SendData, 0, 0);
//		
//		if(SendStatus != osOK)
//		{
//			printf("SendData orror!\r\n");
//		}
//		else
//			printf("�������ݳɹ�\r\n");
	
	
//		HAL_GPIO_TogglePin(GPIOH, LED_R_Pin);
		osDelay(500);   /* ��ʱ500��tick */
	}
}

	

 void LEDG_Task(void * parameter)
{	
	Queue_UsartTypeDef RxDatastruct;
	//uint8_t RxData[255] = {0};
	
	osStatus_t RxStatus = osOK;
	
	while(1)
	{
	  RxStatus = osMessageQueueGet(myQueue01Handle, &RxDatastruct, 0, osWaitForever);
	
		if(RxStatus != osOK)
		{
			printf("RxData error!\r\n");
		}
		else
		{	
			printf("RxDataSize=%d, RxData=%s\r\n", RxDatastruct.data_size, RxDatastruct.data);
		}
		
//		osDelay(500);   /* ��ʱ500��tick */
//		HAL_GPIO_TogglePin(GPIOH, LED_G_Pin);
		
	}
}

