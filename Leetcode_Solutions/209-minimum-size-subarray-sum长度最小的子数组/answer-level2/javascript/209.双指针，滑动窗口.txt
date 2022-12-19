> 子数组相当于一个可变大小的窗口，遍历数组，滑动窗口，即可求解


![1.jpg](https://pic.leetcode-cn.com/31fcc38eeeb41d57161563629b6fc6e05589a23261955c97148c30c631717be8-1.jpg)


### 代码

```
/**
 * @param {number} s
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(s, nums) {
    const int_max = Number.MAX_SAFE_INTEGER
    var i = 0, sum = 0, ans = int_max
    for (var j = 0; j < nums.length; j++) {
        sum += nums[j]
        while (sum >= s) {
            ans = Math.min(ans, j - i + 1)
            sum -= nums[i++]
        }
    }
    return ans === int_max ? 0 : ans
};
```

### 算法复杂度

+   时间复杂度：O(n),每个指针移动都需要O(n) 的时间,每个元素最多被访问2次
+   空间复杂度：O(1)