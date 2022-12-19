### 解题思路
for循环，不断相加对比留下最大值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    let arr = nums[0]
    for (let i = 0; i < nums.length; i++) {
        let sum = nums[i]
        arr = arr > nums[i] ? arr: nums[i]
        for (let j = i + 1; j < nums.length; j++) {
            sum += nums[j]
            if (arr < sum) {
                arr = sum
            }
        }
    }
    return arr
};
```