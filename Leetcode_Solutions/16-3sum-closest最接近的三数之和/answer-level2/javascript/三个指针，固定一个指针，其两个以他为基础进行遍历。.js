```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
  let len = nums.length;
  if (len <= 2) return [];
  nums = nums.sort((a, b) => a - b);
  let min = nums[0] + nums[1] + nums[2];
  for (let x = 0; x < len - 2;) {
    for (let y = x + 1, z = len - 1; y < z;) {
      let t = nums[x] + nums[y] + nums[z];
      if (Math.abs(t - target) < Math.abs(min - target)) {
        min = t;
      }
      if (t < target) {
        do {
          y++;
        } while(y < z && nums[y] === nums[y - 1])
      } else if (t > target) {
        do {
          z--;
        } while(y < z && nums[z] === nums[z + 1])
      } else {
        return min;
      }
    }
    do {
      x++;
    } while (x < len - 2 && nums[x] === nums[x - 1])
  }
  return min;
};
```