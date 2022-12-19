cat words.txt | tr ' ' '\n' | sort | uniq -c | sort -r | awk '$2!="" {print $2" "$1}'

1. 获取words.txt的内容
2. 将空格换成换行符，让每一个单词单独成为一列
3. 根据字母顺序进行排序
4. 使用uniq -c统计频次
5. 逆序排序
6. 过滤空的字符，并将结果输出