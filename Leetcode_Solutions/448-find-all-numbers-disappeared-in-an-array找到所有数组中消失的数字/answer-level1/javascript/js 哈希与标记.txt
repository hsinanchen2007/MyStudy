### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    var map = {};
    for(var i=0; i<nums.length; i++) {
        map[nums[i]] = true;
    }

    var res = [];
    for(var j=0; j<nums.length; j++) {
        if(!map[j+1]) res.push(j+1)
    }
    return res;
};

var findDisappearedNumbers = function(nums) {
    for(var i=0; i<nums.length; i++) {
        var index = Math.abs(nums[i]) - 1;
        if(nums[index] > 0) {
            // 将已存在的数的index 标记为负
            nums[index] *= -1; 
        }
    }

    var res = [];
    for(var j=0; j<nums.length; j++) {
        if(nums[j] > 0) res.push(j+1)
    }
    return res;
}
```