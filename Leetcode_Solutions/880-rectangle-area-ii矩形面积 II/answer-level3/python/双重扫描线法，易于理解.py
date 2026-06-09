### 解题思路
首先，作为一道hard题，给与它最基本的尊重，先去完成medium题 56 合并区间。
然后再用扫描线法，将矩形的出入点和上下点都记录下来，按照x轴排序（类似skyline problem）。
根据event，依次扫描矩形的边，记录当前的矩形上下边（矩形可能不是从x=0开始）。在一个扫描区间，可能会有多个离散的矩形分布在纵坐标上，这里应用56题的合并区间（同样也是扫描线法），计算出合并的区间。

面积计算可能发生变化的点只能是矩形的出入点，因此在横坐标上，每个出入点判断一下纵坐标的合并区间是否发生变化。如果变化了，计算一下之前的面积。

所以最终是双重扫描线法，横坐标扫描矩形，纵坐标扫描合并区间。


### 代码

```python
class Solution(object):
    def rectangleArea(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        mod = 10 ** 9 + 7
        events = []
        for r in rectangles:
            left, right = r[0], r[2]
            events.append([left, -1, r[1], r[3]])
            events.append([right, 1, r[1], r[3]])
        events.sort()

        last_change = 0
        current_intervals = []
        current_merge = set()
        area = 0
        for e in events:
            if e[1] < 0:
                current_intervals.append((e[2], e[3]))
            else:
                current_intervals.remove((e[2], e[3]))

            new_merge = self.merge(current_intervals)
            if new_merge != current_merge:
                area += (e[0] - last_change) * sum((n[1] - n[0]) for n in current_merge)
                area %= mod
                current_merge = new_merge
                last_change = e[0]
        return area

    def merge(self, intervals):
        events = []
        for inter in intervals:
            events.append([inter[0], -1])
            events.append([inter[1], 1])
        events.sort()

        counts = 0
        interval = [0, 0]
        result = set()
        for e in events:
            if e[1] < 0:
                if counts == 0:
                    interval[0] = e[0]
                counts += 1
            else:
                counts -= 1
                if counts == 0:
                    interval[1] = e[0]
                    result.add(tuple(interval))
        return result
```