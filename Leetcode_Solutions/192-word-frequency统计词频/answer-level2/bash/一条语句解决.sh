### 解题思路
根据题目来，他说只有小写字母就过滤小写字母就行咯，加上边界
然后排序统计数量再根据数字倒序排列，最后用awk倒换位置

### 代码

```bash
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | egrep -o  "\<[a-z]+\>" | sort | uniq -c | sort -nr | awk '{print $2" "$1}'

```
