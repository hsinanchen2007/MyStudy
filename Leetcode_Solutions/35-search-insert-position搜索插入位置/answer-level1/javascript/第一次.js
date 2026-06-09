### 解题思路
从头和尾部一起比对，减少循环次数
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let len = nums.length
    for(var i=0;i< len;i++){
        if(nums[i]>=target){
            return i
        }else if(nums[len-1-i]<target){
            return len-i
        }
    }
    return len
};
```