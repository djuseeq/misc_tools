# Miscellaneous tools for Arduino

## adcFilter
- Sort raw ADC values with bubble sorting and return the median value
- It's advantage is the burst noise does not affect the returned ADC value, [read more](https://embeddedgurus.com/stack-overflow/2010/10/median-filtering/) about the concept
- Change  ADC_SAMPLE_RATE to desired value in adcFilter.h file
