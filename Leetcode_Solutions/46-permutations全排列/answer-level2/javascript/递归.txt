```
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let ret = [];
    const combine = (item, arr) => {
        if (arr.length === 0) {
            ret.push(item);
            return;
        }
        if (arr.length === 1) {
            ret.push(item.concat(arr[0]));
            return;
        }
        for (let i = 0; i < arr.length; i++) {
            combine(item.concat(arr[i]), arr.slice(0, i).concat(arr.slice(i + 1)));
        }
    }
    for (let i = 0; i < nums.length; i++) {
        combine([nums[i]], nums.slice(0, i).concat(nums.slice(i + 1)));
    }
    return ret;
};
```