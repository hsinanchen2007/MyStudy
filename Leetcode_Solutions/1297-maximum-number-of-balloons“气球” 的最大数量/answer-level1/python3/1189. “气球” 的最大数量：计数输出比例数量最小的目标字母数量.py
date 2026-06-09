没有什么算法，就是计数而已，时间复杂度$O(N)$，空间复杂度$O(1)$，其中$N$为`text`的长度。

![image.png](https://pic.leetcode-cn.com/05294d46062491f5df76604a8c8c09207f03d1174d9f5db905f5c8be973a4d40-image.png)

48ms，仅供参考。

```python []
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        d = collections.Counter(text)
        return min(d['b'], d['a'], d['l'] // 2, d['o'] // 2, d['n'])
```
