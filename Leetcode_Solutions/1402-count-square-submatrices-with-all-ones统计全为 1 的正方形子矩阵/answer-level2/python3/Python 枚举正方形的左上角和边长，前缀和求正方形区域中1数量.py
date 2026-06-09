![image.png](https://pic.leetcode-cn.com/40c0b86ddc1ca158b65c57a74bb3b0d7276a7016a7a191753145d401e9274e48-image.png)


```
from typing import List
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])

        left_one_num = [[0 for _ in range(n)] for _ in range(m)]
        up_one_num = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                left_one_num[i][j] = matrix[i][j] if j == 0 else left_one_num[i][j-1] + matrix[i][j]
                up_one_num[i][j] = matrix[i][j] if i == 0 else up_one_num[i-1][j] + matrix[i][j]

        #枚举正方形的左上角和右下角
        ans = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    continue

                one_cnt = 1
                ans += 1

                for edge_len in range(2, min(m, n) + 1):
                    ii, jj = i + edge_len - 1,  j + edge_len - 1
                    if ii >= m or jj >= n or matrix[ii][jj] == 0:
                        break

                    left_cnt = left_one_num[ii][jj] - left_one_num[ii][j-1] if j != 0 else left_one_num[ii][jj]
                    up_cnt = up_one_num[ii][jj] - up_one_num[i-1][jj] if i != 0 else up_one_num[ii][jj]
                    one_cnt += left_cnt + up_cnt - 1
                    if one_cnt != edge_len * edge_len:
                        break

                    ans += 1

        return ans
```
