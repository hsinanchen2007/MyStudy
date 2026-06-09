// **注意：由于测试数据会溢出 js 中的整数范围，所以请使用大数（bigint）类型！！！**

// ## 解法 1: 数学定义

// 根据数学定义：`f(n) = f(n - 1) + f(n - 2)`。最初始情况是`f(0) = 0`和`f(1) = 1`。

// 因此直接循环更新即可。时间复杂度 O(N)，空间复杂度 O(1)。

// ```javascript
// ac地址：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
// 原文地址：https://xxoo521.com/2019-12-25-fei-bo-na-qi/

/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if (n === 0) {
        return 0;
    }
    if (n === 1) {
        return 1;
    }

    let a = 0n,
        b = 1n;
    for (let i = 2n; i < n; ++i) {
        let c = a + b;
        a = b;
        b = c;
    }

    return (a + b) % 1000000007n;
};
// ```

// ## 解法 2: 递归 + 动态规划

// 根据数学定义：`f(n) = f(n - 1) + f(n - 2)`，代码可以实现为递归形式。

// 但是以 f(5)为例，它的过程如下：

// 1. f(5) = f(4) + f(3)
// 2. f(4) = f(3) + f(2)
// 3. f(3) = f(2) + f(1)
// 4. ...省略

// 注意在第 2 步和第 3 步中，我们计算了 2 次 f(3)的值。当要求的 n 越大的时候，重复计算就会越多，时间复杂度就会越高。

// **在动态规划的一种做法中，可以借助“备忘录”来实现结果的缓存，避免重复计算**。

// 代码如下，时间复杂度是 O(N)，空间复杂度是 O(1)。

// ```javascript
// ac地址：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
// 原文地址：https://xxoo521.com/2019-12-25-fei-bo-na-qi/

/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    const cache = {
        0: 0n,
        1: 1n
    };
    return Fibonacci(n) % 1000000007n;

    /**
     * @param {number} n
     * @return {number}
     */
    function Fibonacci(n) {
        if (cache[n] !== undefined) {
            return cache[n];
        }

        cache[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
        return cache[n];
    }
};
// ```

// ## “备忘录”的其他优点

// 虽然备忘录用了 O(N)的空间。但是重复计算同个 f(n)的结果时候，时间复杂度是 O(1)。比如之前调用过一次`Fibonacci(10)`，那么 f(10)的结果就缓存在了 cache 中。再次调用函数，直接从缓存读取即可。

// 同样地，当 n < 10 时候，结果都是从 cache 中直接读取，时间复杂度均是 O(1)。

// 再推广，当计算 f(20)的时候，n < 10 的结果都计算完了，不需要重复计算。效率是高于第一种循环写法的调用。

// **总结：备忘录缓存了计算结果，避免了多次调用时的重复计算**。

// ## 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
