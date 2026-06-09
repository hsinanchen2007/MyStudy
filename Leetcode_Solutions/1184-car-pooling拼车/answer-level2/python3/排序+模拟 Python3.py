**思路：**

按照时间（路程）顺序模拟，把所有的上车点和下车点加入一个列表里，然后从小到大排序，如果有上车点和下车点在一起的话，根据先下后上原则，要把下车点排在前面。然后从头开始遍历列表，模拟经过每个站点车上的人数，如果某个站点车上的人数大于车的容量，那么返回`False`，如果所有站点人数都小于等于车的容量，那么返回`True`。

**代码：**

```python
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        process = []
        for t in trips:
            process.append((t[1], 1, t[0]))
            process.append((t[2], 0, t[0]))
        process.sort()
        print(process)
        num = 0
        for p in process:
            if p[1] == 1:
                num += p[2]
                if num > capacity:
                    return False
            else:
                num -= p[2]
        return True`
```