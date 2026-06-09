
// ## 解法：找规律

// 写出这些数据，可以发现：

// -   1 位数字有 9 个：1-9
// -   2 位数字有 90 个：10-99
// -   3 位数字有 900 个：100-999
// -   k 位数字有 `9 * 10^k` 个

// 所以解决思路就是先通过循环，确定所要查找的数字落在第几位。最后通过计算找出数字即可。例如对于 n=13 来说，过程如下：

// -   n 大于 9，说明不是 1 位数字，n 更新为 n - 9 = 4。继续循环。
// -   n 小于 90，说明是 2 位数字。
// -   计算要找的数字 num：`num = 10 + int(4/2) - 1 = 11`
// -   计算结果在 num 中的位置：`pos = 4 - 2 * (11 - 10) - 1 = 1`

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/nth-digit/
// 原文地址：https://xxoo521.com/2020-03-09-n-number/
/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function(n) {
    for (let bit = 1; bit < 32; ++bit) {
        const startNum = Math.pow(10, bit - 1);
        const bitSum = 9 * startNum * bit;
        if (n > bitSum) {
            n -= bitSum;
        } else {
            let num = startNum + Math.ceil(n / bit) - 1;
            let pos = n - bit * (num - startNum) - 1;
            return num.toString(10)[pos];
        }
    }
};
// ```

// n 的取值范围决定了循环的次数，也决定了时间复杂度。

// ## 更多资料

// **整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
