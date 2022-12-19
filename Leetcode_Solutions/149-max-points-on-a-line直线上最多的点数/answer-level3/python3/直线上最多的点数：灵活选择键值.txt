#### 思路：
两点确定一条直线，每次固定一个点，如果这时其他点和此点的斜率相同，则这些点在同一条直线上。另外，要考虑斜率为无穷大的情况。

```
from decimal import *
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n < 3:
            return len(points)
        
        res = 0
        for i in range(n):
            dic = {'inf':0}  # 先列出斜率正无穷的情况
            same = 0
            for j in range(n):
                if i != j:
                    if points[i][0] == points[j][0] and points[i][1] != points[j][1]:
                        dic['inf'] += 1
                    elif points[i][0] != points[j][0]:
                        k1 = self.slope(points[i],points[j])
                        if k1 in dic:
                            dic[k1] += 1
                        else:
                            dic[k1] = 1
                    else:
                        same += 1
            res = max(res,max(dic.values()) + same)
        return res + 1
    # 使用Decimal精确计算
    def slope(self,x1,x2):
        return Decimal(x2[1] - x1[1]) / Decimal(x2[0] - x1[0])
```
有几个需要解释的地方，帮助更好地理解代码，在此分享：
1. 字典`dic = {'inf':0}`表示`{与点x的斜率:点的个数}`,这个定义要放在第一个循环内，一个`dic`字典表示一个点与其它点的关系，当`i`改变时，重新定义`dic = {'inf':0}`。
2. 代码主体结构如下，主要有三部分：
  - 斜率为无穷大的情况；
  - 横坐标不同的情况，这时斜率按照定义的`slope`函数计算斜率；
  - 其他情况，即两点重合的情况，这时不同字典，用一个单独的`same`保存。
3. 字典保存的`value`值不包括该点本身，因此返回`res + 1`
