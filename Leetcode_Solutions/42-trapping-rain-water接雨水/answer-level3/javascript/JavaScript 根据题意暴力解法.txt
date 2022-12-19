### 解题思路
每个柱子能够容纳的水等于这个柱子左边最高的柱子和右边最高的柱子中较小的那个减去当前柱子高度

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    // 每个柱子能够容纳的水等于这个柱子左边最高的柱子和右边最高的柱子中较小的那个减去当前柱子高度
    const len = height.length
    let res = 0
    for (let i = 1; i < len - 1; i ++) {
        // 当前柱子i左侧最高柱子高度以及右侧最高柱子高度
        let left = 0, right = 0
        for (let j = i; j >= 0; j --) {
            left = Math.max(left, height[j])
        }
        for (let j = i; j < len; j ++) {
            right = Math.max(right, height[j])
        }
        res += Math.min(left, right) - height[i]
    }
    return res
};
```