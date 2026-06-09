# **求重叠部分的面积。阴影部分面积取决于宽度最小的和长度最小的**
![11111.jpg](https://pic.leetcode-cn.com/c35a1dd4adaa6c8346c1afe241aabd26f696796f2a6fea8fe4c6355c7efbf05b-11111.jpg)

**短板效应。懂我的意思吧**
```
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        if not ops:
            return m*n
        a = min(map(lambda x: x[0], ops))
        b = min(map(lambda x: x[1], ops))
        return a*b
```