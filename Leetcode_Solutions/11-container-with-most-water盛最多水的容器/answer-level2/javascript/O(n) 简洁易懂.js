```
var maxArea = function(height) {
    let l = 0,
        r = height.length - 1,
        max = 0

    while (l < r) {
        
        // 获取较小高度的柱子并且移动
        const minHeight = height[l] < height[r]? height[l++]: height[r--]
        
        // 柱子已发生移动，所以 x 轴需要加 1
        max = Math.max(max, (r - l + 1) * minHeight)
    }
    return max
};
```
