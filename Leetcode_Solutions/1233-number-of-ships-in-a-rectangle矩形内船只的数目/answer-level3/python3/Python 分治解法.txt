![image.png](https://pic.leetcode-cn.com/e151b199321dbe08950052c4893753731582ceb095c834d5852d9b8258d2de09-image.png)


```

'''
分治求解，每次把范围均分成四等分，分别统计4个等分块里面的船的坐标，然后再
归并在一起
'''

from itertools import chain
from functools import lru_cache

class Solution(object):

    def hasShips(self, p1, p2):
        if not (p1[0] >= p2[0] and p1[1] >= p2[1]):
            return False

        return self.sea.hasShips(Point(p1[0], p1[1]), Point(p2[0], p2[1]))

    # 获取区域内所有船坐标列表
    def getShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point'):
        self.sea = sea

        x1, y1 = bottomLeft.x, bottomLeft.y
        x2, y2 = topRight.x, topRight.y

        #print(x1, y1, x2, y2)

        if x1 == x2 and y1 == y2:
            return [(x1, y1)] if self.hasShips((x1, y1), (x2, y2)) else []

        if x1 == x2:
            return [(x1, y) for y in range(y1, y2+1) if self.hasShips((x1, y), (x1, y))]
        if y1 == y2:
            return [(x, y1) for x in range(x1, x2+1) if self.hasShips((x, y1), (x, y1))]

        if x2 - x1 == 1 and y2 - y1 == 1:
            return [(x, y) for x, y in [(x1, y1), (x1, y2), (x2, y1), (x2, y2)] if self.hasShips((x, y), (x, y))]

        mid_x, mid_y = (x1 + x2) // 2, (y1 + y2) // 2
        l1 = self.getShips(sea, Point(mid_x, y2), Point(x1, mid_y+1)) if self.hasShips((mid_x, y2), (x1, mid_y+1)) else []
        l2 = self.getShips(sea, Point(x2, y2), Point(mid_x+1, mid_y+1)) if self.hasShips((x2, y2), (mid_x+1, mid_y+1)) else []
        l3 = self.getShips(sea, Point(mid_x, mid_y), Point(x1, y1)) if self.hasShips((mid_x, mid_y), (x1, y1)) else []
        l4 = self.getShips(sea, Point(x2, mid_y), Point(mid_x+1, y1)) if self.hasShips((x2, mid_y), (mid_x+1, y1)) else []
        s = set((x, y) for x, y in chain(l1, l2, l3, l4))
        return list(s)

    def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        return len(self.getShips(sea, topRight, bottomLeft))


```
