#### 方法一： 动态规划 【超内存】

**思路**

定义 `dp[n][k]` 表示增加 `k` 个加油站之后前 `n` 个加油站之间最小的最大距离。

**思路**

定义第 `i` 个间隔为 `deltas[i] = stations[i+1] - stations[i]`，用递归来计算 dp[n+1][k]。将 `x` 个加油站平均放在第 `n+1` 个间隔之间可以得到的间隔距离为 `deltas[n+1] / (x+1)`，全局最小的最大距离可以通过和 `dp[n][k-x]` 比较来得到。用动态规划来实现这个递归方法。

```java [solution1-Java]
class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        double[] deltas = new double[N-1];
        for (int i = 0; i < N-1; ++i)
            deltas[i] = stations[i+1] - stations[i];

        double[][] dp = new double[N-1][K+1];
        //dp[i][j] = answer for deltas[:i+1] when adding j gas stations
        for (int i = 0; i <= K; ++i)
            dp[0][i] = deltas[0] / (i+1);

        for (int p = 1; p < N-1; ++p)
            for (int k = 0; k <= K; ++k) {
                double bns = 999999999;
                for (int x = 0; x <= k; ++x)
                    bns = Math.min(bns, Math.max(deltas[p] / (x+1), dp[p-1][k-x]));
                dp[p][k] = bns;
            }

        return dp[N-2][K];
    }
}
```

```python [solution1-Python]
class Solution(object):
    def minmaxGasDist(self, stations, K):
        N = len(stations)
        deltas = [stations[i+1] - stations[i] for i in xrange(N-1)]
        dp = [[0.0] * (K+1) for _ in xrange(N-1)]
        #dp[i][j] = answer for deltas[:i+1] when adding j gas stations
        for i in xrange(K+1):
            dp[0][i] = deltas[0] / float(i + 1)

        for p in xrange(1, N-1):
            for k in xrange(K+1):
                dp[p][k] = min(max(deltas[p] / float(x+1), dp[p-1][k-x])
                               for x in xrange(k+1))

        return dp[-1][K]
```

**复杂度分析**

* 时间复杂度：$O(N K^2)$，其中 $N$ 是 `stations` 的长度。

* 空间复杂度：$O(N K)$，其为 `dp` 数组的大小。

#### 方法二： 暴力法 【超时】

**思路**

和方法一相同，先计算相邻加油站之间的间距，之后不断往最大间距中新增加油站，直到加满 `k` 个加油站。显然这个贪心算法是正确的，没有其他方法能达到比这个方法更小的最大间距。

**算法**

用 `count[i]` 记录第 `i` 个间距之间有多少加油站，之后每次找最大间距的时候比较 `deltas[i] / count[i]`。

```java [solution2-Java]
class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        double[] deltas = new double[N-1];
        for (int i = 0; i < N-1; ++i)
            deltas[i] = stations[i+1] - stations[i];

        int[] count = new int[N-1];
        Arrays.fill(count, 1);

        for (int k = 0; k < K; ++k) {
            // Find interval with largest part
            int best = 0;
            for (int i = 0; i < N-1; ++i)
                if (deltas[i] / count[i] > deltas[best] / count[best])
                    best = i;

            // Add gas station to best interval
            count[best]++;
        }

        double ans = 0;
        for (int i = 0; i < N-1; ++i)
            ans = Math.max(ans, deltas[i] / count[i]);

        return ans;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def minmaxGasDist(self, stations, K):
        N = len(stations)
        deltas = [float(stations[i+1] - stations[i]) for i in xrange(N-1)]
        count = [1] * (N - 1)

        for _ in xrange(K):
            #Find interval with largest part
            best = 0
            for i, x in enumerate(deltas):
                if x / count[i] > deltas[best] / count[best]:
                    best = i

            #Add gas station to best interval
            count[best] += 1

        return max(x / count[i] for i, x in enumerate(deltas))
```

**复杂度分析**

* 时间复杂度：$O(N K)$，其中 $N$ 是 `stations` 的长度。

* 空间复杂度：$O(N)$，其为 `deltas` 和 `count` 的大小。

#### 方法三： 堆 【超时】

**思路**

同方法二相同的思路，用堆来加速找到最大间隔的速度。

**算法**

同方法二相同，不断往最大间距中新增加油站，重复 `k` 次。用最大堆来完成找最大间距的操作。在 Python 的实现中，用到了负优先级在最小堆中模拟最大堆。

```java [solution3-Java]
class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) ->
            (double)b[0]/b[1] < (double)a[0]/a[1] ? -1 : 1);
        for (int i = 0; i < N-1; ++i)
            pq.add(new int[]{stations[i+1] - stations[i], 1});

        for (int k = 0; k < K; ++k) {
            int[] node = pq.poll();
            node[1]++;
            pq.add(node);
        }

        int[] node = pq.poll();
        return (double)node[0] / node[1];
    }
}
```

```python [solution3-Python]
class Solution(object):
    def minmaxGasDist(self, stations, K):
        pq = [] #(-part_length, original_length, num_parts)
        for i in xrange(len(stations) - 1):
            x, y = stations[i], stations[i+1]
            pq.append((x-y, y-x, 1))
        heapq.heapify(pq)

        for _ in xrange(K):
            negnext, orig, parts = heapq.heappop(pq)
            parts += 1
            heapq.heappush(pq, (-(orig / float(parts)), orig, parts))

        return -pq[0][0]
```

**复杂度分析**

* 时间复杂度：$O(K \log N)$，其中 $N$ 为 `stations` 的长度。

* 空间复杂度：$O(N)$，其为 `deltas` 和 `count` 的大小。

#### 方法四： 二分搜索 【通过】

**思路**

定义 `possible(D)`： 有 `k` 个加油站，有没有可能让最小的最大距离小于等于 `D`？ 这个问题的结果是单调的，因此可以用二分搜索来找到答案 $D^{*}$。

**算法**

更准确一点来说，假设答案为 `D*`， 对于 `d < D*`，`possible(d) = False`，对于`d > D*`，`possible(d) = True`。针对单调问题的二分搜索是一个很典型的做法，重点是 `possible(D)` 的实现。

定义 `X = stations[i+1] - stations[i]`，此时需要 $\lfloor \frac{X}{D} \rfloor$ 个加油站来保证每个间距都小于 `D`，总共需要  $\sum_i \lfloor \frac{X_i}{D} \rfloor$ 个加油站。如果这个数不超过 `K`，就可以做到最大距离不超过 `D`。

```java [solution4-Java]
class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        double lo = 0, hi = 1e8;
        while (hi - lo > 1e-6) {
            double mi = (lo + hi) / 2.0;
            if (possible(mi, stations, K))
                hi = mi;
            else
                lo = mi;
        }
        return lo;
    }

    public boolean possible(double D, int[] stations, int K) {
        int used = 0;
        for (int i = 0; i < stations.length - 1; ++i)
            used += (int) ((stations[i+1] - stations[i]) / D);
        return used <= K;
    }
}
```

```python [solution4-Python]
class Solution(object):
    def minmaxGasDist(self, stations, K):
        def possible(D):
            return sum(int((stations[i+1] - stations[i]) / D)
                       for i in xrange(len(stations) - 1)) <= K

        lo, hi = 0, 10**8
        while hi - lo > 1e-6:
            mi = (lo + hi) / 2.0
            if possible(mi):
                hi = mi
            else:
                lo = mi
        return lo
```

**复杂度分析**

* 时间复杂度：$O(N \log W)$，其中 $N$ 是 `stations` 的长度，$W = 10^{14}$ 为答案的范围（$10^8$ 除以答案的精度 $10^{-6}$)。

* 空间复杂度：$O(1)$。