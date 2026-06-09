#### 方法一： 动态规划

**思路**

`dp[i]` 为加 `i` 次油能走的最远距离，需要满足 `dp[i] >= target` 的最小 `i`。

**算法**

依次计算每个 `dp[i]`，对于 `dp[0]`，就只用初始的油量 `startFuel` 看能走多远。

每多一个加油站 `station[i] = (location, capacity)`，如果之前可以通过加 `t` 次油到达这个加油站，现在就可以加 `t+1` 次油得到 `capcity` 的油量。

举个例子，原本加一次油可以行驶的最远距离为 15，现在位置 10 有一个加油站，有 30 升油量储备，那么显然现在可以加两次油行驶 45 距离。 


```java [solution1-Java]
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int N = stations.length;
        long[] dp = new long[N + 1];
        dp[0] = startFuel;
        for (int i = 0; i < N; ++i)
            for (int t = i; t >= 0; --t)
                if (dp[t] >= stations[i][0])
                    dp[t+1] = Math.max(dp[t+1], dp[t] + (long) stations[i][1]);

        for (int i = 0; i <= N; ++i)
            if (dp[i] >= target) return i;
        return -1;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def minRefuelStops(self, target, startFuel, stations):
        dp = [startFuel] + [0] * len(stations)
        for i, (location, capacity) in enumerate(stations):
            for t in xrange(i, -1, -1):
                if dp[t] >= location:
                    dp[t+1] = max(dp[t+1], dp[t] + capacity)

        for i, d in enumerate(dp):
            if d >= target: return i
        return -1
```

**复杂度分析**

* 时间复杂度： $O(N^2)$，其中 $N$ 为加油站的个数。

* 空间复杂度： $O(N)$，`dp` 数组占用的空间。

#### 方法二：栈

**思路**

每驶过一个加油站，记住这个加油站有多少油。不需要立即决定要不要在这个加油站加油，如果后面有油量更多的加油站显然优先选择后面的加油。

如果当前油量不够抵达下一个加油站，必须得从之前的加油站中找一个来加油，贪心选择最大油量储备的加油站就好了。

**算法**

定义 `pq`（优先队列）为一个保存了驶过加油站油量的最大堆，定义当前油量为 `tank`。

如果当前油量为负数（意味着当前油量不够抵达当前位置），那就必须在驶过的加油站找一个油量储备最大来加油。

如果在某个位置油量为负，且没有加油站可用了，那就不可能完成这个任务。

```java [solution2-Java]
class Solution {
    public int minRefuelStops(int target, int tank, int[][] stations) {
        // pq is a maxheap of gas station capacities
        PriorityQueue<Integer> pq = new PriorityQueue(Collections.reverseOrder());
        int ans = 0, prev = 0;
        for (int[] station: stations) {
            int location = station[0];
            int capacity = station[1];
            tank -= location - prev;
            while (!pq.isEmpty() && tank < 0) {  // must refuel in past
                tank += pq.poll();
                ans++;
            }

            if (tank < 0) return -1;
            pq.offer(capacity);
            prev = location;
        }

        // Repeat body for station = (target, inf)
        {
            tank -= target - prev;
            while (!pq.isEmpty() && tank < 0) {
                tank += pq.poll();
                ans++;
            }
            if (tank < 0) return -1;
        }

        return ans;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def minRefuelStops(self, target, tank, stations):
        pq = []  # A maxheap is simulated using negative values
        stations.append((target, float('inf')))

        ans = prev = 0
        for location, capacity in stations:
            tank -= location - prev
            while pq and tank < 0:  # must refuel in past
                tank += -heapq.heappop(pq)
                ans += 1
            if tank < 0: return -1
            heapq.heappush(pq, -capacity)
            prev = location

        return ans
```


**复杂度分析**

* 时间复杂度： $O(N \log N)$，其中 $N$ 为加油站的个数。

* 空间复杂度： $O(N)$， `pq` 数组占用的空间。