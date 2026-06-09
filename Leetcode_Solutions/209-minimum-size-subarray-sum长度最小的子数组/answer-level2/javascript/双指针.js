### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} s
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(s, nums) {
    var count = Number.MAX_SAFE_INTEGER
    let begin = 0, i = 0, sum = 0
    while (i < nums.length) {
        if (sum+nums[i] < s) {
            sum += nums[i]
            i++
        } else {
            if (i-begin+1 < count) {
                count = i - begin + 1
            }
            sum -= nums[begin]
            begin++
        }
    }
    return count === Number.MAX_SAFE_INTEGER ? 0 : count
};
```