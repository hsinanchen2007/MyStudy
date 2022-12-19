### 解题思路
遍历到第k个数的时候，如果前k-1个数之和为负数，则丢弃前k-1个数之和。遍历过程中保存最大和。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  let sum = nums[0];
  let ans = sum;
  for(let i=1;i<nums.length;i++){
    if(sum<0)
      sum=nums[i];
    else
      sum+=nums[i]
    ans = Math.max(ans,sum)
  }
  return ans;
};
```