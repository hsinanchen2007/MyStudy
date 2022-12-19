### 解题思路
判断nums[i]是否等于nums[i-1],若是则删除即可。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    for(let i = 0;i < nums.length;i ++) {
        while(i > 0 && nums[i] === nums[i - 1]){ // 去重
            nums.splice(i,1);
        }
    }
    return nums.length;
};
```