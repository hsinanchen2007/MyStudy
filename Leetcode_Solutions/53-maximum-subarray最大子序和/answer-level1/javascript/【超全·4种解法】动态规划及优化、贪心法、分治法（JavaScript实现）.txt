
虽然这题在 leetcode 上标注的是「简单」难度，但是解法有 4 种，并且都非常具有代表性。比较容易想到的是基础的动态规划法。

## 解法 1：动态规划

定义状态数组`dp[i]`的含义：数组中元素下标为`[0, i]`的连续子数组最大和。

状态转移的过程如下：

-   初始情况：`dp[0] = nums[0]`
-   若 `nums[i] > 0`，那么 `dp[i] = nums[i] + dp[i - 1]`
-   若 `nums[i] <= 0`，那么 `dp[i] = nums[i]`

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/maximum-subarray/
// 原文地址：https://xxoo521.com/2020-03-09-max-sub-sum/
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    const dp = [];

    let res = (dp[0] = nums[0]);
    for (let i = 1; i < nums.length; ++i) {
        dp[i] = nums[i];
        if (dp[i - 1] > 0) {
            dp[i] += dp[i - 1];
        }
        res = Math.max(res, dp[i]);
    }
    return res;
};
```

时间复杂度和空间复杂度都是$O(N)$。

## 解法 2：原地进行动态规划

解法 1 中开辟了 dp 数组。其实在原数组上做修改，用`nums[i]`来表示`dp[i]`。所以解法 1 的代码可以优化为：

```javascript
// ac地址：https://leetcode-cn.com/problems/maximum-subarray/
// 原文地址：https://xxoo521.com/2020-03-09-max-sub-sum/
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let res = nums[0];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i - 1] > 0) {
            nums[i] += nums[i - 1];
        }
        res = Math.max(res, nums[i]);
    }
    return res;
};
```

不用开辟额外空间，所以空间复杂度降为$O(1)$。

## 解法 3：贪心法

贪心法的题目比较少见，而且一般都比较难证明。本题的贪心法的思路是：在循环中找到不断找到当前最优的和 sum。

注意：sum 是 `nums[i]` 和 `sum + nums[i]`中最大的值。这种做法保证了 sum 是一直是针对连续数组算和。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/maximum-subarray/
// 原文地址：https://xxoo521.com/2020-03-09-max-sub-sum/
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let maxSum = (sum = nums[0]);
    for (let i = 1; i < nums.length; ++i) {
        sum = Math.max(nums[i], sum + nums[i]);
        maxSum = Math.max(maxSum, sum);
    }
    return maxSum;
};
```

空间复杂度为$O(1)$，时间复杂度为$O(N)$

## 解法 4: 分治法

分治法的做题思路是：先将问题分解为子问题；解决子问题后，再将子问题合并，解决主问题。

使用分治法解本题的思路是：

-   将数组分为 2 部分。例如 `[1, 2, 3, 4]` 被分为 `[1, 2]` 和 `[3, 4]`
-   通过递归计算，得到左右两部分的最大子序列和是 lsum，rsum
-   从数组中间开始向两边计算最大子序列和 cross
-   返回 max(lsum, cross, rsum)

整体过程可以参考来自 [Leetcode 官方题解](https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode/)的图：

![](https://pic.leetcode-cn.com/3aa2128a7ddcf1123454a6e5364792490c5edff62674f3cfd9c81cb7b5e8e522-file_1576478143567)

可以看到，分治法可行的关键的是：最大子序列和只可能出现在左子数组、右子数组或横跨左右子数组 这三种情况下。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/maximum-subarray/
// 原文地址：https://xxoo521.com/2020-03-09-max-sub-sum/

/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} right
 * @param {number} mid
 * @return {number}
 */
function crossSum(nums, left, right, mid) {
    if (left === right) {
        return nums[left];
    }

    let leftMaxSum = Number.MIN_SAFE_INTEGER;
    let leftSum = 0;
    for (let i = mid; i >= left; --i) {
        leftSum += nums[i];
        leftMaxSum = Math.max(leftMaxSum, leftSum);
    }

    let rightMaxSum = Number.MIN_SAFE_INTEGER;
    let rightSum = 0;
    for (let i = mid + 1; i <= right; ++i) {
        rightSum += nums[i];
        rightMaxSum = Math.max(rightMaxSum, rightSum);
    }

    return leftMaxSum + rightMaxSum;
}

/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
function __maxSubArray(nums, left, right) {
    if (left === right) {
        return nums[left];
    }

    const mid = Math.floor((left + right) / 2);
    const lsum = __maxSubArray(nums, left, mid);
    const rsum = __maxSubArray(nums, mid + 1, right);
    const cross = crossSum(nums, left, right, mid);

    return Math.max(lsum, rsum, cross);
}

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    return __maxSubArray(nums, 0, nums.length - 1);
};
```

时间复杂度是$O(NlogN)$。由于递归调用，所以空间复杂度是$O(logN)$

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
