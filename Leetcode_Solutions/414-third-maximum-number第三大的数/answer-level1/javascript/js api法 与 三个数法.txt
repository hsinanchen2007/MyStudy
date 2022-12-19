### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
    nums = [...new Set(nums)].sort((a, b) => a - b);
    return nums[2] ? nums[nums.length - 3] : nums[nums.length - 1];
};

var thirdMax = function(nums) {
    var first = -Infinity, second = -Infinity, third = -Infinity;

    for(var i=0; i<nums.length; i++) {
        var cur = nums[i];
        if(cur == first || cur == second || third == cur) continue;
        if(cur > first) {
            // 大于最大数
            third = second;
            second = first;
            first = cur;
        } else if(cur > second) {
            third = second;
            second = cur;
        } else if(cur > third) {
            third = cur
        }
    }
    return third > -Infinity ? third : first;
}

```