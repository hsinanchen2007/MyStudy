####  方法：动态规划
**模板：**
这是经典的动态编程问题。这是一个可以使用的模板：
- 定义答案显而易见的基本情况。
- 制定根据简单的情况计算复杂情况的策略。
- 将此策略链接到基本情况。

**例子：**
让我们举一个例子：`amount = 11`，可用硬币面值有 `2` 美分，`5` 美分和 `10` 美分。 请注意，硬币数量是无限的。

![在这里插入图片描述](https://pic.leetcode-cn.com/ee366a0e1b14432c1ad252e4d16fce649a3ea1656c42ad19679a49c6da564d70-file_1576478034278){:width=500}

**基本情况：没有硬币或 金币 = 0**
- 如果总金额为 `0`，那么只有一个组合情况：`0`。
- 另一个基本情况是没有硬币，若 `amount > 0`，则组合情况为 `0`，若 `amount == 0`，则组合情况为 `1`。

![在这里插入图片描述](https://pic.leetcode-cn.com/3ca0515cc9bf3032b78c2eebf8721b92b05dd71fad5fc9ce7e530ee582b9a851-file_1576478034332){:width=500}

**2 美分：**
- 让我们用一种硬币做进一步考虑：`2` 美分

![在这里插入图片描述](https://pic.leetcode-cn.com/c6973b09c8bdec35b21aa7efde6533b2d52b599f49b40e0ef012fbcce785be5b.png){:width=500}
- 很明显，这里可能会有 `1` 种或 `0` 种组合。偶数金额为 `1` 种，奇数金额为 `0` 种。
- 首先，所有金额均小于 `2` 美分不会受到 `2` 美分硬币的影响。 因此对于 `amount = 0` 和 `amount = 1` 的结果没有变化。
- 从 `amount = 2` 开始，可以使用 `2` 美分硬币进行组合。
- 我们使用 `2` 美分硬币来组合 `amount = 2`，则金额 2 美分的组合数等于 `amount = 0` 的组合数量，即 `1`。

![在这里插入图片描述](https://pic.leetcode-cn.com/26604220a2e6bb89a1bd3b1c2bc8966162abaaec9c576a35f2610afb8a3d37f5-file_1576478034329){:width=500}
- 同理 `amount = 3` 的组合数量等于 `amount = 1` 的组合数量，即 `0`。 

![在这里插入图片描述](https://pic.leetcode-cn.com/5a5730dd8b5b8abe0070691feaf52ad9a484be7d7df50d32365e02335aef3fd2-file_1576478034334){:width=500}
- 我们可以推到出 `DP` 公式为 `amount = x: dp[x] = dp[x] + dp[x - coin]`，其中 `coin = 2 美分`，是当前甜腻骄傲硬币的价值。

![在这里插入图片描述](https://pic.leetcode-cn.com/8eb31f1d6c8d57a0d31f540e4c4771c544f26821ed56d15ff5ace7707684630a-file_1576478034308){:width=500}

**2 美分 + 5 美分 + 10 美分：**
- 我们先增加 `5` 美分的情况，公式是一样的。

![在这里插入图片描述](https://pic.leetcode-cn.com/ee88e1301cd83c63855464771a27b325a637b4ec6ace1e26c791886bf403a60d-file_1576478034338){:width=500}
- 对于 `10` 美分也是一样的。

![在这里插入图片描述](https://pic.leetcode-cn.com/6cff4c7b1d1d8a5874a81444ed90f009c5f888dcb3e3f0a530bd2cf5eaa881e3-file_1576478034336){:width=500}

策略为：
- 从基本情况没有硬币开始，一一添加硬币。
- 对于每个添加的硬币，我们从金额 `0` 到 `amount` 递归的计算组合数量。

**算法：**
- 以基本情况没有硬币开始组合数量。`dp[0] = 1`，然后其余等于 `0`。
- 遍历所有硬币面值：
	*  对于每个硬币，我们将从金额 `0` 遍历到 `amount`：
		* 	对于每个 `x`，计算组合数：`dp[x] += dp[x - coin]`。
- 返回 `dp[amount]`。

```python [solution1-Python]
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        
        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] += dp[x - coin]
        return dp[amount]
```

```java [solution1-Java]
class Solution {
  public int change(int amount, int[] coins) {
    int[] dp = new int[amount + 1];
    dp[0] = 1;

    for (int coin : coins) {
      for (int x = coin; x < amount + 1; ++x) {
        dp[x] += dp[x - coin];
      }
    }
    return dp[amount];
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N \times \textrm{amount})$。其中 `N` 为 `coins` 数组的长度。
* 空间复杂度：$\mathcal{O}(\textrm{amount})$，`dp` 数组使用的空间。