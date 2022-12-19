### 贪心算法
有一种痛苦是知道思路是啥，就是编程一直出错。。。
难过ing

### 代码

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    let count = nums[0], maxCount = nums[0]
    for (let i = 1; i < nums.length; i++) {
        count = Math.max(count + nums[i], nums[i])
        maxCount = Math.max(maxCount, count)    
    }
    return maxCount
};
```