### 解题思路
- 词库降序（长的在前，短的在后），初始化字符串S=''
- 遍历有序词库，检查word+'#'是不是在S中，是则表明已编码；否则S拓展word+'#'

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        S = ''
        words = sorted(words,key=lambda x:len(x),reverse=True)
        for word in words:
            if word+'#' not in S:
                S = S + word+'#'
        return len(S)
```