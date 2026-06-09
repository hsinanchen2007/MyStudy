
// 这里的不使用任何额外空间，指的是不为哈希表开辟额外空间。最后要返回的元素，还是要放在数组内的。

// ## 思路实现

// 因为不能使用额外空间存储哈希表，所以只能对数组本身做操作。题目提到元素的范围是 1 到 n，并且元素只可能出现 1 次或者 2 次。

// 因此这里可以使用符号来标记元素是否出现过。下标为 i 的元素的符号，代表着值为 i + 1 的元素是否出现过，负号是出现过，正号是没出现过。

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
// 原文地址：https://xxoo521.com/2020-02-14-find-all-duplicates-in-an-array/
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    const res = [];
    for (const num of nums) {
        const absNum = Math.abs(num);
        if (nums[absNum - 1] < 0) {
            res.push(absNum);
        } else {
            nums[absNum - 1] = -1 * nums[absNum - 1];
        }
    }

    return res;
};
// ```

// 空间复杂度是 O(1)，时间复杂度是 O(N)。

// ## 更多资料

// -   **📖Blog：[剑指 Offer/LeetCode 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
