没什么好说的
```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    nums.sort((a, b) => a - b);
    const res = [];
    function backTrace(path, i) {
        res.push(path);
        for(let j = i; j < nums.length; j++) {
            if (j > i && nums[j] === nums[j - 1]) continue;
            backTrace(path.concat([nums[j]]), j + 1);
        }
    }
    backTrace([], 0);
    return res;
};
```
