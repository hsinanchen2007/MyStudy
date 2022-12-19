### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
  let area = 0;
  for (let i = 0, j = height.length - 1; i < j; ) {
    area = Math.max(area, (j - i) * (height[i] < height[j] ? height[i++] : height[j--]));
  }
  return area;
}
```