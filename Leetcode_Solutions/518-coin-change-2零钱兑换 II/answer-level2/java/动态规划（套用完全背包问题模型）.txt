关于完全背包问题的介绍，大家可以在互联网上搜索《背包九讲》进行相关知识的学习。本题解有些地方使用了完全背包问题的描述，因此会不加解释的使用“背包”、“容量”这样的名词。

这道题，第一眼看过去和「力扣」 第 377 题：[“组合总和 Ⅳ”](https://leetcode-cn.com/problems/combination-sum-iv/) 很像，不过仔细分析示例就可以看出区别：

+ 「力扣」 第 377 题：一个组合的不同排列是一个新的组合。`(1, 1, 2)`、`(1, 2, 2)`、`(2, 1, 2)` 视为为不同的组合。

+ 「力扣」 第 518 题：**一个组合的不同排列在结果集中只出现一次，这一点是「背包问题」的特征，拿东西的顺序并不重要**。`(2, 2, 1)` 是一个组合，`(1, 2, 2)` 和 `(2, 1, 2)` 不是新的组合。这其实是「力扣」第 39 题：[“组合总和”](https://leetcode-cn.com/problems/combination-sum/)，于是可以尝试使用回溯搜索的写法计算出所有的组合数，参考代码在附录。

问的都是解法有多少种，而不是问具体的解。因此可以考虑使用“动态规划”。

### 方法：动态规划

+ 这道题是典型的“完全背包问题”。“完全背包问题”的特点是：背包里的物品可以无限次选取。

+ 本题特殊的地方在于：从背包里选取的物品必须刚刚好装满需要考虑的容量，而不是小于等于就好，注意这点细微的区别。

+ 完全背包问题是基于 0-1 背包问题的扩展。它们的不同之处在于：


0-1 背包问题：当前考虑的物品用或者不用；

完全背包问题：当前考虑的物品用或者不用，如果用，用几个。

+ 思路依然是：一个一个物品考虑，容量一点一点扩大，整个过程是一个尝试和比较的过程。

#### 第 1 步：定义状态

`dp[i][j]`：硬币列表的前缀子区间 `[0, i]` 能够凑成总金额 `j` 的组合数。

说明：背包问题有一个特点，顺序无关，在最开始，我们强调过这道问题的这个性质，因此可以一个一个硬币去看。


#### 第 2 步：思考状态转移方程

对于遍历到的每一种面值的硬币，逐个考虑添加到 “总金额” 中。由于硬币的个数可以无限选取，因此对于一种新的面值的硬币 `coins[i - 1]`（注意这里有一个位移偏差），依次考虑选取 0 枚、1 枚、2 枚，以此类推，直到选取这种面值的硬币的总金额超过需要的总金额 `j`，`dp[i][j]` 是它们的值的和。

状态转移方程是：

```java [-Java]
dp[i][j] = dp[i - 1][j - 0 * coins[i]] + 
           dp[i - 1][j - 1 * coins[i]] +
           dp[i - 1][j - 2 * coins[i]] + 
           ... + 
           dp[i - 1][j - k * coins[i]]
```
这里状态转移要成立，需要满足：`j - k * coins[i] >= 0`。`dp[i][j]` 相对于 `dp[i - 1][j]` 而言，多考虑的一枚硬币，是“正在考虑的那枚硬币的面值”，`coins[i]`，而这枚硬币选取的个数（从 $0$ 开始）就是 `dp[i][j]` 这个问题可以分解的各个子问题的分类标准。

**事实上，这个状态转移方程有优化的空间，因为做了很多重复的工作，读者可以试着自己优化一下状态转移方程。**

### 第 3 步：思考初始化

`dp[0][0]` 的值应该设置为 1，它虽然没有意义，但是是一个被参考的值，原因是：当 `dp[i - 1][j - k * coins[i]]` 的第 2 个坐标 `j - k * coins[i] == 0` 成立的时候，`k` 个硬币 `coin[i]` 就恰好成为了一种组合，因此，`dp[0][0] = 1`。

填写第 1 行，也是初始化的时候需要考虑的内容，第 1 行即考虑第 1 个数，能够组合出的容量就只有 `coins[0]` 的整数倍数。


> **事实上，可以考虑多设置一行，把第 1 行除了 `dp[0][0]` 全部设置为 `0`，这样可以避免这种复杂的初始化讨论，这一步留给读者完成。**

#### 第 4 步：思考输出

输出就是表格的最后一格的数值，即 `dp[len - 1][amount]`。

#### 第 5 步：考虑状态压缩

当前状态行的值，只和上一行的状态值相关，因此可以考虑状态压缩，使用滚动数组技巧即可，这里暂不展示代码。

**参考代码 1**：

```Java []
public class Solution {

    public int change(int amount, int[] coins) {
        int len = coins.length;
        if (len == 0) {
            if (amount == 0) {
                return 1;
            }
            return 0;
        }

        int[][] dp = new int[len][amount + 1];
        // 这个值语义不正确，但是是一个被其它状态参考的值，这样设置是正确的
        dp[0][0] = 1;

        // 填第 1 行
        for (int i = coins[0]; i <= amount; i += coins[0]) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= amount; j++) {
                for (int k = 0; j - k * coins[i] >= 0; k++) {
                    dp[i][j] += dp[i - 1][j - k * coins[i]];
                }
            }
        }
        return dp[len - 1][amount];
    }
}
```

**复杂度分析**：
+ 时间复杂度：$O(NM^2)$，这里金额为 $M$，硬币数为 $N$。第 1 层循环与硬币总数同规模，第 2 层循环与要求的总金额同规模，第 3 层循环在“最坏情况下”，硬币的面值为 $1$ 时，与要求的总金额同规模。
+ 空间复杂度：$O(NM)$，表格有 $N$ 行，$M$ 列。 


#### 补充：「滚动数组」技巧代码

说明：如果要使用「滚动数组」技巧来计算，当前行的值应该先恢复为 0，这是因为上一行在 `j - k * coins[i] >= 0` 的时候才计算结果，后面的部分没有计算就直接到下一行了。

如果直接使用「滚动数组」的话，就有可能引用到错误的结果。

想象一下填表的过程，如果不设置为 0，就有可能引用到错误的结果。

也就是说，**在填表的时候，不是每一格都会计算结果**。这些细节如果不好想明白，可以自己模拟一下填表的过程就清楚了。

**参考代码 0**：（因为中途加塞，这里将代码编号为 0）

```Java []
import java.util.Arrays;

class Solution {

    public int change(int amount, int[] coins) {
        int len = coins.length;
        if (len == 0) {
            if (amount == 0) {
                return 1;
            }
            return 0;
        }

        int[][] dp = new int[2][amount + 1];
        dp[0][0] = 1;

        for (int i = coins[0]; i <= amount; i += coins[0]) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < len; i++) {
            // 注意：如果写成滚动数组的情况，这一行完全参考上一行的值
            // 当前行的值应该先恢复为 0，这是因为上一行只在 j - k * coins[i] >= 0 的时候才计算结果，后面的部分程序没有计算直接跳到下一行了
            // 如果不清空为 0，就有可能引用到错误的结果
            Arrays.fill(dp[i & 1], 0);
            
            for (int j = 0; j <= amount; j++) {
                for (int k = 0; j - k * coins[i] >= 0; k++) {
                    dp[i & 1][j] += dp[(i - 1) & 1][j - k * coins[i]];
                }
            }
        }
        return dp[(len - 1) & 1][amount];
    }
}
```


### 方法二：优化状态转移方程

根据状态转移方程其实可以得到递推公式。状态转移方程的表达形式“看起来”像是一个“无穷级数”，可以通过如下方式得到一个 “递推公式” 

```java [-Java]
dp[i][j] = dp[i - 1][j - 0 * coins[i - 1]] + 
           dp[i - 1][j - 1 * coins[i - 1]] +
           dp[i - 1][j - 2 * coins[i - 1]] + 
           ... + 
           dp[i - 1][j - k * coins[i - 1]]
```
这里 `j - k * coins[i] >= 0`。我们将这个等式记为“等式（1）。

**将 `j` 用 `coins[i]` 替换**，得：

```java [-Java]
dp[i][j - coins[i]] = dp[i - 1][j - coins[i] - 0 * coins[i]] + 
                      dp[i - 1][j - coins[i] - 1 * coins[i]] +
                      dp[i - 1][j - coins[i] - 2 * coins[i]] + 
                      ... + 
                      dp[i - 1][j - coins[i] - k * coins[i]]
```

这里 `j - coins[i] - k * coins[i] >= 0`。

整理一下：

```java [-Java]
dp[i][j - coins[i]] = dp[i - 1][j - 1 * coins[i]] + 
                      dp[i - 1][j - 2 * coins[i]] +
                      dp[i - 1][j - 3 * coins[i]] + 
                      ... + 
                      dp[i - 1][j - k * coins[i]]
```

这里 `j - k * coins[i] >= 0`。我们将这个等式记为“等式（2）”。

将 `等式（1）- 等式（2）`，得：

``` [-Java]
dp[i][j] - dp[i][j - coins[i]] = dp[i - 1][j]
```

整理得：

``` [-Java]
dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]
```

所以其实每一行单元的值的填写**我们只要看它的左边就好了**，如果没有左边，它至少是上一行单元格的值。

> 请读者比较这里状态压缩和 0-1 背包问题的不同之处。

**参考代码 2**：

```Java []
public class Solution {

    public int change(int amount, int[] coins) {
        int len = coins.length;
        if (len == 0) {
            if (amount == 0) {
                return 1;
            }
            return 0;
        }

        int[][] dp = new int[len][amount + 1];
        dp[0][0] = 1;

        for (int i = coins[0]; i <= amount; i += coins[0]) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i] >= 0) {
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }
        return dp[len - 1][amount];
    }
}
```

**复杂度分析**：
+ 时间复杂度：$O(NM)$，这里金额为 $M$，硬币数为 $N$。与参考代码 1 相比缩减了最内层的循环，时间复杂度降低了一级。
+ 空间复杂度：$O(NM)$，表格有 $N$ 行，$M$ 列。 

#### 第 5 步：考虑状态压缩

这个方法只是优化了状态转移方程，因此，我们直接跳到第 5 步，考虑状态压缩。

**参考代码 3**：

```Java []
public class Solution {

    public int change(int amount, int[] coins) {
        int len = coins.length;
        if (len == 0) {
            if (amount == 0) {
                return 1;
            }
            return 0;
        }

        int[] dp = new int[amount + 1];
        dp[0] = 1;

        for (int i = coins[0]; i <= amount; i += coins[0]) {
            dp[i] = 1;
        }

        for (int i = 1; i < len; i++) {
            
            // 从 coins[i] 开始即可
            for (int j = coins[i] ; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
}
```

**复杂度分析**：
+ 时间复杂度：$O(NM)$，这里金额为 $M$，硬币数为 $N$。
+ 空间复杂度：$O(M)$，表格只有 $1$ 行，$M$ 列。  


附录：使用回溯方法计算组合总数。

**参考代码**：

注意：以下的代码虽然正确，但不能得到 Accept。

```Java []
import java.util.Arrays;

public class Solution {

    // 该解法超时，问题规模小的时候可用

    private int res = 0;

    public int change(int amount, int[] coins) {
        int len = coins.length;
        Arrays.sort(coins);

        backtracking(amount, coins, 0, len);
        return res;
    }

    private void backtracking(int residue, int[] coins, int start, int len) {
        if (residue == 0) {
            res++;
            return;
        }

        for (int i = start; i < len; i++) {
            if (residue - coins[i] < 0) {
                break;
            }
            backtracking(residue - coins[i], coins, i, len);
        }
    }
}
```