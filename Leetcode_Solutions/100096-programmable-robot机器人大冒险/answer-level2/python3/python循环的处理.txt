### 解题思路
由于命令是循环的，命令同一位置的循环点是形成一个直线，判断点是否会在该直线上。
此外，注意障碍只有在起点和终点之间才会有效。

### 代码

```python3
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        r = 0
        u = 0
        direction = []
        for item in command:
            if item == 'U':
                u += 1
            elif item == 'R':
                r += 1
            direction.append((r,u))

        def helper(x,y,r,u):
            if u!=0 and r!=0:
                if x/r == y/u:
                    return True
                else:
                    return False
            else:
                if (r==0 and x == 0) or (u==0 and y ==0):
                    return True
            return False

        def meet(x,y,direction):
            r,u = direction[-1]
            if helper(x,y,r,u):
                return True
            for item in direction[:-1]:
                if helper(x-item[0],y-item[1],r,u):
                    return True
            return False
        
        # obstacles
        for obs in obstacles:
            if (obs[0] > x) or (obs[1] > y):
                continue
            if meet(obs[0],obs[1],direction):
                return False
        # end point
        if meet(x,y,direction):
            return True
        return False
```