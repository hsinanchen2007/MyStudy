![image.png](https://pic.leetcode-cn.com/18e9330a8d4b6cd24db6e56761284bac26cc97b1aae2b339cb314144bde4182d-image.png)

把括号、根号和系数去掉，纯粹的加与乘，44ms，还是面积法最快。

```python []
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        (x1, y1), (x2, y2), (x3, y3) = points
        return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3
```
