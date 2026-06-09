### 解题思路
1、根据几何公式ax+b=y计算出a,b,其中有个特例就是x=c,c是常数
2、题目有个精度问题[[0,0],[94911151,94911150],[94911152,94911151]],使用Decimal对象计算a,b
3、计算相同坐标点出现数，对一条直线上的点进行相加

### 代码

```python3
import itertools
import collections
from decimal import Decimal

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 1:
            return len(points)
        dict = collections.defaultdict(set)
        for point1, point2 in itertools.combinations(points, 2):
            print(point1, point2)
            point1 = tuple(point1)
            point2 = tuple(point2)
            # 处理x=c, 避免除0
            if point1[0] == point2[0]:
                a = Decimal(point1[0])
                b = Decimal(float('inf'))
            else:
                # 计算ax + b = y, 计算a,
                # ax + b = y
                # a = (y1 - y2) / (x1 - x2)
                # b = (y2 * x1 - y1 * x2) / (x1 - x2)
                # 根据精度a = ax / ay, b = bx / by; ax, ay
                # np.set_printoptions(precision=32)

                ax = Decimal(point1[1] - point2[1])
                ay = Decimal(point1[0] - point2[0])
                bx = Decimal(point2[1] * point1[0] - point1[1] * point2[0])
                by = Decimal(point1[0] - point2[0])
                a = ax / ay
                b = bx / by

                # a = round(a, 5)
                # b = round(b, 5)
            if not dict.__contains__((a, b)):
                dict[a, b] = set()

            dict[a, b].add(point1)
            dict[a, b].add(point2)

        points_stat = collections.defaultdict(int)
        for point in points:
            point = tuple(point)
            points_stat[point] = points_stat[point] + 1
        result = 0
        for set_points in dict.values():
            num_point = 0
            for point in set_points:
                point = tuple(point)
                num_point += points_stat[point]
            result = max(result, num_point)
        return result


```