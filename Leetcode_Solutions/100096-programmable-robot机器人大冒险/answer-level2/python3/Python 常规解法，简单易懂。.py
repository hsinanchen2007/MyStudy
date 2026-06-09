### 解题思路
**1.暴力法**
  看到题首先简单粗暴的想用暴力法破解，不断地走下去，看逐个判断是否会碰到阻碍点，再判断最终是否能走到终点。
  悲剧的是，超时了。

**2.找规律**
  在纸上自己模拟了一下题目给的例子之后，发现command = 'URR'时，机器人走过的坐标如下：
原点(0, 0) ->->-> U(0, 1) -> R(1, 1) -> **R(2, 1)** -> U(2, 2) -> R(3, 2) -> **R(3, 3)** -> U(4, 3) -> R(4, 4) -> **R(4, 5)**
仔细观察，发现自第一次command循环结束产生的前三个坐标之后的每个坐标，都是由初次循环产生的坐标加上 R(2,1) * circle(当前循环数) 得到的。
现在，先假设一下终点的坐标时可以到达的，接下来我们就可以直接计算达到目标终点时所需要的循环数：  
```
circle = min(x // xi, y // yi) # xi = 'R'的个数， yi = 'U'的个数
```
此处为什么取min，接下来会有一个比较直观的解释。得到了需要经过多少个circle才能到达终点后，我们接下来反过来计算终点坐标对应的第一次循环中的坐标。
```
x_origin, y_origin = x - xi * circle, y - yi * circle  # 若是以上不取min，此时有可能会出现 <0 的情况，明显越界了
```
计算出来之后，只需要判断这个坐标是否在初始坐标的列表中就可以了。

```
if [x - xi * circle, y - yi * circle] not in first_coor:
    return False
```
相应的，为了判断是否会在走到终点之前先走到障碍物，可以对障碍物列表中的每个点进行类似的计算，看是否会碰到它。

```
# 对每个阻碍点逐个判断，是否会走到它
for obstacle in obstacles:
    ob_x, ob_y = obstacle[0], obstacle[1]
    # 走到阻碍点所需要的循环数（若是能走到的话）
    circle = min(ob_x // xi, ob_y // yi)
    # 判断是否会走到这个阻碍点，注意在终点之后的阻碍点可以忽略
    if ob_x <= x and ob_y <= y and [ob_x - xi * circle, ob_y - yi * circle] in first_coor:
        return False 

```


### 代码

```
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:

        xi = 0
        yi = 0

        # 计算第一次执行完command后, 走过的所有坐标
        first_coor = [[0, 0]]
        for c in command:
            if c == 'R' :
                xi += 1
            else:
                yi += 1
            first_coor.append([xi, yi])
        
        # 此时(xi, yi)也代表着初次command执行结束时走到的最后一个坐标
        # 走到目标点所需要的循环次数
        circle = min(x // xi, y // yi)

        if [x - xi * circle, y - yi * circle] not in first_coor:
            return False

        # 对每个阻碍点逐个判断，是否会走到它
        for obstacle in obstacles:
            ob_x, ob_y = obstacle[0], obstacle[1]
            # 走到阻碍点所需要的循环数（若是能走到的话）
            circle = min(ob_x // xi, ob_y // yi)
            # 判断是否会走到这个阻碍点，注意在终点之后的阻碍点可以忽略
            if ob_x <= x and ob_y <= y and [ob_x - xi * circle, ob_y - yi * circle] in first_coor:
                return False 

        return True
```

时间复杂度： O(n * m) 
其中n为command的长度， m为obstacles的长度。
空间复杂度： O(m + n)

欢迎指正~！