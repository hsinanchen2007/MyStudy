leetcode官方的题解已经图文并茂诠释得清楚了。

本题解的具体解题思路照搬[官方题解 （方法三、动态规划：自下而上）](https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/)，没有阅读官方题解的朋友可以大概阅读下。

当然，本题解的注释内容也很详解，哪怕没有阅读过官方题解，也不妨碍继续往下阅读。


```
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
 var coinChange = function(coins, amount) {
    // 本题采用 自底向上 的动态规划解法
    /*
    首先，构造出amount+1的数组，
    之所以+1,是为了保障最后的金额（最初的原始金额）有位置可以存放
    例如：amount[11]存放着总金额11的最少金币组合
    */
    // 数组中每一项都事先赋为正无穷，便于与最小值的判断
    let dp = new Array(amount + 1).fill(Infinity);
    // 首先预先赋值为0，因为金额0的解法有0种
    dp[0] = 0;

    /*
    破题关键
    每种金额的解法至1金币始，循环到金额amount为止。
    每次外层for循环时，内部的for...of循环来判断是否可用现有的金币组合来组成amount金币量
    举例：amount为11，coins为[1,2,5]，则取以下解法的最小值
    coins为1时，amount[11] = 1(利用硬币金额1来解，故占一个金额的位置) + amount[11-1]（假设已知，且为最小值）
    coins为2时，amount[11] = 1(利用硬币金额2来解，故占一个金额的位置) + amount[11-2]（假设已知，且为最小值）
    coins为5时，amount[11] = 1(利用硬币金额5来解，故占一个金额的位置) + amount[11-5]（假设已知，且为最小值）
    */
    for(let i = 1; i <= amount; i++) {
        for(let coin of coins) {
            if (i - coin >= 0) {
                // dp[i]本身的解法 和 dp[当前的总金额i(即amount) - 遍历的icon] + 1(遍历的icon) 的解法的最小值
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // 如果结果为无穷大，则无解
    return dp[amount] === Infinity ? -1 : dp[amount];
};
```
