### 解题思路
从平方根开始依次向下搜索（向上也一样）

### 代码

```python3
import math
class Solution:

    def constructRectangle(self, area: int) -> List[int]:
        mid = int(math.sqrt(area))  # 求平方根

        while mid >= 1:  # 从平方根开始依次向下搜索（向上也一样）
            if mid * int(area / mid) == area:  # 如果当前值*int(面积/当前值) == 面积，那么说明找到符合条件了。（如果area不能整除mid，那么是不会像等的。）
                return [int(area/mid), mid]
            mid -= 1
```