#### 方法一：动态规划加二分搜索

**思路**

很容易想到用动态规划来做这道题，之前也做过这道题。状态可以表示成 `(K, N)`: `K` 为鸡蛋数和 `N` 为楼层数。当从第 `X` 楼扔鸡蛋的时候，要么鸡蛋不碎，状态变成 `(K, N-X)`，或者碎掉，状态变成 `(K-1, X-1)`。

动态规划的时间复杂度为 $O(K N^2)$，但对于这道题其实是不够高效的，可以做地更快。定义 `dp(K, N)` 为状态 `(K, N)` 下最多需要的步数。根据以上分析：

$$
dp(K, N) = \min\limits_{1 \leq X \leq N} \Big( \max(dp(K-1, X-1), dp(K, N-X)) \Big)
$$

这里需要注意的是， $\text{dp}(K, N)$ 是一个关于 N 的递增函数。在最大式中，第一项 $\mathcal{T_1} = \text{dp}(K-1, X-1)$ 是一个随 $X$ 递增的函数，第二项 $\mathcal{T_2} = \text{dp}(K, N-X)$ 也是一个随着 $X$ 递减的方法。这种情况下是可以用二分搜索去找 $X$ 的。

**算法**

对于一个  $X$，如果 $\mathcal{T_1} < \mathcal{T_2}$，意味着 $X$ 的太小了；如果 $\mathcal{T_1} > \mathcal{T_2}$，意味着 $X$ 太大了。

```java [solution1-Java]
class Solution {
    public int superEggDrop(int K, int N) {
        return dp(K, N);
    }

    Map<Integer, Integer> memo = new HashMap();
    public int dp(int K, int N) {
        if (!memo.containsKey(N * 100 + K)) {
            int ans;
            if (N == 0)
                ans = 0;
            else if (K == 1)
                ans = N;
            else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2)
                        lo = x;
                    else if (t1 > t2)
                        hi = x;
                    else
                        lo = hi = x;
                }

                ans = 1 + Math.min(Math.max(dp(K-1, lo-1), dp(K, N-lo)),
                                   Math.max(dp(K-1, hi-1), dp(K, N-hi)));
            }

            memo.put(N * 100 + K, ans);
        }

        return memo.get(N * 100 + K);
    }
}
```

```python [solution1-Python]
class Solution(object):
    def superEggDrop(self, K, N):
        memo = {}
        def dp(k, n):
            if (k, n) not in memo:
                if n == 0:
                    ans = 0
                elif k == 1:
                    ans = n
                else:
                    lo, hi = 1, n
                    # keep a gap of 2 X values to manually check later
                    while lo + 1 < hi:
                        x = (lo + hi) / 2
                        t1 = dp(k-1, x-1)
                        t2 = dp(k, n-x)

                        if t1 < t2:
                            lo = x
                        elif t1 > t2:
                            hi = x
                        else:
                            lo = hi = x

                    ans = 1 + min(max(dp(k-1, x-1), dp(k, n-x))
                                  for x in (lo, hi))

                memo[k, n] = ans
            return memo[k, n]

        return dp(K, N)
```

**复杂度分析**

* 时间复杂度： $O(K * N \log N)$。

* 空间复杂度： $O(K * N)$。

#### 方法二： 基于最优策略的动态规划

**思路**

在 $K$ 个鸡蛋 $N$ 层楼的情况下, 定义状态为 $dp}K, N)$:

$$
dp(K, N) = \min\limits_{1 \leq X \leq N} \Big( \max(dp(K-1, X-1), dp(K, N-X)) \Big)
$$

假设 $X_{\emptyset} = opt(K, N)$ 是满足 $dp(K, N)$ 最小的 $X$。

$$
dp(K, N) = \Big( \max(dp(K-1, X_{\emptyset}-1), dp(K, N-X_{\emptyset})) \Big)
$$

$opt(K, N)$ 是一个随着 $N$ 递增的函数。 在 **最大** 表达式中， $T_1 = dp(K-1, X-1)$ 随 $X$ 递增的，$T_2 = dp(K, N-X)$ 随 $X$ 递减。将 $T_1, T_2$ 两个函数图像的交点即为 $X_{\emptyset} = opt(K, N)$ 。 

**算法**

自底向上的动态规划，设 $X_{\emptyset} = opt(K, N)$：

$$
dp(K, N) = \min\limits_{1 \leq X \leq N} \Big( \max(dp(K-1, X-1), dp(K, N-X)) \Big)
$$

```java [solution2-Java]
class Solution {
    public int superEggDrop(int K, int N) {
        // Right now, dp[i] represents dp(1, i)
        int[] dp = new int[N+1];
        for (int i = 0; i <= N; ++i)
            dp[i] = i;

        for (int k = 2; k <= K; ++k) {
            // Now, we will develop dp2[i] = dp(k, i)
            int[] dp2 = new int[N+1];
            int x = 1;
            for (int n = 1; n <= N; ++n) {
                // Let's find dp2[n] = dp(k, n)
                // Increase our optimal x while we can make our answer better.
                // Notice max(dp[x-1], dp2[n-x]) > max(dp[x], dp2[n-x-1])
                // is simply max(T1(x-1), T2(x-1)) > max(T1(x), T2(x)).
                while (x < n && Math.max(dp[x-1], dp2[n-x]) > Math.max(dp[x], dp2[n-x-1]))
                    x++;

                // The final answer happens at this x.
                dp2[n] = 1 + Math.max(dp[x-1], dp2[n-x]);
            }

            dp = dp2;
        }

        return dp[N];
    }
}
```

```python [solution2-Python]
class Solution(object):
    def superEggDrop(self, K, N):

        # Right now, dp[i] represents dp(1, i)
        dp = range(N+1)

        for k in xrange(2, K+1):
            # Now, we will develop dp2[i] = dp(k, i)
            dp2 = [0]
            x = 1
            for n in xrange(1, N+1):
                # Let's find dp2[n] = dp(k, n)
                # Increase our optimal x while we can make our answer better.
                # Notice max(dp[x-1], dp2[n-x]) > max(dp[x], dp2[n-x-1])
                # is simply max(T1(x-1), T2(x-1)) > max(T1(x), T2(x)).
                while x < n and max(dp[x-1], dp2[n-x]) > \
                                max(dp[x], dp2[n-x-1]):
                    x += 1

                # The final answer happens at this x.
                dp2.append(1 + max(dp[x-1], dp2[n-x]))

            dp = dp2

        return dp[-1]
```

**复杂度分析**

* 时间复杂度： $O(K * N)$。

* 空间复杂度： $O(N)$。



#### 方法三：数学法

**思路**

反过来问这个问题：$T$ 次操作，$K$ 个鸡蛋，最高 $f(T, K)$ 楼一定能找到答案，也就是超过这个层数就一定找不到答案。接着问题就变成了找到满足 $f(T, K) \geq N$ 最小的 $T$。T 越小越好，$f$ 随着 $T$ 递增，可以用二分搜索来找到最小的 T。

定义一个递归方法 $f$。如果最优策略是从 $X_{\emptyset}$ 丢鸡蛋，如果鸡蛋碎了，继续解决 $f(T-1, K-1)$，如果不碎，继续解决 $f(T-1, K)$ 。 

$$
f(T, K) = 1 + f(T-1, K-1) + f(T-1, K)
$$

同时，当 $t \geq 1$ 的时候 $f(t, 1) = t$，当 $k \geq 1$ 时，$f(1, k) = 1$。

令 $g(t, k) = f(t, k) - f(t, k-1)$：

$$
f(T, K) = 1 + f(T-1, K-1) + f(T-1, K)
$$

$$
f(T, K-1) = 1 + f(T-1, K-2) + f(T-1, K-1)
$$

可以得出：

$$
g(t, k) = g(t-1, k) + g(t-1, k-1)
$$


二项式递归 $g(t, k) = \binom{t}{k+1}$，

$$
f(t, k) = \sum\limits_{1 \leq x \leq K} g(t, x) = \sum\limits_{0 \leq x \leq K} \binom{t}{x}
$$

**算法**

总结一下算法，递增函数 $f(t, K) = \sum\limits_{1 \leq x \leq K} \binom{t}{x}$，需要找到满足 $f(t, K) \geq N$ 的最小 $t$，用二分搜索来找。

$\sum\limits_{0 \leq x \leq K} \binom{t}{x}$ 可以转化成 $\binom{n}{k} * \frac{n-k}{k+1} = \binom{n}{k+1}$。

```java [solution3-Java]
class Solution {
    public int superEggDrop(int K, int N) {
        int lo = 1, hi = N;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (f(mi, K, N) < N)
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }

    public int f(int x, int K, int N) {
        int ans = 0, r = 1;
        for (int i = 1; i <= K; ++i) {
            r *= x-i+1;
            r /= i;
            ans += r;
            if (ans >= N) break;
        }
        return ans;
    }
}
```

```python [solution3-Python]
class Solution(object):
    def superEggDrop(self, K, N):
        def f(x):
            ans = 0
            r = 1
            for i in range(1, K+1):
                r *= x-i+1
                r //= i
                ans += r
                if ans >= N: break
            return ans

        lo, hi = 1, N
        while lo < hi:
            mi = (lo + hi) // 2
            if f(mi) < N:
                lo = mi + 1
            else:
                hi = mi
        return lo
```

**复杂度分析**

* 时间复杂度： $O(K * \log N)$。

* 空间复杂度： $O(1)$。