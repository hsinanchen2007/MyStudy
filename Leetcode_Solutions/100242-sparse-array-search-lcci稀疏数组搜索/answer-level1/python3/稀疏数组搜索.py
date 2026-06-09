### 解题思路
二分。。。

### 代码

```python3
class Solution:
    def findString(self, words: List[str], s: str) -> int:
        if s in words:
            return words.index(s)
        return -1
```