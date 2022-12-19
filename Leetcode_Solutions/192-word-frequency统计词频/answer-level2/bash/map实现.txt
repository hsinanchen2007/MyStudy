#!/bin/bash

declare -A map
for word in `cat words.txt`;do
    ((map[$word]++))
done
for key in ${!map[@]};do
    max=0
    maxwd=""
    for key1 in ${!map[@]};do
        if [ ${map[$key1]} -gt $max ]; then
            max=${map[$key1]}
            maxwd=$key1
        fi
    done
   echo "$maxwd $max"
   unset map[$maxwd]
done
