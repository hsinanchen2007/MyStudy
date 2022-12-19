#### 解题思路：

我们用 $A^k$ 表示连续使用 `k` 次 $A$ 指令，这样就可以用 $A^{k_1} R A^{k_2} R \cdots A^{k_n}, k_i \geq 0$ 表示任意一种指令列表。注意到最优的指令列表不可能以 $R$ 结束，因为在到了终点后转向是无意义的；同样最优的指令列表也不必以 $R$ 开始，假设 $R A^{k_1} R A^{k_2} \cdots R A^{k_n}$ 是一种最优的指令列表，那么我们可以将 $R A^{k_1} R$ 根据 $n$ 的奇偶性将其变为 $R A^{k_1}$ 或 $RR A^{k_1}$ 放在指令列表的末尾。

对于指令列表 $A^{k_1} R A^{k_2} R \cdots A^{k_n}$，它可以使得赛车到达的位置为 $(2^{k_1} - 1) - (2^{k_2} - 1) + (2^{k_3} - 1) - \cdots$，因此不失一般性，可以交换 $k_1, k_3, \cdots$ 这些奇数位置的 $k_i$ 使得这个数列单调不增，同样可以交换 $k_2, k_4, \cdots$ 这些偶数位置的 $k_i$ 使得这个数列单调不增。同时所有的 $k_i$ 都有一个上界 $a + 1$，其中 $a$ 为最小满足 $2^a \geq \text{target}$ 的整数，即如果在某一时刻赛车经过了终点，那么折返比继续行驶更优。

#### 方法一：最短路

由于 $k_i$ 存在上界 $a + 1$，因此我们可以在给定 `target` 后确定赛车能够到达的最远距离 `barrier`，那么赛车只有在 `[-barrier, barrier]` 这个区间内驾驶，才可以找到最优解。对于区间中的某一个位置 `x`，我们可以通过 $k_i = 0, 1, 2, \cdots$ 来使得赛车行驶对应的距离，同时需要使用对应长度的指令，相当于位置 `x` 和其余若干个位置间连了一条长度为指令的边。因此我们只需要求出位置 `0` 到位置 `target` 的最短路即可。我们可以使用 `Dijkstra` 算法快速求出最短路。

```Java [sol1]
class Solution {
    public int racecar(int target) {
        int K = 33 - Integer.numberOfLeadingZeros(target - 1);
        int barrier = 1 << K;
        int[] dist = new int[2 * barrier + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[target] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<Node>(
            (a, b) -> a.steps - b.steps);
        pq.offer(new Node(0, target));

        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int steps = node.steps, targ1 = node.target;
            if (dist[Math.floorMod(targ1, dist.length)] > steps) continue;

            for (int k = 0; k <= K; ++k) {
                int walk = (1 << k) - 1;
                int targ2 = walk - targ1;
                int steps2 = steps + k + (targ2 != 0 ? 1 : 0);

                if (Math.abs(targ2) <= barrier && steps2 < dist[Math.floorMod(targ2, dist.length)]) {
                    pq.offer(new Node(steps2, targ2));
                    dist[Math.floorMod(targ2, dist.length)] = steps2;
                }
            }
        }

        return dist[0];
    }
}

class Node {
    int steps, target;
    Node(int s, int t) {
        steps = s;
        target = t;
    }
}
```

```Python [sol1]
class Solution(object):
    def racecar(self, target):
        K = target.bit_length() + 1
        barrier = 1 << K
        pq = [(0, target)]
        dist = [float('inf')] * (2 * barrier + 1)
        dist[target] = 0

        while pq:
            steps, targ = heapq.heappop(pq)
            if dist[targ] > steps: continue

            for k in xrange(K+1):
                walk = (1 << k) - 1
                steps2, targ2 = steps + k + 1, walk - targ
                if walk == targ: steps2 -= 1 #No "R" command if already exact

                if abs(targ2) <= barrier and steps2 < dist[targ2]:
                    heapq.heappush(pq, (steps2, targ2))
                    dist[targ2] = steps2

        return dist[0]
```

**复杂度分析**

* 时间复杂度：$O(T \log T)$。其中 $O(T)$ 表示 `barrier` 的数量级。

* 空间复杂度：$O(T)$。

#### 方法二：动态规划

我们可以使用动态规划来找到最短的指令长度。

假设我们需要到达位置 `x`，且 $2^{k-1} \leq x < 2^k$，我们用 `dp[x]` 表示到达位置 `x` 的最短指令长度。如果 $t = 2^{k-1}$，那么我们只需要用 $A^k$ 即可。否则我们需要考虑两种情况：

- 我们首先用 $A^{k-1}$ 到达位置 $2^{k-1} - 1$，随后折返并使用 $A^j$，这样我们到达了位置 $2^{k-1} - 2^j$，使用的指令为 $A^{k-1} R A^k R$，长度为 $k - 1 + j - 2$，剩余的距离为 $x - (2^{k-1} - 2^j) < x$；

- 我们首先用 $A^k$ 到达位置 $2^k - 1$，随后仅使用折返指令，此时我们已经超过了终点并且速度方向朝向终点，使用的指令为 $A^k R$，长度为 $k + 1$，剩余的距离为 $x - (2^k) - 1 < x$。

```Java [sol2]
class Solution {
    public int racecar(int target) {
        int[] dp = new int[target + 3];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0; dp[1] = 1; dp[2] = 4;

        for (int t = 3; t <= target; ++t) {
            int k = 32 - Integer.numberOfLeadingZeros(t);
            if (t == (1<<k) - 1) {
                dp[t] = k;
                continue;
            }
            for (int j = 0; j < k-1; ++j)
                dp[t] = Math.min(dp[t], dp[t - (1<<(k-1)) + (1<<j)] + k-1 + j + 2);
            if ((1<<k) - 1 - t < t)
                dp[t] = Math.min(dp[t], dp[(1<<k) - 1 - t] + k + 1);
        }

        return dp[target];  
    }
}
```

```Python [sol2]
class Solution(object):
    def racecar(self, target):
        dp = [0, 1, 4] + [float('inf')] * target
        for t in xrange(3, target + 1):
            k = t.bit_length()
            if t == 2**k - 1:
                dp[t] = k
                continue
            for j in xrange(k - 1):
                dp[t] = min(dp[t], dp[t - 2**(k - 1) + 2**j] + k - 1 + j + 2)
            if 2**k - 1 - t < t:
                dp[t] = min(dp[t], dp[2**k - 1 - t] + k + 1)
        return dp[target]
```

**复杂度分析**

* 时间复杂度：$O(T \log T)$。对于每一个位置 `x`，需要循环 $O(\log x)$ 次。

* 空间复杂度：$O(T)$。