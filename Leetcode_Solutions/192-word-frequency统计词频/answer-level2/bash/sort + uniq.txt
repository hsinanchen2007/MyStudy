### 解题思路
bash 排序统计常用 sort, uniq
若原文以行为单位处理略复杂，将每个词转换为单独行再统计会简单一些
对于词之间多个空格的情况，第一遍 sort 会把所有多余的行放到末尾，grep 过滤掉
uniq 统计之后输出是按字母排序，所以有第二遍 sort 按词频排序
按输出格式要求，awk 调换词频和词的位置

### 代码

```bash
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr ' ' '\n' | sort | grep -v '^$' | uniq -c | sort -rn | awk '{print $2,$1}'
```