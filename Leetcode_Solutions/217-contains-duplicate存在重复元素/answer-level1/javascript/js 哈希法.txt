```
var containsDuplicate = function(nums) {
    var obj = {}; // 存储元素出现次数
    for(var i=0; i<nums.length; i++) {
        if(!obj[nums[i]]) {
            obj[nums[i]] = 1;
        } else {
            return true;
        }
    }
    return false;
};
```
