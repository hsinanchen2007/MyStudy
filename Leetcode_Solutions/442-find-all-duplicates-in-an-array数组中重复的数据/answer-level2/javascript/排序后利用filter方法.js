```javascript
var findDuplicates = function(nums) {
    nums.sort();
    return nums.filter((value, i) => value == nums[i+1] && value != nums[i+2] && value != nums[i-1] );
};
```

暴力解法！！！