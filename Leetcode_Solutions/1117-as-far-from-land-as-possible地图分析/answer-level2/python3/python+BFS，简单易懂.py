### 解题思路
此题是一个标准的广度优先题目。
基本思路就是不断模拟从陆地向海洋扩张的最长距离：
- 查找初始所有陆地坐标，并进行判断是否为空或长度与grid大小一致，满足条件即输出-1
- 定义一个判断给定坐标值是否有效的辅助函数：isValid(x, y) 
- 定义一个4向delt列表，用于从当前坐标生成新坐标，并初始化depth=-1
- 从当前陆地坐标列表开始向外扩张探索：
    - 对于每个待搜索的陆地坐标，依次生成4个方向新的坐标值
    - 若新坐标值尚未探索到，则加入到待探索列表tmp，并将其"填充"为陆地(即赋值为1)，避免重复探索 
    - 若当前深度所有陆地周边仍有待探索的海洋（即tmp不为空），则继续探测

最后，需特殊考虑depth初值问题：由于陆地初始值是已有深度，当其探索一层后方可赋值为1，所以其初始值实际上应为-1.

### 结果
![image.png](https://pic.leetcode-cn.com/f8cb723a0dd18b1f76f12c6992a53dcec740d999684706c4b1a298bff4973151-image.png)

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        nodes = [(i, j) for i in range(m) for j in range(n) if grid[i][j]]  #提取陆地坐标列表    
        if not nodes or len(nodes)==m*n:#是否为纯陆地或纯海洋
           return -1

        def isValid(x, y):#判断给定坐标是否有效
            return 0<= x <m and 0<= y <n

        depth = -1
        delt = [(0,1),(0,-1),(1,0),(-1,0)]
        while nodes:#处理当前层信息
            depth += 1
            tmp = []#存储待探索海洋坐标
            for x, y in nodes:#对当前每个待探坐标分别处理4个方向
                for d in delt:
                    newx, newy = x+d[0], y+d[1]
                    if isValid(newx, newy) and not grid[newx][newy]:#新点是海洋且未探测
                        tmp.append((newx, newy))
                        grid[newx][newy] = 1 #探测到了要给它填充陆地
            nodes = tmp
        return depth
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)