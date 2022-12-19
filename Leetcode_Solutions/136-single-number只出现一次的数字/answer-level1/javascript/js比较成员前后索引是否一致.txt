var singleNumber = function(nums) {
    for (let i = 0; i < nums.length; i++) {
        if (nums.lastIndexOf(nums[i]) === nums.indexOf(nums[i])) return nums[i];
    }
};