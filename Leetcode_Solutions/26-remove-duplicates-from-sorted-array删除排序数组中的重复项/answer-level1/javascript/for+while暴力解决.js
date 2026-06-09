### 解题思路
需要考虑到多个相同值的情况，因此不能使用if而需要while来不断判断，直到排除所有重复值。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    for(let i=0;i<nums.length;i++){
        while(nums[i]===nums[i+1]){
            nums.splice(i+1,1);
        }
    }
    return nums.length;
};
```