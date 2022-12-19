三个点在一条直线上，必须满足：三个点两两之间的斜率相等
如果不相等就不在一条直线上。
```python []
class Solution(object):
    def isBoomerang(self, points):
        c=[]
        for i in range(2):
            b=[]
            for j in range(1):
                b.append(float((points[i][j]-points[i+1][j])))
                b.append(float(points[i][j+1]-points[i+1][j+1]))
                c.append(b)
        if c[0][1]*c[1][0]==c[1][1]*c[0][0]:
            print('不是回旋镖')
            flag=False
        else:
            print('是回旋镖：')
            flag=True
        return flag
```
