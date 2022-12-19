```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var len = nums.length;
    var obj = {};
    for(let i = 1;i < len;i ++){
        obj[nums[i]] = i;
    }
    for(let i = 0;i < len;i ++){
        var a = target - nums[i];
        if(obj[a] && i !== obj[a]){
            return [i, obj[a]];
        }
    }
    return false;
};
```