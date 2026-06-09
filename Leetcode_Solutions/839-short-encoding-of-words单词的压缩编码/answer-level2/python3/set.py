### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words):
        good = set(words)
        for i in range(len(words)):
            for j in range(1,len(words[i])):
                good.discard(words[i][j:])
        return sum(len(word)+1 for word in good)
```