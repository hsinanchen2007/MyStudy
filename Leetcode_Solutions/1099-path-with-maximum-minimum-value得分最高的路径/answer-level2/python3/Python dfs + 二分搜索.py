
![image.png](https://pic.leetcode-cn.com/781b57c59ada9964ad5e342b5706b1291bf9f9218478f5fdff6a12b90bafb713-image.png)



```

'''
假设起点和终点较小值是n
则中间路径最小值一定在0 n之间，二分找这个数值，如果将某数值
作为路径中出现值的最小可能值能够从起点走到终点，该值就可以作为
一个候选，找所有候选值中最大的即可, 注意优先往右下走才能快速
剪枝回溯
'''

from typing import List
class Solution:

    def dfs(self, A, i, j, m, n, visited, min_val, depth) -> bool:
        if i == m-1 and j == n-1:
            return True

        visited[i][j] = 1
        for ii, jj in [(i, j+1), (i+1, j), (i, j-1), (i-1, j)]:
            if ii >= 0 and ii < m and jj >= 0 and jj < n and visited[ii][jj] == 0 and A[ii][jj] >= min_val:
                if self.dfs(A, ii, jj, m, n, visited, min_val, depth+1) == True:
                    visited[i][j] = 0
                    return True

        return False


    def maximumMinimumPath(self, A: List[List[int]]) -> int:
        m, n = len(A), len(A[0])
        l, r = 1, min(A[0][0], A[-1][-1])

        ans = 0
        visited = [[0 for _ in range(n)] for _ in range(m)]
        while l <= r:
            mid = l + (r - l) // 2
            if self.dfs(A, 0, 0, m, n, [[0 for _ in range(n)] for _ in range(m)], mid, 0):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans
```
