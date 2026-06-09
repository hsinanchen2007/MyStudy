
#### 方法：排序

**想法**

我们可以以任意顺序考虑工人，所以我们按照能力大小排序。

如果我们先访问低难度的工作，那么收益一定是截至目前最好的。

**算法**

我们使用 “双指针” 的方法去安排任务。我们记录最大可用利润 `best`。对于每个能力值为 `skill` 的工人，找到难度小于等于能力值的任务，并将如结果中。

```Java []
import java.awt.Point;

class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int N = difficulty.length;
        Point[] jobs = new Point[N];
        for (int i = 0; i < N; ++i)
            jobs[i] = new Point(difficulty[i], profit[i]);
        Arrays.sort(jobs, (a, b) -> a.x - b.x);
        Arrays.sort(worker);

        int ans = 0, i = 0, best = 0;
        for (int skill: worker) {
            while (i < N && skill >= jobs[i].x)
                best = Math.max(best, jobs[i++].y);
            ans += best;
        }

        return ans;
    }
}
```

```Python []
class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        jobs = zip(difficulty, profit)
        jobs.sort()
        ans = i = best = 0
        for skill in sorted(worker):
            while i < len(jobs) and skill >= jobs[i][0]:
                best = max(best, jobs[i][1])
                i += 1
            ans += best
        return ans

```

**复杂度分析**

* 时间复杂度：$O(N \log N + Q \log Q)$，其中 $N$ 是任务个数，$Q$ 是工人数量。
* 空间复杂度：$O(N)$，`jobs` 的额外空间。