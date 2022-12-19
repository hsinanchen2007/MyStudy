#### 方法一： 暴力 【超时】

**思路和算法**

遍历所有可能的加号中心，找到其中最大的加号。这个算法的时间复杂度为 $O(N^3)$，大致估算的运算量为 $500^3 = (1.25) * 10^8$，这个复杂度是略微高出了题目要求的复杂度的。

```python [solution1-Python]
class Solution(object):
    def orderOfLargestPlusSign(self, N, mines):
        banned = {tuple(mine) for mine in mines}
        ans = 0
        for r in xrange(N):
            for c in xrange(N):
                k = 0
                while (k <= r < N-k and k <= c < N-k and
                        (r-k, c) not in banned and
                        (r+k, c) not in banned and
                        (r, c-k) not in banned and
                        (r, c+k) not in banned):
                    k += 1
                ans = max(ans, k)
        return ans
```
```java [solution2-Java]
class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        Set<Integer> banned = new HashSet();
        for (int[] mine: mines)
            banned.add(mine[0] * N + mine[1]);
            
        int ans = 0;
        for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
            int k = 0;
            while (k <= r && r < N-k && k <= c && c < N-k &&
                    !banned.contains((r-k)*N + c) &&
                    !banned.contains((r+k)*N + c) &&
                    !banned.contains(r*N + c-k) &&
                    !banned.contains(r*N + c+k))
                k++;
            
            ans = Math.max(ans, k);
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度: $O(N^3)$，遍历整个网格需要 $O(N^2)$，对于每个中心点需要遍历 $O(N)$ 次来找到 `k`。

* 空间复杂度: $O(mines.length)$。

#### 方法二： 动态规划 【通过】

**思路**

怎么提升暴力算法的性能呢？有一个方法就是加快找到 `k` 的速度。如果我们能预先计算出每个中心的最长臂长 $L_u, L_l, L_d, L_r$，那么就能知道以这个为中心的加号的阶就是 $\min(L_u, L_l, L_d, L_r)$。动态规划可以用来预先计算臂长。

**算法**

对于每个中心点坐标 `(r, c)`，从四个方向计算从 `(r, c)` 开始最长连续 `1` 的个数。用动态规划的方法来看，如果 `grid[r][c]` 是 `0`，那么臂长就是 `0`，如果 `grid[r][c]` 是 `l`, 那么臂长就是当前方向上连续 `1` 的个数再加 `1`。
举个例子，假设当前方向为左，网格中有一行为 `01110110`， 那么对应的连续 `1` 的个数就是 `012301201`。可以观察到，每个数要么是它相邻左边的数加 `1`， 要么是 `0`。
对于每个中心点，让 `dp[r][c]` 为四个方向中最小的连续 `1` 的个数。显然，`dp` 数组中最大的值就是我们要的结果。

```python [solution2-Python]
class Solution(object):
    def orderOfLargestPlusSign(self, N, mines):
        banned = {tuple(mine) for mine in mines}
        dp = [[0] * N for _ in xrange(N)]
        ans = 0
        
        for r in xrange(N):
            count = 0
            for c in xrange(N):
                count = 0 if (r,c) in banned else count+1
                dp[r][c] = count
            
            count = 0
            for c in xrange(N-1, -1, -1):
                count = 0 if (r,c) in banned else count+1
                if count < dp[r][c]: dp[r][c] = count
        
        for c in xrange(N):
            count = 0
            for r in xrange(N):
                count = 0 if (r,c) in banned else count+1
                if count < dp[r][c]: dp[r][c] = count
            
            count = 0
            for r in xrange(N-1, -1, -1):
                count = 0 if (r, c) in banned else count+1
                if count < dp[r][c]: dp[r][c] = count
                if dp[r][c] > ans: ans = dp[r][c]
        
        return ans
```

```java [solution2-Java]
class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        Set<Integer> banned = new HashSet();
        int[][] dp = new int[N][N];
        
        for (int[] mine: mines)
            banned.add(mine[0] * N + mine[1]);
        int ans = 0, count;
        
        for (int r = 0; r < N; ++r) {
            count = 0;
            for (int c = 0; c < N; ++c) {
                count = banned.contains(r*N + c) ? 0 : count + 1;
                dp[r][c] = count;
            }
            
            count = 0;
            for (int c = N-1; c >= 0; --c) {
                count = banned.contains(r*N + c) ? 0 : count + 1;
                dp[r][c] = Math.min(dp[r][c], count);
            }
        }
        
        for (int c = 0; c < N; ++c) {
            count = 0;
            for (int r = 0; r < N; ++r) {
                count = banned.contains(r*N + c) ? 0 : count + 1;
                dp[r][c] = Math.min(dp[r][c], count);
            }
            
            count = 0;
            for (int r = N-1; r >= 0; --r) {
                count = banned.contains(r*N + c) ? 0 : count + 1;
                dp[r][c] = Math.min(dp[r][c], count);
                ans = Math.max(ans, dp[r][c]);
            }
        }
        
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度: $O(N^2)$。

* 空间复杂度: $O(N^2)$，其中 $N$ 为 `dp` 数组的大小。