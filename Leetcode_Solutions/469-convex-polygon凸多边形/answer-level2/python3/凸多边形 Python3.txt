### 解题思路
执行用时 :236 ms, 在所有 Python3 提交中击败了42.31%的用户
内存消耗 :18.4 MB, 在所有 Python3 提交中击败了10.00%的用户

依次选取三个点做叉乘得到value：
记录上次叉乘的结果为pre_value
1. pre_value*value<0: 方向发生变化，不是凸多边形
2. pre_value*value>0: 方向没有发生变化，更新pre_value为value
2. value=0: 三个点在一条直线上，不更新pre_value

### 代码

```python3
class Solution:
    def isConvex(self, points: List[List[int]]) -> bool:
        
        pre_value = 0
        
        for i in range(len(points)):
            p0 = points[i]
            p1 = points[(i+1) % len(points)]
            p2 = points[(i+2) % len(points)]
            x1 = p1[0] - p0[0]
            y1 = p1[1] - p0[1]
            x2 = p2[0] - p0[0]
            y2 = p2[1] - p0[1]
            value = x1*y2 - x2*y1
            if value*pre_value < 0:
                return False
            if value != 0:
                pre_value = value

        return True
```