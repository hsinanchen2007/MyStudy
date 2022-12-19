### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    if(nums.length === 1) {
        return 0
    }
    let maxDis = 0
    let count = 0
    // end比较难理解
    let end = 0 // end为边界 到end步数再+1
    for(let i = 0;  i < nums.length; i++) {
        maxDis = Math.max(nums[i] + i, maxDis)
        // 当前位置能够到的最大值超过了length，则步数+1即可
        if (maxDis >= nums.length - 1) {
            return count+1
        }
        if(i === end) {
            count++
            end = maxDis
        }
    }
    return count
};
```