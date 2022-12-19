
## 题目分析

我印象中看第一版书的时候，这题的考察点是需要用字符串处理大数。但是仔细看这题给的 JavaScript 模版，函数返回的类型是`number[]`，所以不是考察字符串和大数，否则的话字符串还得转换成数字，照样越界。_以字符串为考点的可以看这篇文章[《打印从 1 到最大的 n 位数》](https://xin-tan.com/passages/2019-06-23-recursive-loop-from-one-to-one/)_。

思来想去，感觉 leetcode 上的这题考察的是乘幂的优化。我在[《剑指 offer - 数值的整次方(四种解法)》](https://xxoo521.com/2019-12-31-pow/)这篇文章中详细讲解了求整次方的几种做法。**本题显然不需要封装通用的函数，只需要对 10 的 n 次方进行快速计算即可**。

## 解法 1:BIF

直接调用内置函数即可：

```javascript
// ac地址：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-17-from-one-to-n/

/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    const max = Math.pow(10, n) - 1;
    const res = [];
    for (let i = 1; i <= max; ++i) {
        res.push(i);
    }
    return res;
};
```

由于 leetcode 对 es 规范支持的很好，这里可以直接使用`**`运算符，简化写法：

```javascript
// ac地址：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-17-from-one-to-n/

/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    const max = 10 ** n - 1;
    const res = [];
    for (let i = 1; i <= max; ++i) {
        res.push(i);
    }
    return res;
};
```

## 解法 2: 位运算

具体推导请看[《剑指 offer - 数值的整次方(四种解法)》](https://xxoo521.com/2019-12-31-pow/)的“第四部分”。代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-17-from-one-to-n/

/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    let max = 1;
    let x = 10;
    while (n) {
        if (n & 1) {
            max = max * x;
        }
        x = x * x;
        n = n >> 1;
    }

    const res = [];
    for (let i = 1; i < max; ++i) {
        res.push(i);
    }
    return res;
};
```

**注意：解法 2 的执行用时远远低于解法 1**

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
