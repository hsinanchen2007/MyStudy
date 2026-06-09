### 解题思路
此处撰写解题思路
从后往前。 如果 i=== i-1 ;则  Array.splice(i,1); 对 Array 原数组也会有删减的操作
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
for(var i = nums.length-1; i>0;){
    if(nums[i] === nums[i-1]){
        nums.splice(i,1);
        i--;
    } else {
        i--;
    }
    
}
return nums.length;
};
```