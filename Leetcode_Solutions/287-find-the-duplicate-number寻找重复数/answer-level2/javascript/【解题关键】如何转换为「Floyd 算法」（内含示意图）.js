// ## 解法 1: Floyd 算法(符合题意)

// Floyd 算法才是符合“说明”中的所有要求的正确解法。Floyd 算法是为了解决链表中是否存在环，以及环的入口的问题，有两道相关的题目，可以通过它们来掌握 Floyd 的应用：

// -   [LeetCode 141.环形链表](https://xxoo521.com/2020-03-03-linked-list-cycle/)
// -   [LeetCode 142.环形链表](https://xxoo521.com/2020-03-03-linked-list-cycle-ii/)

// **那么，现在的问题关键是怎么将数组转换为链表判环的问题？**

// 由于数组长度是 n + 1，里面元素的范围是【1，n】。所以，**对于值为 v 的元素，可以将它看作链表中的一个节点，定义它的 next 指针指向 `nums[v]`**。若是存在重复数字，则这条链表中一定存在环，且唯一重复的数字是环的入口。

// 为了方便说明，我们以下面的数组为例。index 是下标，val 是值，name 是为了方便在链表中表示节点：

// ![](https://pic.leetcode-cn.com/8593b9d954592b82c22db0d01dadbe49852c40f7564f884f11e3aa559dc5612e.jpg)

// 那么按照规则，链表如下：

// ![](https://pic.leetcode-cn.com/bd97d0d5ab403ece61b78c0e4a99649237114ab01d77f3c1093644c95c0cdebe.jpg)

// 环的入口节点 C 对应着 val 为 3，就是我们要找的重复数字。

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/find-the-duplicate-number/
// 原文地址：https://xxoo521.com/2020-03-03-find-the-duplicate-number/
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    let intersect = getIntersect(nums);
    let ptr1 = nums[0];
    let ptr2 = intersect;
    while (ptr2 !== ptr1) {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }

    return ptr2;
};

/**
 * @param {number[]} nums
 * @param {number}
 */
function getIntersect(nums) {
    let fast = nums[0];
    let slow = nums[0];

    do {
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
    } while (fast !== slow);

    return fast;
}
// ```


// ## 解法 2: 原地哈希

// 这种思路和[《LeetCode 442.数组中重复的数据》](https://xxoo521.com/2020-02-14-find-all-duplicates-in-an-array/)一样，用数组元素的符号代表当前元素是否出现过：

// -   若`nums[i] < 0`: 数字 i 出现过
// -   若`nums[i] > 0`: 数字 i 没出现过

// 代码实现：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/find-the-duplicate-number/
// 原文地址：https://xxoo521.com/2020-03-03-find-the-duplicate-number/
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    const length = nums.length;

    for (let i = 0; i < length; ++i) {
        const val = Math.abs(nums[i]);
        if (nums[val] < 0) {
            return val;
        } else {
            nums[val] *= -1;
        }
    }
};
// ```

// **注意**：这种解法不符合“说明”中的第一条，不能更改原数组。

// ## 更多资料

// **若有纰漏，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

// -   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
