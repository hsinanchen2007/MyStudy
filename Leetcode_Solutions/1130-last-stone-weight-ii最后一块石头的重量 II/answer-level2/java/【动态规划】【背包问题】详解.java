
> [更新链接](https://www.zhangjc.site/archives-327/)：https://www.zhangjc.site/archives-327/

## Example:

**示例：**

```
输入：[2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
```

 **提示：**

1. `1 <= stones.length <= 30`
2. `1 <= stones[i] <= 1000`

------

## Analysis

- 由于石头拿走还能放回去，因此可以简单地把所有石头看作两堆
- 假设总重量为 sum, 则问题转化为背包问题：
  - 如何使两堆石头总重量接近 sum / 2

定义：

- `dp[i]`  背包容量限制为 `i` 时能够装载的最大石块总重量
- `curStone` 存在最优解 `dp[i]` 时需要考虑的下一块石块重量

$$\begin{equation}
dp[i]=max\left\{
             \begin{array}{lr}
             \text{dp[i],}&\quad\text{不拿取 curStone,}\\
             \text{dp[i-curStone] + curStone,} &\quad\text{拿取 curStone.}
             \end{array}
\right.
\end{equation} $$



> 具体可以参考背包问题理解

## Solution 【动态规划】

> 执行用时 : 4 ms, 在Last Stone Weight II的Java提交中击败了78.67% 的用户
>
> 内存消耗 : 33.9 MB, 在Last Stone Weight II的Java提交中击败了100.00% 的用户

```java
class Solution {
    public int lastStoneWeightII(int[] stones) {
        /* 由于石头拿走还能放回去，因此可以简单地把所有石头看作两堆
         * 假设总重量为 sum, 则问题转化为背包问题：如何使两堆石头总重量接近 sum / 2
         */
        int len = stones.length;
        /* 获取石头总重量 */
        int sum = 0;
        for (int i : stones) {
            sum += i;
        }
        /* 定义 dp[i] 重量上限为 i 时背包所能装载的最大石头重量 */
        int maxCapacity = sum/2;
        int[] dp = new int[maxCapacity + 1];
        for (int i = 0; i < len; i++) {
            int curStone = stones[i];
            for (int j = maxCapacity; j >= curStone; j--) {
                dp[j] = Math.max(dp[j], dp[j-curStone] + curStone);
            }
        }
        return sum - 2 * dp[maxCapacity];
    }
}
```

#### 复杂度分析

时间：$O(M * N)$

空间：$O(M)$

>    M：石块总重；N：石块总数

