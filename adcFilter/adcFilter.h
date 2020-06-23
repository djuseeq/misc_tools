/**
  ******************************************************************************
  * @file    adcFilter.h
  * @author  György Kovács
  * @date    Jun 13, 2020
  * @brief   Sort raw ADC values ​​with bubble sorting and return the median value
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) [2020] [György Kovács]
  *
  * The MIT License (MIT)
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy of
  * this software and associated documentation files (the "Software"), to deal in
  * the Software without restriction, including without limitation the rights to
  * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
  * the Software, and to permit persons to whom the Software is furnished to do so,
  * subject to the following conditions:
  *
  * The above copyright notice and this permission notice shall be included in all
  * copies or substantial portions of the Software.
  *
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
  * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
  * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
  * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  * 
  ******************************************************************************
  */
#ifndef ADCFILTER_H_
#define ADCFILTER_H_

	//CONF
#define ADC_SAMPLE_RATE 5 // use only odd numbers, e.g. 3, 5, 7, 9, ...
	///////////
#define MEDIAN_POS (ADC_SAMPLE_RATE/2)

	//Prototype
	void bubSort(int sArray[], int aSize);
	int filteredAnalog(int aPin);


////Functions
	int filteredAnalog(int aPin){
		int samples[ADC_SAMPLE_RATE];
		for(int a = 0; a < ADC_SAMPLE_RATE; a++){
			//approximately takes (ADC_SAMPLE_RATE * 100 us) on Arduino with AtMega328
			samples[a] = analogRead(aPin);
		}
		bubSort(samples, ADC_SAMPLE_RATE);
		return samples[MEDIAN_POS];
	}
	///////////////////
	void bubSort(int sArray[], int aSize) {
		//128 -- 116 microsec
		for(int mainLoopCnt = 0; mainLoopCnt < (aSize-1); mainLoopCnt++) {

			for(int subLoopCnt = 0; subLoopCnt < (aSize - (mainLoopCnt+1)); subLoopCnt++) {

				if(sArray[subLoopCnt] > sArray[subLoopCnt+1]) {
					int sTmp = sArray[subLoopCnt];
					sArray[subLoopCnt] = sArray[subLoopCnt+1];
					sArray[subLoopCnt+1] = sTmp;
				}//end if

			}//end sub loop

		}//end main loop
	}

#endif /* ADCFILTER_H_ */
