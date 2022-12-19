### 解题思路
此处撰写解题思路
创建一个空的对象,对nums的值遍历,没有的就存进对象中,有重复出现直接return true.
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    var obj = {};
    for (var i = 0; i < nums.length; i++){
        if(obj[nums[i]]){
            return true;
        } 
        obj[nums[i]] = 1;     
    }
    return false;
};
```