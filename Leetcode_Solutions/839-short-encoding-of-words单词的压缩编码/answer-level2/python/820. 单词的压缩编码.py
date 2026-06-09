### 解题思路
通过判断单词的后缀是否在集合中，在就去掉
知识点：
Set 函数discard 用于去掉集合中的值

### 代码

```python3
class Solution:
    
    def minimumLengthEncoding(self, words: List[str]) -> int:
        if not words:
            return 0
        nss = set(words)
        for w in words:
            for i in range(1, len(w)):
                nss.discard(w[i:])
        return sum([len(w)+1 for w in nss])
```