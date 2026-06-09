// 看到题目，首先直接放弃了暴力法，因为时间复杂度是O(n^2)。

// ```js
//solution 1: use arr.findIndex function
var twoSum = function(nums, target) {
    for (var i = 0; i < nums.length; i++) {
        var ret = [];
        var rest = target  - nums[i];
        var _index = nums.findIndex(isEquals, rest)
        if(_index < 0) {
            continue
        }else if(_index != i && _index > 0){
            ret.push(i, _index)
            return ret;
        }
    }
};
// ```
// 但是这样执行时间为5912ms,我的天，这写的简直一坨💩

// 看了题解之后想起来ES6的Map，也就是哈希表

// ```js
//solution 2: use Map function
var twoSum = function (nums, target) {
    let map = new Map()
    for(let i in nums) {
        map.set(nums[i], i)
    }

    for (let j = 0; j < nums.length; j++) {
        if(map.has(target - nums[j]) && map.get(target - nums[j]) != j) {
            return [j, map.get(target - nums[j])]
        }
    }
}
// ```
// 这样执行时间就降到了104ms,内存消耗为37.2MB。
// 但是上面的代码有些冗余，进一步修改下

// ```js
var twoSum = function (nums, target) {
    let map = new Map()
    for(let i in nums) {
        map.set(nums[i], i)
    }

    for (let j = 0; j < nums.length; j++) {
        let rest = target - nums[j]
        if(map.has(rest) && map.get(rest) != j) {
            return [j, map.get(rest)]
        }
    }
}
// ```
// 这样执行时间为64ms,内存消耗略有降低。

