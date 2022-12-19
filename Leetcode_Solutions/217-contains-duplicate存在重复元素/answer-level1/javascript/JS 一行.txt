var containsDuplicate = function(nums) {
    return !nums.every(x=>nums.indexOf(x)==nums.lastIndexOf(x))
};

var containsDuplicate = function(nums) {
    let map = new Map()
    return nums.some(item => map.has(item) ? true : !map.set(item))
};