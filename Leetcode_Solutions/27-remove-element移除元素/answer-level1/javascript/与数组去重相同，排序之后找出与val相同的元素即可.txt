### 解题思路
与数组去重相同，排序之后找出与val相同的元素，使用splice删除。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    nums.sort((a,b) => a - b);
    for(let i = 0;i < nums.length;i ++) {
        while(nums[i] == val) {
            nums.splice(i,1);
        }
    }
    return nums.length;
};
```