### 解题思路
动态规划

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
const lengthOfLIS = function(nums) {
  if (nums.length <= 1) return nums.length;
  let arr = [];
  arr.push(nums[0]);
  for (let i=1; i<nums.length; i++) {
    if (nums[i] > arr[arr.length - 1]) arr.push(nums[i]);
    if (nums[i] <= arr[arr.length - 1]) {
      for (let j=arr.length - 1; j>=0; j--) {
        if (arr[j] < nums[i]) {
          arr[j+1] = nums[i];
          break;
        }
        if (j==0) arr[j] = nums[i];
      }
    }
  }
  return arr.length;
};
```