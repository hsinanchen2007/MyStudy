### 解题思路
一开始尝试了一下一步一步去判断结果超时了，于是换了一个思路。
newO存所有x和y都小于终点xy的障碍物(只有xy都小于终点xy才可能会碰到)。
xx和yy是执行一次command, x和y的值。
reach()是根据command, xx, yy来判断是否(x,y)可以走到,可以返回True，不可以则False。
先判断是否可以走到终点，如果不行直接return False。
如果可以走到终点，再遍历所有newO，是否会走到障碍物上，如果可以则返回False。
如果没有走到任何障碍物上返回True
### 代码

```python3
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        newO = []
        for o in obstacles:
            if o[0] > x or o[1] > y:
                continue
            else:
                newO.append(o)

        xx = 0
        yy = 0
        for s in command:
            if s == "U":
                yy += 1
            else:
                xx += 1
        if self.reach(x,y,xx,yy,command):
            for o in newO:
                if self.reach(o[0],o[1],xx,yy,command):
                    return False
            return True
        else:
            return False

        
    def reach(self, x1,y1,xx,yy,command):
        start = int((x1+y1)/(xx+yy))
        point = [start*xx, start*yy]
        step = (x1+y1)%(xx+yy)
        if step != 0:
            for s in command[:step]:
                if s == "U":
                    point[1] += 1
                else:
                    point[0] += 1
        if x1 == point[0] and y1 == point[1]:
            return True
        else:
            return False
```
![图片.png](https://pic.leetcode-cn.com/6bcb42147fcc5750c32342bdd39b11369f66a2e46f466d8afc05087cdaeaf7c3-%E5%9B%BE%E7%89%87.png)
