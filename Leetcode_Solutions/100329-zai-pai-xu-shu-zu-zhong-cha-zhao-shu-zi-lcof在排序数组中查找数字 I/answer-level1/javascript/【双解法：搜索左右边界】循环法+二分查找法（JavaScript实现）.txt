
这题要解决的核心问题就是：搜索数字出现的左右边界。边界的差值，就是出现次数。

## 解法 1: 从两边向中间

思路比较简单：

-   从数组左侧向右遍历，遇到目标数字 target，停止，记录下标 left
-   从数组右侧向左遍历，遇到目标数字 target，停止，记录下标 right
-   如果 right 小于 left，那么说明没出现，返回 0；否则返回 right - left + 1

代码实现：

```javascript
// ac地址：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
// 原文地址：https://xxoo521.com/2020-03-13-find-num-in-sorted/
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    if (!nums.length) return 0;

    let left = 0,
        right = nums.length - 1;
    while (nums[left] !== target && left < nums.length) {
        ++left;
    }
    while (nums[right] !== target && right >= 0) {
        --right;
    }

    return left <= right ? right - left + 1 : 0;
};
```

时间复杂度是$O(N)$，空间复杂度是$O(1)$。

## 解法 2: 二分查找（巧妙）

二分查找一般用来查找数字在有序数组中是否出现过。进一步想，它可以用来不断在子序列中搜索对应数字。所以，我们就可以用它来向左边子序列中不断搜索，确认左边界；同样的思路，确认右边界。

这可能还是有点抽象，举个 🌰。以数组 2、3、3、3、2 为例，我们要搜索数字 3 的左右边界。假设我们先尝试搜索左边界下标 start。

按照二分法思路，`arr[mid] = arr[2] = 3`，更新 start 为 2，同时缩小搜索范围到 `[0, mid - 1] = [0, 1]`。继续按照二分思路，搜索范围缩小到`[1, 1]`，发现值为 3，更新 start 为 1。结束。

按同样方法，可以获得右边界下标 end。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
// 原文地址：https://xxoo521.com/2020-03-13-find-num-in-sorted/
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    const length = nums.length;
    let start = -1,
        end = -1;

    let left = 0,
        right = length - 1;
    // 找到左边界：找到第一次出现
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] === target) {
            start = mid;
            right = mid - 1; // important
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    left = 0;
    right = length - 1;
    // 找到右边界：找到第2次出现
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] === target) {
            end = mid;
            left = mid + 1; // important
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return start <= end && start !== -1 ? end - start + 1 : 0;
};
```

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
