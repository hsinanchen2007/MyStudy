### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    // 贪心
    let result = 0;
    let maxResult = -Infinity;
    for (let i=0; i< nums.length; i++) {
        let num = nums[i];
        result += num;
        if (result < num) {
            result = num;
        }
        maxResult = Math.max(maxResult, result);
    }
    return maxResult;
};
```