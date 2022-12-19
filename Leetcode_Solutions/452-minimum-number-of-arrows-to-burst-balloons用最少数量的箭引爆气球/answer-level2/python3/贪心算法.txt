首先对所有的气球，按右边界排序，构成一个队列。肯定要有一支箭射穿最先结束的（也就是排序之后的第一个）气球；如果可以顺便把后面更多的气球射穿，肯定不会让箭的数量增多；依次从队列左边取气球，如果可以连同第一个气球一起穿过（有交集），则将两个气球合并；如果不能一起穿过，则停止，射出一支箭。这里有可能会出现，第i（>1）个气球与第1个气球没有交集，但后面第j（>i）个气球与第1个气球有交集的情况，但是没有关系，因为j与第1个气球有交集，那j肯定也与i有交集，在射穿第i个气球（也可能是比i更靠后的某一个）的时候，可以顺便把它射穿，不会增加箭的数量。

```python3
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key=lambda x: [x[1], x[0]])
        queue = collections.deque(points)
        cnt = 0
        while len(queue) > 0:
            point = queue.popleft()
            while len(queue) > 0 and self.hasOverlap(point, queue[0]):
                point = self.combine(point, queue.popleft())
            cnt += 1
        return cnt


    def combine(self, point1, point2):
        return max(point1[0], point2[0]), min(point1[1], point2[1])

    def hasOverlap(self, a, b):
        if a[1] > b[1]:
            a, b = b, a 
        return b[0] <= a[1]
```
