
## 方法 1: 暴力法

暴力法是通过回溯得到所有可能的排列结果，然后从其中挑选出最小的数字。

这种方法容易想到，虽然能得到正确结果，但是时间复杂度过高，会 TLE。

代码实现如下：

```javascript
// 原文地址：https://xxoo521.com/2020-03-08-array-to-min-num/
/**
 * @param {number[]} nums
 * @return {string}
 */
var minNumber = function(nums) {
    const result = [];
    permutation(nums, 0, result);
    result.sort((a, b) => {
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    });
    return result[0];
};

/**
 * @param {number[]} nums
 * @param {number} start
 * @param {number[]} result
 */
function permutation(nums, start, result) {
    if (start === nums.length) {
        result.push(nums.join(""));
        return;
    }

    for (let i = start; i < nums.length; ++i) {
        [nums[i], nums[start]] = [nums[start], nums[i]];
        permutation(nums, start + 1, result);
        [nums[start], nums[i]] = [nums[i], nums[start]];
    }
}
```

## 方法 2: 快速排序

使用快速排序，可以将数字放在正确的位置上，从而满足题目的要求。例如对于数组【3，32】来说，它有两种排列方法：332、323。显然，323 符合题目的要求。那么在排序的过程中，就应该比较 332 和 323，然后返回正确的顺序。

在 js 中，可以通过参数将自定义的「排序依据」作为函数传入 sort 中，这个函数的逻辑是：

-   如果 `a + b < b + a`，说明 ab 比 ba 小，a 应该在 b 前面，返回-1
-   如果 `a + b > b + a`，说明 ab 比 ba 大，a 应该在 b 后面，返回 1
-   如果相等，返回 0

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
// 原文地址：https://xxoo521.com/2020-03-08-array-to-min-num/

/**
 * @param {number[]} nums
 * @return {string}
 */
var minNumber = function(nums) {
    nums.sort((a, b) => {
        const s1 = a + "" + b;
        const s2 = b + "" + a;

        if (s1 < s2) return -1;
        if (s1 > s2) return 1;
        return 0;
    });
    return nums.join("");
};
```

时间复杂度是$O(NlogN)$,空间复杂度是$O(1)$。

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
