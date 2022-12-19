
## 解法 1: 内置函数（BIF）

第一反应直接调用库函数。

```javascript
// ac地址：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
// 原文地址：https://xxoo521.com/2019-12-31-pow/

/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    return Math.pow(x, n);
};
```

## 解法 2: 二分法

为了方便讨论，假设指数`exponent`是正数。那么递归式如下：

-   如果`exponent`是偶数，`Power(base, exponent) = Power(base, exponent / 2) * Power(base, exponent / 2)`
-   如果`exponent`是奇数，`Power(base, exponent) = base * Power(base, exponent / 2) * Power(base, exponent / 2)`

对于负指数`exponent`的情况，取其绝对值先计算。将最后结果取倒数即可。

时间复杂度是 O(logN)；由于采用递归结构，空间复杂度是 O(logN)。

```javascript
// ac地址：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
// 原文地址：https://xxoo521.com/2019-12-31-pow/

/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    const isNegative = n < 0; // 是否是负指数
    const result = absMyPow(x, Math.abs(n));
    return isNegative ? 1 / result : result;
};

function absMyPow(base, exponent) {
    if (exponent === 0) {
        return 1;
    }

    if (exponent === 1) {
        return base;
    }

    const subResult = absMyPow(base, Math.floor(exponent / 2));
    return exponent % 2 ? subResult * subResult * base : subResult * subResult;
}
```

## 解法 3: 位运算

第 2 种解法可以转换为迭代写法。迭代写法和位运算有关。

为了理解，假设 base=3，exponent= 5。那么 5 的二进制是：101。所以，3 的 5 次方可以写成下图的格式：

![](https://pic.leetcode-cn.com/07b61523ab54c8acd38db44abee96017e29cddfa387488bbaabb3313fe8a842e.jpg)

可以看到，对 base 进行自乘，导致 base 的指数每次都扩大 2 倍。与 exponent 的二进制相对应。

以上图为例，整个算法的流程如下：

-   结果值 result 初始为 1
-   base 初始为 3，此时 exponent 的二进制最右位为 1，更新结果为：base \* result
-   exponent 右移一位。base 进行累乘，base 更新为 3 的 2 次方。由于 exponent 的二进制最右位为 0，不更新结果
-   exponent 右移一位。base 进行累乘，base 更新为 3 的 4 次方。此时 exponent 的二进制最右位为 1，更新结果为：base \* result
-   结束

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
// 原文地址：https://xxoo521.com/2019-12-31-pow/

/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if (n === 0) {
        return 1;
    }
    if (n === 1) {
        return x;
    }

    const isNegative = n < 0; // 是否是负指数
    let absn = Math.abs(n);
    let result = 1;
    while (absn) {
        // 如果n最右位是1，将当前x累乘到result
        if (absn & 1) {
            result = result * x;
        }

        x = x * x; // x自乘法
        absn = Math.floor(absn / 2); // n右移1位
    }

    return isNegative ? 1 / result : result;
};
```

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
