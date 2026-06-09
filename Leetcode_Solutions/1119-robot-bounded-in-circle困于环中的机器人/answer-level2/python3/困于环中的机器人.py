有两种情况机器人会被困在一个环内，一是它执行了一轮指令后回到了原点，或者是它执行了一轮指令后机器人朝向发生了改变。在用代码实现的时候，可以用一个整型变量来记录机器人当前的朝向，0、1、2、3分别代表上、右、下、左，同时还需要记录当前机器人的坐标。在一轮指令后利用上述变量，根据前面的分析就可以判断出机器人是否会被困在一个环内。  
```Python
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        direction = 0
        x = 0
        y = 0
        for i in instructions:
            if i == 'L':
                direction -= 1
            elif i == 'R':
                direction += 1
            else:
                direction %= 4
                if direction == 0:
                    y += 1
                elif direction == 1:
                    x += 1
                elif direction == 2:
                    y -= 1
                else:
                    x -= 1
        return direction % 4 != 0 or (x == 0 and y == 0)
```