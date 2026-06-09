这题和[《LeetCode 137.只出现一次的数字 II》](https://leetcode-cn.com/problems/single-number-ii/) 一样。

## 解法 1: 最直观的哈希表

解决思路很简单，直接遍历一边数组，然后统计每个数字的出现次数，存入哈希表中。

然后再遍历哈希表中的记录，返回出现次数为 1 的数字。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/single-number-ii/
// 原文地址：https://xxoo521.com/2020-03-25-single-number-ii/
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    const map = new Map();
    for (let num of nums) {
        if (map.has(num)) map.set(num, map.get(num) + 1);
        else map.set(num, 1);
    }

    for (let [num, times] of map.entries()) {
        if (times === 1) return num;
    }
};
```

但是，这种解法利用了额外的$O(N)$空间来开辟哈希表。

## 解法 2: 数学计算

假设对于 a、b、c、d 来说，d 出现了 1 次，其他数字出现 3 次。那么求 d 的值的表达式是：`2 * d = 3*(a + b + c + d) - (3a + 3b + 3c + d)`

为了计算`(a + b + c + d)`，可以将数组去重后，再求和。去重借助的是集合（Set）。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/single-number-ii/
// 原文地址：https://xxoo521.com/2020-03-25-single-number-ii/
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    const set = new Set(nums);
    let sum1 = 0;
    for (let num of set.values()) {
        sum1 += num;
    }
    let sum2 = 0;
    for (let num of nums) {
        sum2 += num;
    }

    return Math.floor((3 * sum1 - sum2) / 2);
};
```

这种方法还是额外使用了$O(N)$的空间。

## 解法 3: 位运算

最符合题目要求的解决方法就是：位运算。能在不开辟额外空间的情况下，完成要求。

按照位数（最高 32 位）去考虑，这种方法的关键就是找到对于只出现一次的数字，它的哪些二进制位是 1。

整体算法流程如下：

-   从第 1 位开始
-   创建掩码（当前位为 1，其他为 0），count 设置为 0
-   将每个数字和掩码进行`&`运算，如果结果不为 0，count 加 1
-   如果 count 整除 3，说明出现一次的数字这一位不是 1；否则，说明出现一次的数字这一位是 1
-   继续检查第 2 位，一直到 32 位，结束

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/single-number-ii/
// 原文地址：https://xxoo521.com/2020-03-25-single-number-ii/
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let res = 0;
    for (let bit = 0; bit < 32; ++bit) {
        let mask = 1 << bit;
        let count = 0;
        for (let num of nums) {
            if (num & mask) ++count;
        }
        if (count % 3) {
            res = res | mask;
        }
    }
    return res;
};
```

时间复杂度是$O(N)$，空间复杂度是$O(1)$。

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
