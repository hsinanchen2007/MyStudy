/**
 * @param {number[]} nums
 * @return {number}
 */

倒叙遍历数组，

```

var removeDuplicates = function(nums) {
    if (nums.length === 0) {
        return 0;
    }
    if (nums.length === 1) {
        return 1;
    }

    nums.reduceRight((pre, cur, index) => {
        if (pre === cur) {
            nums.splice(index, 1);
        }
        return cur;
    }, NaN);
    return nums.length;
};
```
