
## 题目分析

如果想了解汉明距离的相关知识，请参考：[LeetCode 461.汉明距离](https://xxoo521.com/2020-03-04-hamming-distance/)。里面介绍了两种做法：

-   使用掩码
-   使用布赖恩·克尼根算法

但本题要求计算数组中任何两数之间的汉明距离，因此若是两两组合，直接计算汉明距离，最后再统计总和，那么时间复杂度是$O(k*N^2)$，其中 k 是位数。时间复杂度过高，无法达到要求。

## 解法：按位统计

按位统计的算法流程是：

-   准备数组 res，`res[i]`代表第 i 位为 1 的数字的数目
-   循环遍历 nums，对每一位 i 更新对应的 `res[i]`
-   统计所有位的汉明距离的和，其中第 i 位上的汉明距离之和是：`res[i] * (nums.length - res[i])`

注意：根据题目要求，数字的大小不超过 10^9，所以只需要用 30 个二进制表示数字即可。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/total-hamming-distance/
// 原文地址：https://xxoo521.com/2020-03-04-total-hamming-distance/

/**
 * @param {number[]} nums
 * @return {number}
 */
var totalHammingDistance = function(nums) {
    // 根据题目要求，不超过10^9，所以30位就可以了
    const res = new Array(30).fill(0);
    for (let num of nums) {
        let bit = 0;
        let mask = 0x01;
        while (bit < 30) {
            if (num & mask) {
                ++res[bit];
            }
            ++bit;
            mask = mask << 1;
        }
    }

    const length = nums.length;
    return res.reduce((pre, cur) => pre + cur * (length - cur), 0);
};
```

## 更多资料

**若有错误，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
