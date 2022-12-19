### 解题思路
记得p-a/b/c那里加绝对值！否则有个用例会出来复数的面积。。内存消耗好多哦，难顶。

### 代码

```python3
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        points = list(map(lambda x:list(map(lambda x:x/1, x)) ,points))
        size = []

        for i in range(0, len(points)):
            for j in range(i+1, len(points)):
                 for k in range(j+1, len(points)):
                    a = ((points[i][0]-points[j][0])**2 + (points[i][1]-points[j][1])**2) ** 0.5
                    b = ((points[i][0]-points[k][0])**2 + (points[i][1]-points[k][1])**2) ** 0.5
                    c = ((points[k][0]-points[j][0])**2 + (points[k][1]-points[j][1])**2) ** 0.5
                    p = 1/2 * (a+b+c)
                    size.append((p * abs(p-a) * abs(p-b) * abs(p-c)) ** 0.5)

        res = max(size)

        return res
```