首先按照 $efficicecy$ 从大到小排序（排序后工程师数组记为 $team$ ），然后维护一个大小为 $k$ 最小堆，和堆对应的元素速度和 $speedSum$，设置一个变量 $maxPerf$ 表示当前的全局最优解。排序好的元素从左到右遍历，如果堆的实际大小小于 $k$，直接将元素压入堆，如果大小已经到 $k$，那么如果当前元素的 $speed$ 大于堆顶元素的 $speed$，堆顶出堆当前元素入堆。每次入堆都要更新 $speedSum$，重新计算团队表现值，和当前最优解比对，更新当前最优解 $maxPerf$。

当遍历到元素 $team[i]$ 时，最小堆记录的其实是比当前元素 $efficicecy$ 大的前 $k$ 大 $speed$ 的组合。我们证明为什么这样遍历更新之后最大团队表现值是被搜索到的了，首先团队表现值只有在每次堆变化之后才会更新 $maxPerf$，用归纳法证明，遍历到 $team[i]$ 的时候，$maxPerf$ 记录的就是 $team[:i+1]$ 的最大团队表现值：
* 当 $i=0$ 时更新了 $maxPerf$，此时 $maxPerf$ 就是 $team[:1]$ 的最大团队表现值；
* 当假设当 $i=1..m-1$ 时，$maxPerf$ 是 $team[:i+1]$ 的最大团队表现值。当 $i=m$时，此时 $team[:m+1]$ 的最大团队表现值无非包含两种情况，就是包含 $m$ 和不包含 $m$ ：
    * 如果包含 $m$，因为此时 $team[m]$ 的 $efficiency$ 最小的，那么 $team[m]$ 一定是在前 $k$ 大的 $speed$ 的组合里，即 $m$ 会入堆，而且此时更新的 $maxPerf$ 是最优解。
    * 如果不包含 $m$，那么 $team[:m+1]$ 的最大团队表现值其实是由 $team[:m]$ 组成的，根据我们的归纳假设，$maxPerf$ 也是 $team[:m+1]$ 的最优解。此时 $m$ 可能入堆也可能不入堆，不过对于我们的最优解没有影响。
* 综上，即可证明最后 $maxPerf$ 即为最大团队表现值。

```python
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        MOD = int(10 ** 9 + 7)
        team = [[speed[i], efficiency[i]] for i in range(n)]
        team.sort(key=lambda x: (x[1], x[0]), reverse=True)
        from queue import PriorityQueue
        pq = PriorityQueue()
        speedSum = 0
        maxPerf = 0

        for i in range(n):
            if i < k:
                pq.put(team[i][0])
                speedSum += team[i][0]
                maxPerf = max([maxPerf, speedSum * team[i][1]])
            else:
                if team[i][0] > pq.queue[0]:
                    speed_ = pq.get()
                    pq.put(team[i][0])
                    speedSum = speedSum - speed_ + team[i][0]
                    maxPerf = max([maxPerf, speedSum * team[i][1]])

        return maxPerf % MOD
```
