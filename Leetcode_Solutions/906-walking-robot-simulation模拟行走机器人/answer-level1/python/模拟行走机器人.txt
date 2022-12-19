### 解题思路
程序详解

### 代码

```python
class Solution(object):
    def robotSim(self, commands, obstacles):
        #机器人行走方向可以由如下列表表示
        #dir的形成是以向北开始，连续右转得来，若遇到左转，相当于连续右转三次
        dir = [(0,1),(1,0),(0,-1),(-1,0)]
        #机器人起始坐标
        x,y = 0,0
        #起始方向为dir[0]
        d = 0
        #对obstacles取set,简便计算 转换成元组速度较列表快
        obstacles = set(map(tuple,obstacles))
        #根据commands判断行进方向
        ans = 0
        for c in commands:
            if c == -1: #右转
                d = (d + 1) % 4
            if c == -2: #左转
                d = (d + 3) % 4
            else:
                for i in range(c):
                    if (x + dir[d][0],y + dir[d][1]) not in obstacles:
                        x += dir[d][0]
                        y += dir[d][1]
                        ans = max(ans,x**2 + y**2)     
        return ans
```