```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
  let len = nums.length;
  if (len < 4) return [];
  nums = nums.sort((a, b) => a - b);
  let result = [];
  for (let a = 0; a < len - 3;) {
    for (let b = a + 1; b < len - 2;) {
      for (let c = b + 1, d = len - 1; c < d;) {
        let t = nums[a] + nums[b] + nums[c] + nums[d];
        if (t === target) {
          result.push([nums[a], nums[b], nums[c], nums[d]])
          do {
            c++;
          } while(c < d && nums[c] === nums[c - 1]);
          do {
            d--;
          } while(c < d && nums[d] === nums[d + 1])
        } else if (t > target) {
          d--;
        } else {
          c++;
        }
      }
      do {
        b++;
      } while(b < len - 2 && nums[b] === nums[b - 1])
    }
    do {
      a++;
    } while(a < len - 3 && nums[a] === nums[a - 1])
  }
  return result;
};
```