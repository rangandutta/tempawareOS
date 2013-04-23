#!/bin/sh

mkdir $1/TemperatureMonitor
cp ./* $1/TemperatureMonitor
gcc $1/TemperatureMonitor/temp_monitor.c -o $1/TemperatureMonitor/temp_monitor
gcc $1/TemperatureMonitor/take_reading.c -o $1/TemperatureMonitor/take_reading
sed "s/shravan/$2/g" $1/TemperatureMonitor/FrequencyScale.sh > $1/TemperatureMonitor/Threshold
rm $1/TemperatureMonitor/FrequencyScale.sh
mv $1/TemperatureMonitor/Threshold $1/TemperatureMonitor/FrequencyScale.sh
