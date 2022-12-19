### 解题思路
1. 定义递归函数的意义： 在此处，dfs定义为返回以i,j为坐标的点为起点，可以到达点的树木
2. 定义初始条件，很显然如果i,j超出了边界，即`i>m-1 or j>n-1`,显然是返回0的，同时这个点超出了界定条件，即数位之和大于k，也是返回0的。此外，为了防止重复计数，用一个grid矩阵记录我们走过的格子，因为我们从每个格子都要走到能走的每一个格子，所以第二次到这个格子的时候，这个格子能去的新格子数是0。
3. 确定递归条件，就是当前这1格加上从能到达的格子开始的格子数`1+dfs(i+1,j)+dfs(i,j+1)`
### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        res = 0
        grid  = [[0]*n for _ in range(m)]
        #求数位之和
        def helper(x):
            if x == 100: return 1
            if x<10: return x
            else:return x//10 + x%10

        def dfs(i,j):
            if (helper(i)+helper(j)) > k:
                return 0
            if i>m-1 or j>n-1 or grid[i][j] == 1:
                return 0

            grid[i][j] = 1
            return 1+dfs(i+1,j)+dfs(i,j+1)

        return dfs(0,0)

```