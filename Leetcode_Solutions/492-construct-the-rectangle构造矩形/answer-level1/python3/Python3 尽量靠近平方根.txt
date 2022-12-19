### 解题思路
长和宽都取尽量靠近平方根的整数

### 代码

```python3
class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        W = int(math.sqrt(area))
        L = area / W
        while L % int(L) != 0:
            W -= 1
            L = area / W
        return [int(L), W]
```