### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function(nums) {

    nums.sort((a, b) => b - a)

    for (let i = 1; i < nums.length - 1; i += 2) {
        let temp = nums[i]
        nums[i] = nums[i + 1]
        nums[i + 1] = temp
    }
    
};
```