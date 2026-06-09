### 代码
>#### 时间复杂度：O(n)  空间复杂度：O(1)
```javascript
var maxArea = function(height) {
    let low = 0
    let high = height.length - 1
    let res = 0
    while (low < high) {
        let sum = (high - low) * Math.min(height[low], height[high])
        res = Math.max(res, sum)
        if (height[low] < height[high]) {
            low++
        } else {
            high--
        }
    }
    return res
};
```
