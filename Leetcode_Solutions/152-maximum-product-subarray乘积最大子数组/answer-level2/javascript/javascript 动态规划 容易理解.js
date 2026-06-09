解题思路：动态规划
- 因为之前做过类似的题目[#53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
- 所以一开始就想到了一样的思路，动态规划，且DP方程是: nums[i] = Math.max(nums[i], nums[i] * nums[i-1])
- 因为有负数的存在，所以我们需要同时记录当前i处的子序列乘积的最大值与最小值，当出现负数时，最大值最小值互换
- 最终的最大值即为结果

```javascript
/**
 * 152. Maximum Product Subarray
 * https://leetcode.com/problems/maximum-product-subarray/
 * @param {number[]} nums
 * @return {number}
 */
const maxProduct = (nums) => {
  if (nums.length <= 1) return nums[0]
  let iMax = nums[0], iMin = nums[0], max = nums[0]
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] < 0) [iMax, iMin] = [iMin, iMax]
    iMax = Math.max(nums[i], nums[i] * iMax)
    iMin = Math.min(nums[i], nums[i] * iMin)
    max = Math.max(iMax, max)
  }
  return max
}
```