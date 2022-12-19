这题其实就是在求斐波那契数列。理解起来也很简单。假设跳到 n 级台阶有 f(n)种方法。根据题目，青蛙在跳上 n 级时有 2 种方法：

-   从 n - 1 级跳 1 级上来
-   从 n - 2 级跳 2 级上来

青蛙跳到 n- 1 级有 f(n-1)种方法，跳到 n- 2 级有 f(n-2)种方法。所以 f(n) = f(n - 1) + f(n - 2)。这就是斐波那契数列的定义式。

JavaScript实现：

```javascript
// ac地址：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
// 原文地址：https://xxoo521.com/2019-12-26-qing-wa-tiao-tai-jie/

/**
 * @param {number} n
 * @return {number}
 */
var numWays = function(n) {
    const cache = {
        0: 0n,
        1: 1n
    };
    return __jumpFloor(n + 1) % 1000000007n; // 注意下标

    function __jumpFloor(n) {
        if (cache[n] !== undefined) {
            return cache[n];
        }

        cache[n] = __jumpFloor(n - 1) + __jumpFloor(n - 2);
        return cache[n];
    }
};
```
