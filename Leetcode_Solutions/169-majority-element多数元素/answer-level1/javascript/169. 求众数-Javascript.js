利用ES6 Map数据结构来解决

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
  if (nums.length === 1) {
    return nums[0]
  }
  let len = nums.length;
  const map = new Map();
  for (let i = 0; i < nums.length; i++) {
    if (map.has(nums[i])) {
      const temp = map.get(nums[i]) + 1;
      map.set(nums[i], temp);
      if (temp > len / 2) {
        return nums[i];
      }
    } else {
      map.set(nums[i], 1);
    }
  }
};
```
