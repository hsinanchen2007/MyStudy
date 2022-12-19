### 解题思路
考虑非法输入的情况，数组为空之所以不返回为 0，是为了和最大子序和为 0 的情况作区分。不得不说 LeetCode 的执行用时真的是非常玄学。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    if (!Array.isArray(nums)) {
        console.log('非法输入');
    }
    if (!nums.length) {
        console.log('数组为空')
    }
    let maxSum = nums[0];
    for (let i = 1; i < nums.length; i++) {
        if (nums[i - 1] > 0) {
            nums[i] += nums[i - 1];
        }
        maxSum = Math.max(maxSum, nums[i]);
    }
    return maxSum
};
```

![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/f3fbaea625e0cc53b1ba93ef7bb1e9c5d581a336d6c8026f7f04562a9d2cb0df-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
