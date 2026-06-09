### 解题思路

- 将 ``数组`` 按从小到大的顺序排序
- 累加奇数个的和即为结果

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    let sum = 0
    let i = 0
    let len = nums.length
    // 数组按从小到大排序
    nums.sort((a, b) => a - b)
    // 累加相邻两个数字的最小值
    while (i < len) {
        sum += nums[i]
        i += 2
    }
    return sum
};
```