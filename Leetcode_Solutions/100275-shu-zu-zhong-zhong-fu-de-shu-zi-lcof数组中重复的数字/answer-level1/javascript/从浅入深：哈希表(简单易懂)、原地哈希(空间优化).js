
// ## 解法 1: 使用哈希表

// 哈希表的结构是：number-boolean，number 就是数组中的数字，boolean 代表数字是否出现过。

// 整体的流程是：遍历数组中的数字，检查是否出现过，如果出现过，那么返回此数字。代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
// 原文地址：https://xxoo521.com/2020-02-14-repeat-number/

/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const map = {};
    for (const num of nums) {
        if (!map[num]) {
            map[num] = true;
        } else {
            return num;
        }
    }
};
// ```

// 由于使用了哈希表，所以空间复杂度是 O(N)。需要遍历一次，时间复杂度是 O(1)。

// ## 解法 2: 原地哈希（推荐）

// 从题目描述可以知道，所有数字都在 0 ～ n-1 的范围内。因此不需要额外开辟空间，每次遍历时，检查当前元素是否放在了正确位置上（例如元素 i 应该放在下标为 i 的位置上）。如果放在了正确位置上，那么继续循环。否则：

// -   下标为 num 的元素 === num，说明当前元素 num 是重复的，直接返回
// -   下标为 num 的元素 !== num，交换当前元素和下标为 num 的元素，将当前元素放入到正确位置上

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
// 原文地址：https://xxoo521.com/2020-02-07-half-number/

/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const length = nums.length;
    for (let i = 0; i < length; ++i) {
        //检测下标为i的元素是否放在了位置i上
        while ((num = nums[i]) !== i) {
            if (num === nums[num]) {
                return num;
            }
            [nums[i], nums[num]] = [nums[num], nums[i]];
        }
    }
};
// ```

// **这里要注意的是**，第二种情况交换完元素后，应该继续检测下标为 i 的元素是否放在了位置 i 上，实现上使用`while`内循环即可。以`[1, 3, 2, 3]`为例，第一次交换后，变为`[3, 1, 2, 3]`，如果没有内循环，那么就会跳过第一个 3，继续遍历，而后面的元素又恰巧都在正确位置上，最终没有检查出重复元素。**特别感谢[@彻](https://leetcode-cn.com/u/che-28/)的提示。**

// ## 错误代码

// 这段代码在 leetcode 上可以 ac，建议官方添加测试用例：`[1, 3, 2, 3]`。

// ```javascript
// ac地址：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
// 原文地址：https://xxoo521.com/2020-02-14-repeat-number/

/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const length = nums.length;
    for (let i = 0; i < length; ++i) {
        const num = nums[i];
        if (num === i) {
            continue;
        }

        if (num === nums[num]) {
            return num;
        } else {
            [nums[i], nums[num]] = [nums[num], nums[i]];
        }
    }
};
// ```

// ## 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
