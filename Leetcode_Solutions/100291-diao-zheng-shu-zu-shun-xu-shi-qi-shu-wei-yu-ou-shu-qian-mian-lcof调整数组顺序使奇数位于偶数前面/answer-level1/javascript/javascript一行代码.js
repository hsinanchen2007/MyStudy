var exchange = function(nums) {
    return [...nums.filter(val=>val%2==1), ...nums.filter(val=>val%2==0)]
};