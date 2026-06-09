#### 方法 1：模拟

**想法**

模拟每一天监狱的状态。

由于监狱最多只有 256 种可能的状态，所以状态一定会快速的形成一个循环。我们可以当状态循环出现的时候记录下循环的周期 `t` 然后跳过 `t` 的倍数的天数。

**算法**

实现一个简单的模拟，每次迭代一天的情况。对于每一天，我们减少剩余的天数 `N`，然后将监狱状态改变成（`state -> nextDay(state)`）。

如果我们到达一个已经访问的状态，并且知道距当前过去了多久，设为 `t`，那么由于这是一个循环，可以让 `N %= t`。这确保了我们的算法只需要执行 $O(2^{\text{cells.length}})$ 步。

```Java []
class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        Map<Integer, Integer> seen = new HashMap();

        // state  = integer representing state of prison
        int state = 0;
        for (int i = 0; i < 8; ++i) {
            if (cells[i] > 0)
                state ^= 1 << i;
        }

        // While days remaining, simulate a day
        while (N > 0) {
            // If this is a cycle, fast forward by
            // seen.get(state) - N, the period of the cycle.
            if (seen.containsKey(state)) {
                N %= seen.get(state) - N;
            }
            seen.put(state, N);

            if (N >= 1) {
                N--;
                state = nextDay(state);
            }
        }

        // Convert the state back to the required answer.
        int[] ans = new int[8];
        for (int i = 0; i < 8; ++i) {
            if (((state >> i) & 1) > 0) {
                ans[i] = 1;
            }
        }

        return ans;
    }

    public int nextDay(int state) {
        int ans = 0;

        // We only loop from 1 to 6 because 0 and 7 are impossible,
        // as those cells only have one neighbor.
        for (int i = 1; i <= 6; ++i) {
            if (((state >> (i-1)) & 1) == ((state >> (i+1)) & 1)) {
                ans ^= 1 << i;
            }
        }

        return ans;
    }
}
```

```Python []
class Solution(object):
    def prisonAfterNDays(self, cells, N):
        def nextday(cells):
            return [int(i > 0 and i < 7 and cells[i-1] == cells[i+1])
                    for i in xrange(8)]

        seen = {}
        while N > 0:
            c = tuple(cells)
            if c in seen:
                N %= seen[c] - N
            seen[c] = N

            if N >= 1:
                N -= 1
                cells = nextday(cells)

        return cells
```

**复杂度分析**

* 时间复杂度：$O(2^N)$，其中 $N$ 是监狱房间的个数。
* 空间复杂度：$O(2^N * N)$。