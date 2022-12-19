两种解题思路
1. 利用awk处理文本. 并且利用awk中数组可以使用字符串作为数组下标的特性,,先将数组统计好后使用管道符传递给sort进行处理
`    awk '{for(i=1;i<=NF;i++){array[$i]++;}}END{for(a in array){print a,array[a];}}' words.txt | sort -r -n -k2`
2. 使用awk内置的数组PROCINFO(详细的介绍请参见:http://bbs.chinaunix.net/thread-4251429-1-1.html)
`awk 'BEGIN{PROCINFO["sorted_in"]="@val_num_desc"}{for(i=1;i<=NF;i++){array[$i]++;}}END{for(a in array){print a,array[a]}}' file.txt`
