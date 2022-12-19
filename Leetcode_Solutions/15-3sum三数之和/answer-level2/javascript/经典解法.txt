### 解题思路
1. 其实就是用最快的方式迭代完全部33组合，此解法先对数组进行排序，有序之后可以用两端逼近法找到合适的组合
![image.png](https://pic.leetcode-cn.com/c21a80068cccbf2044b29ac4bb95d5510bae9c33ae550476fa043f9f0704b273-image.png)
2. 去重是关键
  a. 函数体内第七行，如果当前`nums[i]===nums[i-1]`，则结果可能会重复，应跳过
  b. 函数体内18、19行，如果`sum`为零，下一步元素和当前元素相等，如`nums[left]===nums[left+1]`，则可以跳过
3. 注意sort方法不要写成`nums = nums.sort((a,b) => a > b ? 1 : -1)`，这样性能会比`nums = nums.sort((a,b) => a - b)`差

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let len = nums.length
    if (len < 3) return []
    var nums = nums.sort((a,b) => a - b)
    let result = [], sum, left, right
    for (let i = 0; i < len; i++) {
        if (nums[i] > 0) break
        if (i > 0 && nums[i] === nums[i - 1]) continue // 关键的去重操作
        left = i + 1
        right = len - 1
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right]
            if (sum > 0) {
                right--
            } else if (sum < 0) {
                left++
            } else {
                result.push([nums[i], nums[left], nums[right]])
                while (nums[left] === nums[left + 1] && left < right - 1) left++
                while (nums[right] === nums[right - 1] && left < right - 1) right--
                right--
                left++
            }
        }
    }
    return result
};
```