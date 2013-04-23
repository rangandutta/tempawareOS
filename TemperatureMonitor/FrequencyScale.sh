#!/usr/local/bin/bash

freqs=`cat ./freq_levels`
freq=($freqs)
present=`sysctl -a | grep cpufreq.highest | cut -d ' ' -f 2`
i=0
for str in "${freq[@]}"; do
	if [ "$str" = "$present" ]; then
		
		if [ "$str" = "0" ]; then
			((i++))

		fi

		((i++))

		next=${freq[$i]}
		break
	else
		((i++))
	fi
done	

threshold=shravan

temp=`sysctl -a | grep temperature | cut -d ':' -f 2 | cut -d '.' -f 1`
flag="low"

for i in $temp
	do
		

		if [ $i -ge $threshold ]
		   then
			
			sysctl debug.cpufreq.highest=$next
			sysctl debug.cpufreq.highest

			bash Sleep.sh

			flag="high"
			break

		fi
done

mv present_list prev_list


echo $flag > present_list

ps -auxf | awk '{print $2;}'>> present_list

read=(`cat prev_list`)
prev_flag=${read[0]}

now_flag=$flag


	if [ "$prev_flag" = "low" ] && [ "$now_flag" = "high" ]
		then

			cp present_list hot_process

			read=(`cat prev_list`)
				for pid in ${read[@]}
					do
					sed "s/$pid//g" hot_process > temp
					mv temp hot_process
					done

			
			cat hot_process

	fi

sleep 5
