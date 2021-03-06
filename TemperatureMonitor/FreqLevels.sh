#!/usr/local/bin/bash

i=2
freq=0

rm ./freq_levels
while [ ! -z $freq ]
	do
		echo $freq >> freq_levels
		freq=`sysctl -a | grep levels | cut -d ' ' -f $i | cut -d '/' -f 1`
		i=`expr $i + 1`
done

freq=`cat ./freq_levels`

ps -auxf | awk '{print $2;}'> prev_list
ps -auxf | awk '{print $2;}'> present_list

