### 解题思路
我们需要两个全局变量：标志数组和计数变量；需要一个函数来计算行坐标和列坐标的数位之和；终止条件包括三种情况：越界、重复、行坐标和列坐标的数位之和超过阈值


### 代码

```
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        if k<0 or m<=0 or n<=0: return 0
        visited = [0 for _ in range(m*n)]
        count = self.helper(k, m, n, 0, 0, visited)
        return count
    
    def helper(self, k, rows, cols, i, j, visited):
        index = i*cols + j
        count = 0
        if i>=0 and i<rows and j>=0 and j<cols and sum(map(int, str(i)))+sum(map(int, str(j)))<=k and not visited[index]:
            visited[index] = 1
            count = 1 + self.helper(k, rows, cols, i-1, j, visited)\
            + self.helper(k, rows, cols, i+1, j, visited)\
            + self.helper(k, rows, cols, i, j-1, visited)\
            + self.helper(k, rows, cols, i, j+1, visited)
        return count

```
