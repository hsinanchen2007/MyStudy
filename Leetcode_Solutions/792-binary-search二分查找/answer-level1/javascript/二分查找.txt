```js
var search = function(nums, target) {
    let left = 0;
    let right = nums.length - 1;
    while(left <= right) {
        let middle = parseInt((left + right) / 2);
        if (target === nums[middle]) {
            return middle;
        } else if (target < nums[middle]) {
            right = middle - 1;
        } else if (target > nums[middle]) {
            left = middle + 1;
        }
    }
    return -1;
};
```

