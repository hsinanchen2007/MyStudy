### 解题思路
* 一开始想到回溯算法，基础用例全部通过
* 提交性能超时，考虑到动态规划
* 动态规划一般由两种方法来实现：自顶向下和自底向上
* 自顶向下，使用中备忘录方式，用递归实现
* 自底向上，采用迭代方式实现
* 自底向上是我们最常碰到的使用的动态规划套路，最后一个结果的得出需要依赖前面所有结果的计算结果
* 迭代方法计算1亿次耗时1秒

#### 自顶向下备忘录式动态规划
* 最难理解的缓存位置：记录当前零钱需要最少多少个硬币找零
* 缓存数组10块钱需要最小硬币个数，int[] cached = new int[10]，10块钱存在[0..9]数组的9的位置
* 缓存数组20块钱需要最小硬币个数，int[] cached = new int[20]，20块钱存在[0..19]中19的位置
* 从缓存中返回所需要的最小硬币个数

#### 自底向上（迭代方式）动态规划
定义 F(i) 为组成金额 i 所需最少的硬币数量
假设在计算 F(i) 之前，我们已经计算出 F(0)-F(i-1)F(0)−F(i−1) 的答案。 
F(i)	最小硬币数量
F(0)	0     //金额为0不能由硬币组成
F(1)	1     //F(1)=min(F(1-1),F(1-2),F(1-5))+1=1
F(2)	1     //F(2)=min(F(2-1),F(2-2),F(2-5))+1=1
F(3)	2     //F(3)=min(F(3-1),F(3-2),F(3-5))+1=2
F(4)	2     //F(4)=min(F(4-1),F(4-2),F(4-5))+1=2
...	...
F(11)	3     //F(11)=min(F(11-1),F(11-2),F(11-5))+1=3
具体化示例： 
F(3) = min(F(3−c1),F(3−c2),F(3−c3))+1
     = min(F(3−1),F(3−2),F(3−3))+1
     = min(F(2),F(1),F(0))+1
     = min(1,1,0)+1
     = 1

* 判断金额凑不出的小技巧
先初始化DP table各个元素为amount + 1（代表不可能存在的情况），在遍历时如果金额凑不出则不更新，于是若最后结果仍然是amount + 1，则表示金额凑不出

### 代码
```java []
//方案一、回溯算法 超时
class Solution {
    private int result = Integer.MAX_VALUE;
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        List<Integer> queue = new ArrayList<>();
        backtrack(coins,0,amount,queue);
        return result == Integer.MAX_VALUE ? -1 : result;
    }
    private void backtrack(int[] coins, int index, int residue,List<Integer> queue) {
        if (residue == 0) {
            // 取最小值
            result = Math.min(result,queue.size());
            return;
        }
        if(residue < 0 || index >= coins.length) {
            return;
        }
        for (int i = 0; i < coins.length; i++) {
            queue.add(coins[i]);
            int newResidue = residue - coins[i];
            backtrack(coins, i, newResidue, queue);
            queue.remove(queue.size()-1);
        }
    }
}
```
```java []
//方案二、自顶向下动态规划 执行用时 : 63 ms, 在所有 Java 提交中击败了7.53% 的用户
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount < 1) {
            return 0;
        }
        int[] cached = new int[amount];
        return coinChange(coins,amount,cached);
    }
    private int coinChange(int[] coins, int residue, int[] cached) {
        if (residue < 0) {
            // 没有任何硬币组合组成需要找零的总金额，返回-1
            return -1;
        }
        if (residue == 0) {
            // 所有硬币组合正好满足要找零的总金额，返回0个硬币
            return 0;
        }
        if (cached[residue - 1] != 0) {
           return cached[residue-1];
        }
        int minCoinCount = Integer.MAX_VALUE;
        for (int coin : coins) {
            int coinCount = coinChange(coins, residue - coin, cached);
            if (coinCount >= 0 && coinCount < minCoinCount) {
                minCoinCount = 1 + coinCount;
            }
        }
        //最难理解的缓存位置：记录当前零钱最少要用多少个硬币个数
        //10块钱存在[0..9]数组的9的位置,19存储在[0..18]中18的位置
        cached[residue - 1] = minCoinCount == Integer.MAX_VALUE ? -1 : minCoinCount;
        return cached[residue - 1];
    }
}
========================================================
// 方案二的变革，取消数组减一造成理解困难的问题
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount < 1) {
            return 0;
        }
        int[] cached = new int[amount + 1];
        return coinChange(coins,amount,cached);
    }
    private int coinChange(int[] coins, int residue, int[] cached) {
        if (residue < 0) {
            // 没有任何硬币组合组成需要找零的总金额，返回-1
            return -1;
        }
        if (residue == 0) {
            // 所有硬币组合正好满足要找零的总金额，返回0个硬币
            return 0;
        }
        if (cached[residue] != 0) {
           return cached[residue];
        }
        int minCoinCount = Integer.MAX_VALUE;
        for (int coin : coins) {
            int coinCount = coinChange(coins, residue - coin, cached);
            if (coinCount >= 0 && coinCount < minCoinCount) {
                minCoinCount = 1 + coinCount;
            }
        }
        //最难理解的缓存位置：记录当前零钱最少要用多少个硬币个数
        //10块钱存在[1..10]数组的10的位置,19存储在[1..19]中19的位置
        cached[residue] = minCoinCount == Integer.MAX_VALUE ? -1 : minCoinCount;
        return cached[residue];
    }
}
```
```java []
//方案三、自底向上动态规划
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount < 1) {
            return 0;
        }

        int[] dp = new int[amount + 1];
        final int MAX = amount + 1;
        Arrays.fill(dp, MAX);
        // 设置dp初始状态
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        // 不能使用Integer.MAX_VALUE，因为最大值加1时会溢出变成负数，造成取最小值失败
        return dp[amount] == MAX ? -1 : dp[amount];
    }
}
```