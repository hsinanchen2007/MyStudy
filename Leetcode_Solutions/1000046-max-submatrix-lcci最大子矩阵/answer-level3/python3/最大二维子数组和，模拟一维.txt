# 思路
1. 逐行计算累加和，进而计算一行中各区间的和
2. dp[p][q]记录列位于[p, q]内的子数组最大和
3. 复杂度为N * M * M, 当N < M时，转置matrix
```
class Solution:
    def getMaxMatrix(self, matrix: List[List[int]]) -> List[int]:
        N, M = len(matrix), len(matrix[0])
        transposed = False
        if N < M:
            transposed = True
            matrix = list(zip(*matrix))
            N, M = M, N
        dp = [[[0, 0] for _ in range(M)] for _ in range(M)]
        maxx = -1 << 31
        r1 = c1 = r2 = c2 = -1
        for i in range(N):
            row_sum = [0]
            for j in range(M):
                row_sum.append(row_sum[-1] + matrix[i][j])
            for p in range(M):
                for q in range(p, M):
                    # print(p, q)
                    dp[p][q][0] += row_sum[q + 1] - row_sum[p]
                    if dp[p][q][0] > maxx:
                        r1, c1 = dp[p][q][1], p
                        r2, c2 = i, q
                        maxx = dp[p][q][0]
                    if dp[p][q][0] <= 0:
                        dp[p][q] = [0, i + 1]
        return [r1, c1, r2, c2] if not transposed else [c1, r1, c2, r2]
```
