### 解题思路
1. 遍历points，如点i，计算i与[i+1,i+2,...,n-1]这些点的斜率，其中斜率相同的点在一条直线上；计算直线上最多的点数；
2. 遍历的过程中有几点需要注意，如：1. points中存在重叠的点；2. 因为浮点数的精度问题，不能直接将两数相除作为斜率进行存储，如[0,0],[94911151,94911150],[94911152,94911151]这三个点，如果将斜率用浮点数进行存储，则它们在同一条直线上，但事实并不是；

### 代码

```python3
class Solution:
    """
    注意
    1. 可能存在重叠的点；
    2. python中，当a很大时，a/(a+1) == (a+2)/(a+1)为真；因此通过斜率是否相等来判断三个点是否在同一条直线上并不靠谱；
    3. 为了解决python中浮点数存在的精度问题，这里的斜率用元组的形式存储，即slope=a/b用(a,b)来存储，其中a,b是最简分数的分子与分母；
    """
    def func(self, u, v):
        # 求最大公约数，用辗转相除法
        x, y = u, v
        if u<v:
            u, v = v, u

        r = u%v
        while r!=0:
            u, v = v, r
            r = u%v
        return (x//v, y//v) if x//v > 0 else (-x//v, -y//v)

    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 2:
            return len(points)
        
        max_points = 2
        for i in range(len(points)-1):
            slope_dict = dict()
            overlap = 0
            for j in range(i+1, len(points)):
                if (points[i][0]-points[j][0])==0  and (points[i][1]-points[j][1]) ==0:
                    overlap += 1
                    continue
                elif (points[i][0]-points[j][0])==0:
                    tmp = 'vert'
                elif points[i][1]-points[j][1] == 0:
                    tmp = 0
                else:
                    tmp = self.func(points[i][1]-points[j][1], points[i][0]-points[j][0])
                
                try:
                    slope_dict[tmp] += 1
                except:
                    slope_dict[tmp] = 2
            max_val = max(slope_dict.values()) if slope_dict else 1
            max_points = max_val+overlap if max_val+overlap > max_points else max_points
        return max_points
```