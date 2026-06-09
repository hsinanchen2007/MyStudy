instructions 重复四次一定包含一个循环。所以可以重复四次执行指令，看最后是否在原点

至于向左转向右转，就是利用坐标变换计算。
设 方向坐标$(cos(\theta),sin(\theta))$,向左转后，角度增大90°即$\pi /2$
则新坐标$(cos(\pi /2+\theta),sin(\pi /2+\theta))$等于$(-sin(\theta),cos(\theta))$
即 (dx,dy)变为(-dy,dx),同理向右转

```python3
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x=y=0
        dx,dy=0,1
        for c in instructions*4:
            if c=='G':
                x+=dx
                y+=dy
            elif c=='L':
                dx,dy = -dy,dx # cos(pi/2+theta),sin(pi/2+theta)
            else:
                dx,dy = dy,-dx
        return x==y==0
```