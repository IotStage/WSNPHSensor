#ifndef WSNPHSensor_h
#define WSNPHSensor_h

#include <stdlib.h>
#include <stdint.h>
#include <Arduino.h>

// constantes

#define SensorPin A0  //le pin ou est branche le capteur
#define Offset 1  //compensation de la deviation
//#define LED 13      //le pin du led sur la carte
#define intervalMesure 20 //intervalle de ou on lit les valeurs sur le pin SensorPin
#define intervalConvertion 800 //intervalle ou les valeurs prises seront convertis en ph
#define tailleEchantillon  40  //taille des echantillons

//uint8_t tableauPh[tailleEchantillon];  //tableau stokage des echantillons
//uint8_t indexPh=0; 

class Ph
{

public:
	Ph();
	Ph(uint8_t sensorPin);
	void updatePh();
	//~Ph();
	void init(uint8_t offset, uint8_t mesure, uint32_t convertion,uint8_t taille);
	uint16_t moyenne(uint8_t* arr, uint8_t number);
	uint8_t getMesure();
	
private:
	uint8_t _sensorPin;
	uint8_t _offset;
	uint8_t _intervalMesure;
	uint32_t _intervalConvertion;
	uint8_t _tailleEchantillon;
	uint8_t phValue;
	uint8_t tableauPh[];
	uint8_t indexPh; 

};

#endif