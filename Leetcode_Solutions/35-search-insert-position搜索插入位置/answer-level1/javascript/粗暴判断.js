
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    for(let j = 0; j<nums.length; j++) {
        if(nums[j]>=target) {
            return j;
        } else if(nums.length === j+1) {
            return nums.length;
        }
    }
};
```