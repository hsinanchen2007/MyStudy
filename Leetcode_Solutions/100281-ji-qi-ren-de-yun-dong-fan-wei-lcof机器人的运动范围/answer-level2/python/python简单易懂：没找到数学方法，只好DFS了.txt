### 解题思路
直觉是用数学推导，细想之下发现有很多细节。所以还不如省省大脑，用电脑去算了
主要思路：
- 因为涉及到机器人的逐步移位过程，所以不是简单的判断有多少个格子满足要求，因为可能机器人过不去
- 又由于未限定机器人一定只能朝某些方向走，也不限定同个格子只能走一次等，所以这不是动态规划
- 实际上，这是一个探测题，探测从给定起点能到达的终点个数，那么可以用DFS也可以用BFS。
- 基本实现：
    - 定义一个判断给定坐标是否满足要求的辅助函数`can()`，按定义判断即可
    - 定义一个判断给定坐标是否超出范围的辅助函数`isvalid()`，在m、n合理区间就行
    - 定义一个辅助函数`DFS()`，递归调用其4个方向的，当然是要用标记法记录哪些已走过
    - 原点坐标肯定可以走，从此开始探测，能到的就到了，到不了的就到不了
    - 计算可以到达的坐标个数即可

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def can(i, j):
            return k >= sum([int(num) for num in str(i)+str(j)])
        
        def isvalid(i, j):
            return 0<=i<m and 0<=j<n
        
        def DFS(i, j):
            for dx, dy in delt:
                x, y = i+dx, j+dy
                if isvalid(x, y) and can(x, y) and not flags[x][y]:
                    flags[x][y] = 1
                    DFS(x, y)
        
        flags = [[0]*n for _ in range(m)]
        flags[0][0] = 1
        delt = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        DFS(0, 0)
        return sum([sum(flag) for flag in flags])
```
欢迎关注个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)