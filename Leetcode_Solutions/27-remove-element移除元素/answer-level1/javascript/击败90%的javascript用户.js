### 解题思路
利用splice合理i++

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    for(let i = 0; i < nums.length;) {
        const cur = nums[i]
        if (cur === val) {
            nums.splice(i, 1);
        } else {
            i++;
        }
    }
    return nums.length;
};
```