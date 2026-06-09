
#### 方法：一次遍历

**想法**

第一想法是检查每一个加油站：

- 选择该加油站为出发站

- 模拟汽车环路行驶，在每一个加油站检查我们还剩多少升汽油。

这意味着 $\mathcal{O}(N^2)$ 的时间复杂度。显然，我们可以做得更好。

首先注意两件事情：

> 如果 `sum(gas) < sum(cost)` ，那么不可能环行一圈，这种情况下答案是 `-1` 。


![image.png](https://pic.leetcode-cn.com/4381241b2ed28ee64703425af2e6a4ddb85df5dad25d644c89d7bdbcd2927c8b-image.png){:width="500px"}
{:align="center"}

我们可以用这个式子计算环行过程中邮箱里剩下的油：`total_tank = sum(gas) - sum(cost)`  ，如果 `total_tank < 0` 则返回 `-1` 。

> 对于加油站 `i` ，如果 `gas[i] - cost[i] < 0` ，则不可能从这个加油站出发，因为在前往 `i + 1` 的过程中，汽油就不够了。
 

![image.png](https://pic.leetcode-cn.com/5f9a6f57444dc93f334fdb782f4368e3863888b82fc90d4f9b490eeb53cf86fe-image.png){:width="500px"}
{:align="center"}

第二个规则可以被一般化，我们引入变量 `curr_tank` ，记录当前油箱里剩余的总油量。如果在某一个加油站 `curr_tank`比 `0` 小，意味着我们无法到达这个加油站。

下一步我们把这个加油站当做新的起点，并将 `curr_tank` 重置为 0 ，因为重新出发，油箱中的油为 0 。（从上一次重置的加油站到当前加油站的任意一个加油站出发，到达当前加油站之前， `curr_tank` 也一定会比 0 小）

**算法**

那么现在算法是很直接明了的：

1. 初始化 `total_tank` 和 `curr_tank` 为 0 ，并且选择 `0` 号加油站为起点。

2. 遍历所有的加油站：
    
    - 每一步中，都通过加上 `gas[i]` 和减去 `cost[i]` 来更新 `total_tank` 和 `curr_tank` 。
    
    - 如果在 `i + 1` 号加油站， `curr_tank < 0` ，将 `i + 1` 号加油站作为新的起点，同时重置 `curr_tank = 0` ，让油箱也清空。

3. 如果 `total_tank < 0` ，返回 `-1` ，否则返回 `starting station`。

**算法原理**

想象 `total_tank >= 0` 的情况，同时上述算法返回 $N_s$ 作为出发加油站。

算法直接保证了从 $N_s$ 可以到达 $0$ ，但是剩余的路程，即从 $0$ 到站 $N_s$ 是否有足够的油呢？

> 如何确保从 $N_s$ 出发可以环行一圈？

我们使用 [反证法](https://baike.baidu.com/item/%E5%8F%8D%E8%AF%81%E6%B3%95/5017739?fr=aladdin) 。假设存在 $0 < k < N_s$ ，使得我们从 $N_s$ 出发无法到达 `k` 号加油站。
 
条件 `total_tank >= 0` 可以被写作

$$
\sum_{i = 1}^{N}{\alpha_i} \ge 0    \qquad (1)
$$
其中 $\alpha_i = \textrm{gas[i]} - \textrm{cost[i]}$ 。

我们将出发站点 $N_s$ 和无法到达站点 `k` 作为分隔点，将左式分成三个部分：

$$
\sum_{i = 1}^{k}{\alpha_i} + 
\sum_{i = k + 1}^{N_s - 1}{\alpha_i} +
\sum_{i = N_s}^{N}{\alpha_i} \ge 0  \qquad (2)
$$

根据算法流程，第二项为负，因为每一个出发点前面一段路途的 `curr_tank` 一定为负。否则，出发点应该是比 $N_s$ 更靠前的一个加油站而不是 $N_s$ 。当且仅当 $k = N_s - 1$ ，第二项才为 0 。

$$
\sum_{i = k + 1}^{i = N_s - 1}{\alpha_i} \le 0  \qquad (3)
$$

结合不等式 `(2)` 和 `(3)` ，可以得到

$$
\sum_{i = 0}^{i = k}{\alpha_i} +
\sum_{i = N_s}^{i = N}{\alpha_i} \ge 0  \qquad (4)
$$

同时，因为 $k$ 是一个从 $N_s$ 出发不可到达的站点，意味着

$$
\sum_{i = N_s}^{i = N}{\alpha_i} +
\sum_{i = 0}^{i = k}{\alpha_i} < 0  \qquad (5)
$$

结合不等式 `(4)` 和 `(5)` ，可以得到一个矛盾。因此，假设 “存在一个 $0 < k < N_s$ ，从 $N_s$ 出发无法到达 $k$” 不成立。

因此，从 $N_s$ 出发一定能环行一圈， $N_s$ 是一个可行解。根据题目描述，答案是唯一的。

**实现**

<![image.png](https://pic.leetcode-cn.com/87e7bb7a0745fe4916de8deb8687b4a84b3482daab0643f1ae6d4a02cf03ceb0-image.png),![image.png](https://pic.leetcode-cn.com/4dad65b5a9ed763e2760129635f1704be4a9e093ea66bc4e244657cb59c35744-image.png),![image.png](https://pic.leetcode-cn.com/022e56703b9ce5f53fb8ad9c6d51cc74468bff670eb29dfa48cb0625c9d57cba-image.png),![image.png](https://pic.leetcode-cn.com/256c9491248c8cf0e8fca7370346ea22333edc4394c57f211c1783a6b163235a-image.png),![image.png](https://pic.leetcode-cn.com/d1cef311a434c64d3fd85ea0d1adb5374e1b16d802110c90c833ceb4121bb19c-image.png),![image.png](https://pic.leetcode-cn.com/6be953413c1dbb884e5b2e92837cc4384ba32fa662f7c2c0784cb8e1bff973b2-image.png),![image.png](https://pic.leetcode-cn.com/ca82d1cec3e8d2a325c20f1dab270bcae405e21f4990e46f38f5394fe6c65249-image.png),![image.png](https://pic.leetcode-cn.com/469511c0afc12420e34588cf19cb373ee22e9d4fb5c472d6b92e764f12e0fd7e-image.png),![image.png](https://pic.leetcode-cn.com/dcbe6e6975e1ee7d2cedfbdc9cff3d8212b066e6d5d63535ba435aceec67af9c-image.png),![image.png](https://pic.leetcode-cn.com/8c6d7bb66df5271a3383bce38fadbf0bfd52c1b035582903c3a6ebd4df8d1989-image.png),![image.png](https://pic.leetcode-cn.com/f1aea61b070c96e2e5c718dd3b9a35e40fa74f769204398fbdbd0a7466fa7eff-image.png),![image.png](https://pic.leetcode-cn.com/d450f8d85053fbdd914e21e6e0d56b0b7ebd797bea4cfb6fa5b250f794bcaf61-image.png),![image.png](https://pic.leetcode-cn.com/67399856acdd96570218a3de68ec86de6d6f385e517cc5e1991493433ca58b05-image.png)>

```Python []
class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        n = len(gas)
        
        total_tank, curr_tank = 0, 0
        starting_station = 0
        for i in range(n):
            total_tank += gas[i] - cost[i]
            curr_tank += gas[i] - cost[i]
            # If one couldn't get here,
            if curr_tank < 0:
                # Pick up the next station as the starting one.
                starting_station = i + 1
                # Start with an empty tank.
                curr_tank = 0
        
        return starting_station if total_tank >= 0 else -1
```

```Java []
class Solution {
  public int canCompleteCircuit(int[] gas, int[] cost) {
    int n = gas.length;

    int total_tank = 0;
    int curr_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < n; ++i) {
      total_tank += gas[i] - cost[i];
      curr_tank += gas[i] - cost[i];
      // If one couldn't get here,
      if (curr_tank < 0) {
        // Pick up the next station as the starting one.
        starting_station = i + 1;
        // Start with an empty tank.
        curr_tank = 0;
      }
    }
    return total_tank >= 0 ? starting_station : -1;
  }
}
```

```C++ []
class Solution {
  public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int total_tank = 0;
    int curr_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < n; ++i) {
      total_tank += gas[i] - cost[i];
      curr_tank += gas[i] - cost[i];
      // If one couldn't get here,
      if (curr_tank < 0) {
        // Pick up the next station as the starting one.
        starting_station = i + 1;
        // Start with an empty tank.
        curr_tank = 0;
      }
    }
    return total_tank >= 0 ? starting_station : -1;
  }
};
```

**复杂度分析**

* 时间复杂度： $\mathcal{O}(N)$ ， 这是因为只有一个遍历了所有加油站一次的循环。
 
* 空间复杂度： $\mathcal{O}(1)$ ，因为此算法只使用了常数个变量。

**延伸阅读**

还有许多加油站问题的变种问题，这里是一些例子：

[允许 Δ 次停留的加油站间最小路径开销](https://www.sciencedirect.com/science/article/pii/S002001901730203X) 

[油箱有容量限制下的加油站间最小路径开销](https://link.springer.com/chapter/10.1007/978-3-540-75520-3_48)