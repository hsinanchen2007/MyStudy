执行用时 :
88 ms
, 在所有 JavaScript 提交中击败了
80.68%
的用户
内存消耗 :
34.8 MB
, 在所有 JavaScript 提交中击败了
13.90%
的用户

var searchInsert = function(nums, target) {
    var result = nums.indexOf(target);
    if(result >= 0) {
        return result;
    } else {
        var test = 0;
        for(let i = 0; i< nums.length; i++) {
            if(nums[i] < target) {
                test ++;
            } if(nums[i] > target) {
                break;
            };
        }
            return test;
    }
};

