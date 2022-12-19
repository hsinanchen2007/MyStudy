### 解题思路

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        good = set(words)
        for word in words:
            for k in range(1, len(word)):
                good.discard(word[k: ])
        return sum(len(word) + 1 for word in good)
```