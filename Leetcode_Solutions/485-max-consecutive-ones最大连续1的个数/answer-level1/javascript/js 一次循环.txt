### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    var max = 0, curMax = 0;
    for(var i=0; i<nums.length; i++) {
        if(nums[i] === 1) {
            curMax++;
        } else {
            max = Math.max(max, curMax);
            curMax = 0;
        }
    }
    return Math.max(max, curMax);
};
```