#!/usr/local/bin/bash

ncpu=`sysctl hw.ncpu | cut -d ' ' -f 2`
(( usage=ncpu*100-5 ))

idle=`ps auxf | awk '$11 ~/\[idle\]/' | awk '{print $3;}' | cut -d '.' -f 1`

if [ $idle -ge $usage ]
	then
		pid=`cat ./sleeping`
	
		for i in $pid
		do 

			kill -CONT $i
		done

		rm ./sleeping
fi

flag=1
read=(`cat hot_process`)

for pid in ${read[@]}

	do
		grep -w "$pid" present_list
		flag=$?

		if (( flag==0 ))
			then
				break
		fi

done

