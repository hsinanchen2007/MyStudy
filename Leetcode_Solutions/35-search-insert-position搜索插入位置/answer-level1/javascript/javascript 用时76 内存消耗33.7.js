var searchInsert = function(nums, target) {
    if (nums.includes(target)) {
        return nums.indexOf(target)
    }
    for(let i = 0, len = nums.length; i < len; i++) {
        if (nums[i] > target) {
            nums.splice(i, -1, target)
            return i
        }
        if (nums[len-1] < target) {
            nums.push(target)
            return len
        }
    }
};