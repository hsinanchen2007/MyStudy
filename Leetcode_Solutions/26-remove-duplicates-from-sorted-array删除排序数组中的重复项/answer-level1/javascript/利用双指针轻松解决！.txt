```
var removeDuplicates = function (nums) {
    let p = 0, q = 1;
    while (q < nums.length) {
        if (nums[p] === nums[q]) {
            q++
        } else {
            nums[p + 1] = nums[q]
            p++;
            q++;
        }
    }
    return ++p
};
```
