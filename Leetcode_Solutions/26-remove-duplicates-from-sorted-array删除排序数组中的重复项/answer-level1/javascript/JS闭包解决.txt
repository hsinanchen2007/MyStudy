### 解题思路
使用js中闭包 和 数组的splice方法, 没有额外开辟空间

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    return (function () {
        for(let i = 0; i < nums.length; i++) {
          if(nums[i] === nums[i+1]) {
            // 当前元素和下一位元素相等时，移除当前元素
            nums.splice(i, 1);
            // 移除元素后数组长度减小，索引改变，让 i 减 1
            i--;
          }
        }
        return nums.length;
    })()
};
```