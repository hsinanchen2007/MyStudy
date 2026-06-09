### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    const index = nums.findIndex(val=>val === target)
    if(index !== -1){
        return index
    }else{
        const insertIndex = nums.findIndex(val=>val>target)
        if(insertIndex !== -1){
            return insertIndex
        }else{
            return nums.length
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/2778ecd9f8ea483f2d04e48c21cdd61661f98e83e687542ea51c9006e9616a6a-image.png)
