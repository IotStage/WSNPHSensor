#include "WSNPHSensor.h"

Ph::Ph()
{
	_sensorPin = SensorPin;
	_offset = Offset;
	_intervalMesure = intervalMesure;
	_intervalConvertion = intervalConvertion;
	_tailleEchantillon = tailleEchantillon;
	phValue = 0;
	tableauPh[_tailleEchantillon];
	indexPh=0; 
};

Ph::Ph(uint8_t pin)
{
	_sensorPin = pin;
	_offset = Offset;
	_intervalMesure = intervalMesure;
	_intervalConvertion = intervalConvertion;
	_tailleEchantillon = tailleEchantillon;
	phValue = 0;
	tableauPh[_tailleEchantillon];
	indexPh=0; 
};

void Ph::init(uint8_t offset, uint8_t mesure, uint32_t Convertion,uint8_t taille)
{
	_offset = offset;
	_intervalMesure = mesure;
	_intervalConvertion = Convertion;
	_tailleEchantillon = taille;
	tableauPh[_tailleEchantillon];
	indexPh=0; 
};

uint8_t Ph::getMesure()
{
	return phValue;
};

uint16_t Ph::moyenne(uint8_t* arr, uint8_t number)
{
	uint8_t i;
	 int max,min;
	 uint16_t avg;
	 uint16_t amount=0;

	 if(number<5){  //less than 5, calculated directly statistics
	  for(i=0;i<number;i++){
	    amount+=arr[i];
	  }
	  avg = amount/number;
	  return avg;
	 }else{
	  
	   if(arr[0]<arr[1]){
	    min = arr[0];max=arr[1];
	   }
	   else{
	     min=arr[1];max=arr[0];
	    }
	    
	 for(i=2;i<number;i++){
	  if(arr[i]<min){
	    amount+=min;  //arr<min
	    min=arr[i];
	  }else {
	    if(arr[i]>max){
	      amount+=max;  //arr>max
	      max=arr[i];
	    }else{
	      amount+=arr[i]; //min<=arr<=max
	    }
	  }//if

	 }//for

	 avg = (uint16_t)amount/(number-2);

	 }//if

	 return avg;
};

void Ph::updatePh()
{
	static unsigned long samplingTime = millis();
	//static unsigned long printTime = millis();
	static uint16_t voltage;

	if(millis()-samplingTime > _intervalMesure)
	{
		tableauPh[indexPh++]=analogRead(_sensorPin);
		if(indexPh==_tailleEchantillon)
			{
				indexPh=0;
			}
		voltage = moyenne(tableauPh, _tailleEchantillon)*5.0/1024;
		phValue = 3.5*voltage+_offset;
		samplingTime=millis();
	}
}


