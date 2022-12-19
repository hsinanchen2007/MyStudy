### 解题思路
用模板类中的Counter找两个字符串的区别

### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        from collections import Counter
        map_ = Counter()
        for i in s:
            map_[i] += 1
        for j in t:
            map_[j] -= 1
            if map_[j] == -1:
                return j
```