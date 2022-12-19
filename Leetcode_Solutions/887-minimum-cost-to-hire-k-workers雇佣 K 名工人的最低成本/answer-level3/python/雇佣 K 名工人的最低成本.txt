#### 方法一：贪心

显然，当我们选择 `K` 名工人时，会只要有一名工人恰好拿到了他的最低期望工资。因此，我们可以枚举是哪一名工人恰好拿到了他的最低期望工资，并检查在当前的“工资/质量”比值下，其他工人拿到的工资是否不少于他们的最低期望工资。如果有至少 `K - 1` 名工人满足条件，那么我们就在这些工人中选出 `K - 1` 名拿到工资最低的，加上枚举的那一名工人的最低期望工资，就得到了一个答案。在所有的答案中，返回最小值。

注意这种方法可能会超出时间限制。

```Java [sol1]
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        int N = quality.length;
        double ans = 1e9;

        for (int captain = 0; captain < N; ++captain) {
            // Must pay at least wage[captain] / quality[captain] per qual
            double factor = (double) wage[captain] / quality[captain];
            double prices[] = new double[N];
            int t = 0;
            for (int worker = 0; worker < N; ++worker) {
                double price = factor * quality[worker];
                if (price < wage[worker]) continue;
                prices[t++] = price;
            }

            if (t < K) continue;
            Arrays.sort(prices, 0, t);
            double cand = 0;
            for (int i = 0; i < K; ++i)
                cand += prices[i];
            ans = Math.min(ans, cand);
        }

        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def mincostToHireWorkers(self, quality, wage, K):
        from fractions import Fraction
        ans = float('inf')

        N = len(quality)
        for captain in xrange(N):
            # Must pay at least wage[captain] / quality[captain] per qual
            factor = Fraction(wage[captain], quality[captain])
            prices = []
            for worker in xrange(N):
                price = factor * quality[worker]
                if price < wage[worker]: continue
                prices.append(price)

            if len(prices) < K: continue
            prices.sort()
            ans = min(ans, sum(prices[:K]))

        return float(ans)
```

**复杂度分析**

* 时间复杂度：$O(N^2 \log N)$。

* 空间复杂度：$O(N)$。

#### 方法二：堆（优先队列）

在方法一中，我们枚举了一名工人，并对剩下的工人计算对应的工资，并选出 `K - 1` 个工资最低的进行累加。事实上，我们可以定义一个“价值”，表示工人最低期望工资与工作质量之比。例如某位工人的最低期望工资为 `100`，工作质量为 `20`，那么他的价值为 `100 / 20 = 5.0`。

可以发现，如果一名工人的价值为 `R`，当他恰好拿到最低期望工资时，如果所有价值高于 `R` 的工人都无法拿到最低期望工资，而所有价值低于 `R` 的工人都拿得比最低期望工资多。因此，我们可以按照这些工人的价值，对他们进行升序排序。排序后的第 `i` 名工人可以在它之前任选 `K - 1` 名工人，并计算对应的工资总和，为 `R * sum(quality[c1] + quality[c2] + ... + quality[c{k-1}] + quality[i])`，也就是说，我们需要在前 `i` 名工人中选择 `K` 个工作质量最低的。我们可以使用一个大根堆来实时维护 `K` 个最小值。

```Java [sol2]
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        int N = quality.length;
        Worker[] workers = new Worker[N];
        for (int i = 0; i < N; ++i)
            workers[i] = new Worker(quality[i], wage[i]);
        Arrays.sort(workers);

        double ans = 1e9;
        int sumq = 0;
        PriorityQueue<Integer> pool = new PriorityQueue();
        for (Worker worker: workers) {
            pool.offer(-worker.quality);
            sumq += worker.quality;
            if (pool.size() > K)
                sumq += pool.poll();
            if (pool.size() == K)
                ans = Math.min(ans, sumq * worker.ratio());
        }

        return ans;
    }
}

class Worker implements Comparable<Worker> {
    public int quality, wage;
    public Worker(int q, int w) {
        quality = q;
        wage = w;
    }

    public double ratio() {
        return (double) wage / quality;
    }

    public int compareTo(Worker other) {
        return Double.compare(ratio(), other.ratio());
    }
}
```

```Python [sol2]
class Solution(object):
    def mincostToHireWorkers(self, quality, wage, K):
        from fractions import Fraction
        workers = sorted((Fraction(w, q), q, w)
                         for q, w in zip(quality, wage))

        ans = float('inf')
        pool = []
        sumq = 0
        for ratio, q, w in workers:
            heapq.heappush(pool, -q)
            sumq += q

            if len(pool) > K:
                sumq += heapq.heappop(pool)

            if len(pool) == K:
                ans = min(ans, ratio * sumq)

        return float(ans)
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$。

* 空间复杂度：$O(N)$。