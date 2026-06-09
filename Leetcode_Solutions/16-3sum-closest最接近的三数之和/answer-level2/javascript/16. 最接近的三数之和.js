### 解题思路

这道题跟 [三数之和](https://leetcode-cn.com/problems/3sum/) 的思路大体是一样的：

固定一个数，剩下两个数就变成了 ``双指针`` 的常规解法。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    let N = nums.length
    let res = Number.MAX_SAFE_INTEGER
    nums.sort((a, b) => a - b)
    for (let i = 0; i < N; i++) {
        let left = i + 1
        let right = N - 1
        while (left < right) {
            let sum = nums[i] + nums[left] + nums[right]
            if (Math.abs(sum - target) < Math.abs(res - target)) {
                res = sum
            }
            if (sum < target) {
                left++
            } else if (sum > target) {
                right--
            } else {
                return sum
            }
        }
    }
    return res
};
```