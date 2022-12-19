### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let j = -1;
    let i = 0;
    let count = 0;
    for(; i<nums.length; i++){
        if(nums[i] !== nums[j]){
            ++j
            nums[j] = nums[i]
            count++
        }
    }
    return count
};
```