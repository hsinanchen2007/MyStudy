### 解题思路
DFS解法，将可访问的点置为1，然后求数组和
注：这是因为python中函数的可变参数是可以改变的，如果用count不行，因为count是不可变参数

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        visited = [[0] * n for _ in range(m)]
        self.dfs(visited, 0, 0, m, n, k)
        return sum(map(sum, visited))


    def dfs(self, visited, i, j, m, n, k):
        if not 0 <= i <= m - 1 or  not 0 <= j <= n - 1 or \
            self.sumbit(i) + self.sumbit(j) > k or visited[i][j] == 1:
            return

        visited[i][j] = 1

        self.dfs(visited, i, j+1, m, n, k)
        self.dfs(visited, i, j-1, m, n, k)
        self.dfs(visited, i+1, j, m, n, k)
        self.dfs(visited, i-1, j, m, n, k)


    def sumbit(self, a):
        val = 0 
        while a:
            val += a % 10 
            a = a // 10
        return val 

```