### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var p = 0;
    var q = 1;

    while(q <= nums.length) {
        if (nums[p] !== nums[q]) {
            nums[p + 1] = nums[q];
            p++
        } else {
            q++;
        }
    }

    return p;
};
```