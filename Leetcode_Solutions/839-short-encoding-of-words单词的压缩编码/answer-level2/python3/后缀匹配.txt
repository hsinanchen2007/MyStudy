### 解题思路
若某一单词为其他一个单词的后缀，则该单词不单独出现在索引字符串S中，相同单词在S中只出现一次。所以先将单词列表去重，再对每个单词判断，各个后缀是否在单词列表中，若存在则从单词列表中去除。最后计算单词列表中每个单词的长度加一再累加。

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        tem = list(set(words))
        Sum = 0
        for item in tem:
            tem1 = len(item)
            for i in range(tem1-1):
                if(item[tem1-1-i:] in tem):
                    tem.remove(item[tem1-1-i:])
        for j in tem:
            Sum = Sum+len(j)+1
        return Sum

```