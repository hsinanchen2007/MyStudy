# **解题思路：**
本题每一步做决策的过程实际上可以理解为，在能走的范围内，走使得路径分数尽可能大的点，也就是说可以抽象成在一个优先级队列找最大值的过程。

以示例1为例：

![image.png](https://pic.leetcode-cn.com/aaa44d7b56b4095f2b2ad61b345fe6281cbbe4e1830667f82ee72508f0137b3f-image.png){:width="130px"}
{:align="center"}

一开始从点`(0， 0)`出发，起始分数为`5`。

可以走的路有两条：

1. 往右到点`(0, 1)`，走这条会使得路径的分数变成`4 = min(5, 4)`, 其中`5`是从起点到当前点的分数，`4`是下一个点的值

2. 往下到点`(1, 0)`，走这条会使得路径的分数变成`1 = min(5, 1)`

选哪条呢，显然为了实现让路径最小值尽可能大的题目目标，我们应该选择往右走到点`(0, 1)`。

到达4之后，又多了两个选择：
1. 往右到点`(2, 0)`, 分数还是`4 = min(4, 5)`
2. 往下到点`(1, 1)`，分数变为`2 = min(4, 2)`

目前可选的点有三个，分别会让其所在的路径的分数变成`4`， `2`和`1`， 因而选择最大的4，即往右走到达点`(0, 2)`

以此类推，每次选择前往 能使所在路径分数尽可能大的点，当到达终点时，返回分数即可。

# **代码实现**：
```Python
class Solution(object):
    def maximumMinimumPath(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        from heapq import *
        if not A or not A[0]:
            return 0
        
        m, n = len(A), len(A[0])
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        
        queue = [[-A[0][0], 0, 0]] #Python默认最小堆，因此需要手动用相反数实现最大堆……
        visited = set([0,0])
        heapify(queue)

        while queue:
            score, x0, y0 = heappop(queue) #把目前队里最优的点找出来，三个值分别代表分数， X坐标， Y坐标
            if [x0, y0] == [m - 1, n - 1]: #如果已经到终点了
                return -score #输出结果时记得再取一次相反数
            
            for k in range(4): #找四个可能的邻居点
                x = x0 + dx[k]
                y = y0 + dy[k]
                
                if 0 <= x < m and 0 <= y < n and (x, y) not in visited:#邻居点可走
                    visited.add((x, y))
                    heappush(queue, [max(score, -A[x][y]), x, y]) #邻居点入队，调整分数，因为取了相反数所以找最小值用max不用min
```
# **复杂度分析：**
时间复杂度： $O（MN）$

空间复杂度： $O（MN）$