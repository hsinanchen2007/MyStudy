
# 思路
将数组按大小重新排列， 因为多数大于1/2，所以取中间值就可以了

```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */

var majorityElement = function(nums) {
  return  nums.sort()[parseInt(nums.length/2)];
};

