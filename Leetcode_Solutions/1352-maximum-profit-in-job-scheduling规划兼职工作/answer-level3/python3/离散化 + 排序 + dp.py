# 题解

首先我们按照 `endTime` 来排序，然后就能得到一个可以 dp 的数组了。

$$
end\_time(c)\ is\ equal\ to\ n\\
dp(n)=max(dp(n-1), dp(start\_time(c)+profit(c))
$$

但是我们会发现一个问题，`1 <= startTime[i] < endTime[i] <= 10^9` ，所以这个 dp 数组我们可能会遍历 $10^9$ 次，必定超时。（根据经验，我们认为遍历超过 $10^7$ 次就是 1s，也就是 TLE 的极限时间）

这时候我们又发现 `1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4`。这就暗示我们了，虽然我们的时间上线有 $10^9$ 个，但是描述时间的个数只有 `len(startTime) + len(endTime)` 个，也就是 $10^5$ 个。所以我们对时间做一下离散化来描述大小关系，然后在 dp 一圈求解答案即可。

# 时间复杂度

### 离散化预处理（排序）

$$
O(nlogn) \ (n \in[0, 10^5])
$$

### 动态规划

$$
O(n+c) \ \ (n\in[0, 10^5],\ c\in[0, 5\times10^4])
$$

### 整体

$$
O(nlogn) \ (n \in[0, 10^5])
$$

# 代码实现

```python
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        disc, cur = {}, 0
        all_times = sorted(list(set(startTime + endTime)))
        for i in all_times:
            disc[i] = cur
            cur += 1
        pp = sorted(list(zip([disc[i] for i in startTime], [disc[i] for i in endTime], profit)), key=lambda x: x[1])
        # print(pp)
        cur_index, dp = 0, [0] * (cur)
        for i, num in enumerate(dp):
            while cur_index < len(pp) and i == pp[cur_index][1]:
                current_p = pp[cur_index]
                dp[i] = max(dp[i], dp[current_p[0]] + current_p[2])
                cur_index += 1
            if i > 0:    
                dp[i] = max(dp[i - 1], dp[i])    
        return dp[len(dp) - 1]
```

![image.png](https://pic.leetcode-cn.com/dae928c81759a8b0e1792314ee7dee1ad42d055321cb84859b5d604c6bfda547-image.png)
