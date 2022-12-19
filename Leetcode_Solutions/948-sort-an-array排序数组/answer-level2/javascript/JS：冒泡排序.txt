### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    for(let i = 0; i < nums.length; i++){
        for(let j = 0; j < nums.length-i-1; j++){
            if(nums[j] > nums[j + 1]){
                [nums[j], nums[j+1]] = [nums[j+1], nums[j]];
            }
        }
    }
    return nums;
};
```