### 解题思路
最简单的办法就是从后往前遍历，遇到重复的就删除，因为正序遍历会在循环时改变原数组长度

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    for(let i=nums.length-1; i>0; i--) {
        if(nums[i] === nums[i-1]) {
            nums.splice(i, 1)
        }
    }
    return nums.length;
};
```