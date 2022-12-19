### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let j = 0;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    while(j < nums.length){
        nums[j++] = 0;
    }
};
```