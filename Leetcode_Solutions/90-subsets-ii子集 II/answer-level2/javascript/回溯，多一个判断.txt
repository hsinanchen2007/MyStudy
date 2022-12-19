> 大体思路依然为回溯法，只不过需要加一个判断，如果该数字曾被使用过，则下次跳过该数字

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
  nums = nums.sort((a, b) => a - b);
  let result = [];
  handler(nums, result, [], 0);
  return result;
};

function handler(nums, result, tmp, curr) {
  result.push(tmp);

  let prev = undefined;
  for (let i = curr; i < nums.length; i++) {
    if (prev === nums[i]) continue;
    else prev = nums[i];

    let t = [...tmp];
    t.push(nums[i]);
    handler(nums, result, t, i + 1)
  }
}
```