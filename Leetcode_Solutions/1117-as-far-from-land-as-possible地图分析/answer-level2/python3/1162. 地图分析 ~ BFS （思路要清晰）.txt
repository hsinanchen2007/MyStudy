### 解题思路
`你知道距离陆地区域最远的海洋区域是是哪一个吗, 返回该海洋区域到离它最近的陆地区域的距离。`如何理解？？
> 每个海洋到陆地都会有一个最近的的陆地，我们记录每个海洋到最近陆地的距离，然后在所有距离中取最大值，即最远海洋到离它最近的距离

**第一想法（从海洋的角度出发）** --> 对每个海洋进行BFS遍历：
> 只要碰到陆地立马返回最近的距离， 然后对所以的距离去最小值即可！！但是这样的做法复杂度很高O(n^2)，因为每个海洋都要进行一次BFS。

**第二想法（从陆地角度出发）** --> 对所有的陆地进行BFS遍历（其实就是多源的BFS）：
> 这是什么意思呢？就是开始的时候对列里面有超过1的元素等待出队，简单说就相当于单源BFS的第二层的BFS!!

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        ans = -1
        temp1 = [[0] * len(grid[0]) for _ in range(len(grid))] # 全是海洋
        temp2 = [[1] * len(grid[0]) for _ in range(len(grid))] # 全是陆地
        if grid == temp1 or grid == temp2:
            return -1
        queue = []
        for i in range(len(grid)): # 所有的陆地入队
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    queue.append((i, j))
        dis = 0
        while queue:
            n = len(queue)  
            dis += 1
            for _ in range(n):
                cur_i, cur_j = queue.pop(0)
                for dx, dy in directions:
                    next_i, next_j = cur_i + dx, cur_j + dy

                    if next_i in range(0, len(grid)) and next_j in range(0, len(grid[0])) and grid[next_i][next_j] == 0:
                        queue.append((next_i, next_j))
                        grid[next_i][next_j] = 1 # 利用原数组记录访问信息
            

        return dis - 1



```