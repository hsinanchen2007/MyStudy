该问题等效于 **0-1 背包问题**

# 01背包问题

> 参考 《背包问题九讲》 dd_engi

有`N`件物品和一个容量为`V`的背包。第`i`件物品的体积为`c[i]`，价值为`w[i]`，求解将那些物品放入背包，使得背包内物品的总价值之和最大。

对于此类问题，每种物品仅有一件，可以选择放或者不放入背包，可以用子问题定义状态，即`f[i][v]`表示前`i`件物品恰好放入一个容量为`v`的背包可以获得的最大价值，其状态转移方程为：

```
f[i][v] = max{f[i-1][v], f[i-1][v-c[i]+w[i]]}
```

上公示表示为，当前`i`件物品放入容量为 `v` 的背包时，最大价值牵扯放不放入当前第`i`个物品。

- 若不放入，则价值为前`i-1`件物品放入容量为`v`的背包

- 若放入，则价值为前`i-1`件物品放入容量为`v-c[i]`的背包的最大价值，在加上当前物品的价值

选择上述两个状态的最大值即可。

空间复杂度为 O(VN)，可以优化到 O(V)。由于`f[i][v]`通过`f[i-1][v]`和`f[i-1][v-c[i]]`子问题得到，在第`i`次循环推导`f[v]`时，用到的是`f[i-1][v]`和`f[i-v][v-c[i]]`，因此可以以`V->0`的顺序进行推导

```
for i = 1...N
    for v = V ... 0:
        f[v] = max(f[v], f[v-c[i]+w[i]])
```

对于处理 1 件0-1背包中的物品，可以推导出通用`python`解法

```python
def ZeroOnePack(f: list, cost, weight):
  for v in range(len(f)-1, weight-1, -1):
    f[v] = max(f[v], f[v-weight] + cost)
```

关于数组的初始化，存在两种情况，一种是需要恰好装满背包时的最优解，一种是不需要把背包必须装满。

第一种解法，初始化 `f[0] = 0`， 对于`f[1..V = -inf`，可以保证最后结果`f[N]`是恰好装满背包的最优解

第二种解法，全部初始化为 0

> 初始化`f`数组实际上是在没有任何物品放入背包时的合法状态，如果要求恰好装满，则只有容量为 0 的背包可以被价值为 0 的空物品装满，其他均没有合法解。如果背包不比被装满，则任何容量的背包都有一个合法解：什么都不装，价值都为 0

# 转化为 0-1 背包问题

该问题可以转化为：将石头分为两堆，两堆的总重尽可能接近。假设石头的总重量是`sum_weight` , 任务转化为寻找一组石头，石头的重量尽可能接近`sum_weight//2`，设定背包的最大容量为`max_weight = sum_weight // 2`,对于每块石头，其重量为`weight`，其价值也为`weight`，套用背包问题的公式为:

```python
for v in range(max_weight, weight - 1, -1):
  f[v] = max(f[v], f[v-weight] + weight)
```

因此最终代码可以写为

```python
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        sum_weight = sum(stones)
        max_weight = sum_weight // 2
        f = [0 for _ in range(max_weight + 1)]
        for stone in stones:
            for v in range(max_weight, stone - 1, -1):
                f[v] = max(f[v], f[v - stone] + stone)
        return sum_weight - 2 * f[-1]
```