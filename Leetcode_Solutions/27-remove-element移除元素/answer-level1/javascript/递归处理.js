### 解题思路
递归比对 单指针 

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let i = 0;
    function remove(nums, val) {
      // 数值相同时删除
      if (nums[i] === val) {
        nums.splice(i, 1)
        // 当最后一个元素为相同数值的元素时 立即返回
        if (i >= nums.length) {
          return nums.length
        }
        // 递归
        remove(nums, val)
        return
      }
      // 数值不同时, i增加
      i++
      // 数组还未递归完, 继续递归
      if (nums.length > i) {
        remove(nums, val)
      } else {
        return nums.length
      }
    }
    remove(nums, val)
};
```