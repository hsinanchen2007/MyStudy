### 解题思路
此处撰写解题思路
删除原数组的过程使得数组长度呈现动态变化，若从前往后遍历，索引值递增后的值无法对应相应的值，如果是从后往前遍历，索引值递减后任然可以对应动态变化的数组中相应位置的值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    for (let i = nums.length; i > 0; i--) {
        if (nums[i] == nums[i - 1]) {
            nums.splice(i,1)
        }
    }
    return nums.length;
};
```