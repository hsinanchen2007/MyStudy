 极简6行搞定
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    const len = nums.length;
    if(!len) return 0;
    let [a, b] = [nums[0], Math.max(nums[0], nums[1])];
    for(let i = 2; i < len; i++)
        [a, b] = [b, Math.max(b, a + nums[i])];
    return b || a;
};
```
