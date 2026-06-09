### 解题思路
加了个排序，解题错误@-@
对于其说明，返回数值是整数，但答案是数组，不是很明白？？？

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    // nums.sort()
    let i=0
    for(let j=1; j<nums.length; j++){
        if(nums[i]!=nums[j]){                
            i++
            nums[i]=nums[j]                  
        }
    }
    return i+1
};
```