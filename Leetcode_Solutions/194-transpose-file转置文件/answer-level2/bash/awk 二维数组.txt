1. 先定义输出的记录分割符为空格。
2. 使用二维数组存放切割过得记录信息
3. 使用记录数和行数遍历二维数组输出
4. 每行添加换行符
5. 删除行尾的多余空格
```
awk 'BEGIN{ORS=" "}{for(i=1;i<=NF;i++)res[i,NR]=$i}END{for(j=1;j<=NF;j++){for(k=1;k<=NR;k++) {print res[j,k]}printf("\n")}}' file.txt | sed 's/\s*$//g'
```
