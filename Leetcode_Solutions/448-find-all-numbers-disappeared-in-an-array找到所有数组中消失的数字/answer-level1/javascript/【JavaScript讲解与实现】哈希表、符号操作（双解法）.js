
// 这一题和[Leetcode 442.数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)解决思路很相似。但没有完全明确的限制空间使用。

// ## 解法 1：哈希表

// 算法流程如下：

// -   准备一个哈希表 map，结构是`number-boolean`
// -   遍历原数组，将每个元素在 map 中的值设为 true
// -   从 1 到 n，检查`map[i]`是否为 true。若是 true，说明出现在原数组中；否则是没出现过。

// 这个过程需要为哈希表开辟 O(N)空间，时间复杂度是 O（N）。代码如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
// 原文地址：https://xxoo521.com/2020-02-14-find-all-numbers-disappeared-in-an-array/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    const length = nums.length;
    if (!length) {
        return [];
    }

    const map = {};
    nums.forEach(num => (map[num] = true));

    const res = [];
    for (let i = 1; i <= length; ++i) {
        if (!map[i]) res.push(i);
    }

    return res;
};
// ```

// ## 解法 2: 原地哈希

// 和[Leetcode 442.数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)的解法相似：**使用符号来标记元素是否出现过**。下标为 i 的元素的符号，代表着值为 i + 1 的元素是否出现过，负号是出现过，正号是没出现过。

// 不需要开辟空间给哈希表，时间复杂度是 O（N）。代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
// 原文地址：https://xxoo521.com/2020-02-14-find-all-numbers-disappeared-in-an-array/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    const length = nums.length;
    if (!length) {
        return [];
    }

    nums.forEach(num => {
        // 将下标为 abs(num) - 1 的元素变成负数
        const absNum = Math.abs(num);
        if (nums[absNum - 1] > 0) {
            nums[absNum - 1] *= -1;
        }
    });

    const res = [];
    // 针对“数组下标”进行遍历
    for (let i = 1; i <= length; ++i) {
        // 如果下标 i-1 的元素是正数，说明整数 i 没出现过（要不然前面循环就变成负数了）
        if (nums[i - 1] > 0) {
            res.push(i);
        }
    }

    return res;
};
// ```

// ## 更多资料

// -   **📖Blog：[剑指 Offer/LeetCode 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
