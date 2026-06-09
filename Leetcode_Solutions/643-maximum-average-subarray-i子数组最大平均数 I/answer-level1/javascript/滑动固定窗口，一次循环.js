### 解题思路
维护长度为k的窗口，保存最大值即可

### 代码

```javascript
var findMaxAverage = function(nums, k) {
    // 维护一个长度为k的滑动窗口即可
    let left = 0, right = 1, n = nums.length, sum = nums[0];

    while (right < n) {
        if (right < k) {
            sum += nums[right];
            max = sum;
            // 长度刚好到达直接返回
            if (++right == n) return sum / k;
            continue;
        }
        // 滑动窗口开始移动
        sum -= nums[left];
        sum += nums[right];

        if (sum > max) {
            max = sum;
        }
        right++;
        left++;
    }
    return max / k;
};
```