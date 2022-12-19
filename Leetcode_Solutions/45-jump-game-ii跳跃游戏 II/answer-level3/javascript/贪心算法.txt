```javascript []
var jump = function (nums) {
    let count = 0
    for (let index = 0; index < nums.length - 1; count++) {
        index = findMax(nums[index], nums, index + 1)
    }
    return count
};
const findMax = function (size, nums, from) {
    let maxIndex = from;
    let maxValue = 1;
    for (let index = from; index < from + size && index < nums.length; index++) {
        if (index == nums.length - 1) {
            return index
        }
        if (nums[index] + index > maxValue) {
            maxIndex = index
            maxValue = nums[index] + index
        }
    }
    return maxIndex
}
```

