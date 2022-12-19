思路：

先对尾部的进行排序，然后将前一个插入。

比如 [1,2,3,4]，先获取 [4]，插入 3 有两种插入法 [3,4] 和 [4,3]；接着插入2，有三种插入法[2,3,4]、[3，2，4] 和 [3,4,2]……… 依次类推

```javascript
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
```