### 解题思路
不用heap，不用PriorityQueue，不用一个length 1000的数组，直接把trips分割成上下车两个步骤，然后按照上下车地点排序。遍历每一个上下车，注意要先下后上。如果在某一个点人数超过capacity，返回false。遍历完没有返回false，那么返回true。

### 代码

```python
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        boarding = []
        for trip in trips:
            boarding.extend([[trip[1], trip[0]], [trip[2], -trip[0]]])
        boarding.sort(key = lambda x: (x[0], x[1]))
        on_board = 0
        for w in boarding:
            on_board += w[1]
            if on_board > capacity:
                return False
        return True
```