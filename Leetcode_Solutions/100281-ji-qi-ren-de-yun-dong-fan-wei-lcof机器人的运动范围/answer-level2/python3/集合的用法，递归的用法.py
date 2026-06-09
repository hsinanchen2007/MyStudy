### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def GetSum(self, i, j):
            i_1 = i // 10
            i_2 = i % 10
            j_1 = j // 10
            j_2 = j % 10
            return i_1 + i_2 + j_1 + j_2

        def dfs(i, j):
            if not 0 <= i < m or not 0 <= j < n or k < GetSum(self, i, j) or (i, j) in visited:
                return 0    #递归终止条件
            visited.add((i,j))
            return 1 + dfs(i+1, j) + dfs(i, j+1)

        visited = set()
        return dfs(0, 0)
```