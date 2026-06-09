### 解题思路：
排序+小顶堆

* 首先按照上车地点距离初始位置距离排序；初始化小顶堆，小顶堆用来记录接下来最早需要下车的乘客人数。
* 顺序遍历 `trips`，首先更新当前车的位置距离起点的距离 `dist`，主要是为了解决 “先下后上” 的情况，假如当前乘客已满，但是当前距离与小顶堆堆顶元素比较发现有乘客需要下车，此处一个循环是为了解决在上次还未到下车距离此时又超过了下车位置的乘客一并全部下车的情况，循环直至没有乘客需要下车位置，再将这一站要上车的乘客加进来。
* 如果此时乘客人数大于车容量，那么就无法完成任务。
* 如果可以继续，则将这一站乘客需要下车的距离及人数加入到小顶堆中；继续遍历 `trips`。
* 参考评论区：直接将下车位置及人数和上车位置及人数放在一个列表中进行排序，然后顺序遍历，在特定的位置上下车，判断是否小于车容量，很巧妙。

#### 代码：
```python [-Python]
from typing import List
import heapq


class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key=lambda x: x[1])
        off_dist = []
        count = 0
        for i in range(len(trips)):
            dist = trips[i][1]
            while off_dist and dist >= off_dist[0][0]:
                _, passenger = heapq.heappop(off_dist)
                count -= passenger
            count += trips[i][0]
            if count > capacity:
                return False
            heapq.heappush(off_dist, [trips[i][-1], trips[i][0]])
        return True


    def carPooling1(self, trips: List[List[int]], capacity: int) -> bool:
        stop = []
        for n, s, e in trips:
            stop.append([s, n])
            stop.append([e, -n])

        stop.sort()

        for _, count in stop:
            capacity -= count
            if capacity < 0: return False

        return True
```