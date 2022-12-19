### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let max = nums[0];
    for(let i = 0;i < nums.length;i ++) {
        let sum = nums[i];
        if(sum > max) {
            max = sum;
        }
        for(let j = i + 1;j < nums.length;j ++) {
            sum = sum + nums[j];
            if(sum > max) {
                max = sum;
            }
        }
    }
    return max;
};
```