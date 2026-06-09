### 解题思路
此处撰写解题思路

### 代码

```bash
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' |sort -r|uniq -c |awk '{print $2" "$1}' |sort -n -k2 -r
```
cat 读文件，tr这个是刚学习到的，sort -r 进行排序，实际sort也行，uniq -c进行统计，awk 使用空格进行变量位置转换，最后是根据第二列的数值进行逆序排序