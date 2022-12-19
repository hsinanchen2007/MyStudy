### 解题思路
解读一下python里耗时最短的方法：
`prefix`用来O(1)存取`sum(stones[i:j+1])`
状态转移方程：
`dp[i][j]`代表【从i到j合并为最少堆的最小代价】
m：每次合并的区间长度，从K到N。m<K时已经初始化为0，所以不用遍历。
`dp[i][i+m-1] = min(dp[i][k] + dp[k+1][i+m-1] for k in range(i, i+m-1, K-1)) + (prefix[i+m] - prefix[i] if (m-1)%(K-1) == 0 else 0)`
分析：
1. `min(dp[i][k] + dp[k+1][i+m-1] for k in range(i, i+m-1, K-1)) `：
之前已有的合并代价。为什么是`k in range(i, i+m-1, K-1)`？本质是需要左边的区间能够合并成一堆，或本身就只有一堆，右边的是减去这一堆后剩下的堆。若步长不为K-1，那么左右两堆合并时并不能确定合并的方式，比如 K=5，左边0~3，右边4~7，那还得计算是合并0~4？还是1~5？2~6？3~7？
2. `prefix[i+m] - prefix[i] if (m-1)%(K-1) == 0 else 0`：
当`(m-1)%(K-1) == 0`时，可以也必须进行合并成一堆的工作，此时用`prefix`计算合并代价。

这种方式下`dp[0][n-1]`本身的值看不出是否能合并成一堆，所以必须预先计算，所以开头有`if (N - 1) % (K - 1): return -1`


### 代码

```python3
class Solution:
    def mergeStones(self, stones: List[int], K: int) -> int:
        N = len(stones)
        if (N - 1) % (K - 1): return -1
        prefix = [0] * (N+1)
        for i in range(1,N+1): prefix[i] = stones[i-1] + prefix[i-1]
        dp = [[0] * N for _ in range(N)]
        for m in range(K, N+1):
            for i in range(N-m+1):
                dp[i][i+m-1] = min(dp[i][k] + dp[k+1][i+m-1] for k in range(i, i+m-1, K-1)) + (prefix[i+m] - prefix[i] if (m-1)%(K-1) == 0 else 0)
        return dp[0][N-1]
```