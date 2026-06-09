> 思路：
> 方法一. 先对最后的几个进行排列，然后将下一个插入到该数组中
> 方法二. 先选出第一个排列，然后将剩下的进行插入

推荐方法二

```javascript
// 方法一
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
  let len = nums.length;
  if (len <= 0) return [];
  let result = [],
      tmp = []
  handler(nums, result, tmp, len - 1);
  return result;
};

/**
 * @param {number[]} nums
 * @param {number[]} result
 * @param {number[]} tmp
 * @param {number} idx
 */
function handler(nums, result, tmp, idx) {
  if (idx < 0) {
    result.push(tmp);
    return;
  }
  for (let i = 0; i <= tmp.length; i++) {
    let t = [...tmp];
    t.splice(i, 0, nums[idx]);
    handler(nums, result, t, idx-1);
  }
}

// 方法二
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
  let result = []
  handler(nums, [], result)
  return result;
}

function handler(nums, tmp, result) {
  if (nums.length === 0) {
    result.push(tmp);
    return;
  }

  for (let i = 0; i < nums.length; i++) {
    let t = [...tmp, nums[i]]
    let numsT = nums.slice(0, i).concat(nums.slice(i + 1))
    handler(numsT, t, result)
  }
}
```