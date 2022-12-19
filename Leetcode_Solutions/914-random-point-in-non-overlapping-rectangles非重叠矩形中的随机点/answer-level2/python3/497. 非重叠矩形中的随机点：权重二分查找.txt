按点数权重分成坐标线段坐标，查找的时候用二分查找找矩形，然后再在矩形范围内随机取点。

把**528. 按权重随机选择**改改就可以交了。

```
class Solution:

    def __init__(self, rects: List[List[int]]):
        self.d = [0] * len(rects)
        for i, (x1, y1, x2, y2) in enumerate(rects):
            self.d[i] = self.d[i - 1] + (x2 - x1 + 1) * (y2 - y1 + 1)       #边上点数要比长度多1
        self.rects = rects

    def pick(self) -> List[int]:
        i = bisect.bisect_left(self.d, random.randint(1, self.d[-1]))       #二分查找目标举行
        xi = random.randint(self.rects[i][0], self.rects[i][2])
        yi = random.randint(self.rects[i][1], self.rects[i][3])             #x,y坐标随机生成
        return [xi, yi]
```
![image.png](https://pic.leetcode-cn.com/85ff2e41b3c9bdd33874e2dc17d60a75a0e40e3e988269aa526863f2e9b96a14-image.png)
