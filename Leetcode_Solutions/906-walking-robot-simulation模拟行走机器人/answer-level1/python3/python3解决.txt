**注意点：**
* 找规律
* 机器人行走中，最远的距离，而不是终点的距离

```python
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        di, x, y = 0, 0, 0
        distance = 0
        obs_dict = {}
        # 这一步很重要，因为后面有很多次需要进行判断是否存在
        # list的查找的复杂度明显高于dict的O(1)，提前转，节省很多消耗
        for obs in obstacles:
            obs_dict[tuple(obs)] = 0
        for com in commands:
            if com == -2:
                di = (di + 3)%4
            elif com == -1:
                di = (di + 1)%4
            else:
                for j in range(com):
                    next_x = x + dx[di]
                    next_y = y + dy[di]
                    if (next_x, next_y) in obs_dict:
                        break
                    x, y = next_x, next_y
                    distance = max(distance, x*x + y*y)
        return distance
```

我觉得说思路不难，难就难在这么找到在各个坐标上左转右转后坐标的计算上，这个才是最麻烦的。我想了很久，画了坐标轴，没总结出来，看了官方题解给记下来了。

dx和dy，要么有x要么有y，所以同一个位置，只能一个不为0，剩下的就是，要么正要么负，最后弄出个公式出来。这一步我觉得才是最麻烦的！

上面的代码还可以再简化些：坐标dx，dy用一个元组来表示，元组比列表占用空间更小，一个元组也比两个list要快！
```python
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        x_y = ((0, 1), (1, 0), (0, -1), (-1, 0))
        di, x, y = 0, 0, 0
        distance = 0
        obs_dict = {}
        for obs in obstacles:
            obs_dict[tuple(obs)] = 0
        for com in commands:
            if com == -2:
                di = (di + 3)%4
            elif com == -1:
                di = (di + 1)%4
            else:
                for j in range(com):
                    dx, dy = x_y[di]
                    next_x = x + dx
                    next_y = y + dy
                    if (next_x, next_y) in obs_dict:
                        break
                    x, y = next_x, next_y
                    distance = max(distance, x*x + y*y)
        return distance
```

在国际站看到，还有一种找规律的方式，我觉得更好理解：
* 左转:-2时  dx, dy = -dy, dx
* 右转：-1时 dx, dy = dy, -dx
这种方式比上面的计算%4后的余数更好懂，可能只是对我而言更好理解：
最开始是面北而行，x,y方向的速度肯定是（0，1），dx,dy的初始值就为0， 1
然后画图把每个方向的速度标出来，找规律，就很容易发现了。
实现的代码如下：
```python
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dx, dy, x, y = 0, 1, 0, 0
        distance = 0
        obs_dict = {}
        for obs in obstacles:
            obs_dict[tuple(obs)] = 0
        for com in commands:
            if com == -2:
                dx, dy = -dy, dx
            elif com == -1:
                dx, dy = dy, -dx
            else:
                for j in range(com):
                    next_x = x + dx
                    next_y = y + dy
                    if (next_x, next_y) in obs_dict:
                        break
                    x, y = next_x, next_y
                    distance = max(distance, x*x + y*y)
        return distance
```