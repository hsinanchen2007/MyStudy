### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var len = height.length;
    var l = 0;
    var r = len - 1;
    var maxArea = 0;

    while(l < r) {
        var left = height[l];
        var right = height[r];
        maxArea = Math.max(maxArea, Math.min(left, right) * (r - l));
        if (height[l] < height[r]) {
            l++;
        } else {
            r--
        }
    }

    return maxArea;
};
```