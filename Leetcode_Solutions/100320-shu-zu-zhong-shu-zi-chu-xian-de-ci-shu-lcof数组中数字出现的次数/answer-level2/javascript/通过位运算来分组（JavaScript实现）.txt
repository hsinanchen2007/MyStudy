## 解法：位运算

题目提到了某个元素出现 1 次，其他都是 2 次。这题利用“异或”运算的性质：二进制位相同为 0，不同为 1。所以出现两次的元素，自己和自己异或运算后，就变成了 0.

注意，0 和任意数异或结果都是那个任意数。所以初始值设为 0.

```javascript
// ac地址：https://leetcode-cn.com/problems/single-number/
// 原文地址：https://xxoo521.com/2020-03-25-single-number/

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let res = 0;
    for (let num of nums) {
        res = res ^ num;
    }
    return res;
};
```

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
