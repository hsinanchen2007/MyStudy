### 解题思路
此处撰写解题思路
首先用cat读入文件，输出通过管道向后传；
再用tr对每行的空格进行替换，将一个或多个连续空格替换成一个换行符
再进行字典排序（因为后面的uniq要求输入是有序的）
再用uniq去重复，并记下每种单词的数量。这时是 （数目 单词）形式
再用sort对数目进行排序，sort默认是升序，我们使用降序-r使其按照数目降序排列
再用awk对每一行进行区域划分并输出。默认按tab划分，也可用-F指定分隔符。function以（第二列，第一列）即（单词，数目）打印
### 代码

```bash
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt|tr -s ' ' '\n'|sort |uniq -c|sort -r|awk '{print $2,$1}'
```