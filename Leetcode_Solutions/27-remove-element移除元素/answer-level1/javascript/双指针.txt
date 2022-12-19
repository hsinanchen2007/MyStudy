### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    var p = 0;
    var q = 0;

    while(q < nums.length) {
        if (nums[q] !== val) {
            nums[p] = nums[q];            
            p++;
        }
        q++;
    }

    return p;
};
```