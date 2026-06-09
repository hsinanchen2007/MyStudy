### 解题思路
.........
以后再来看别人的解法吧

### 代码

```python3

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        # 初始化一个最大堆
        words =sorted(words, key= lambda s: len(s),reverse=True)
        # 
        wide_str= words[0]+'#'
        for i in words:
            if wide_str.find(i+'#') == -1:
                wide_str = wide_str + i + '#'
            else:
                continue
        return len(wide_str)
```