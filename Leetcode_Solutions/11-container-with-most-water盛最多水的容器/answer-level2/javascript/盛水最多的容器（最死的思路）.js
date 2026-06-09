```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let max = 0;
    // 盛水的多少是由短板决定的， 取最大值(最简单的思想)
    for(let i = 0; i < height.length; i ++) {
        for(let j = i + 1; j < height.length; j ++) {
            if(height[i] <= height[j]) {
                if(height[i] * (j - i) > max) {
                    max = height[i] * (j - i);
                }
            } else {
                if(height[j] * (j - i) > max) {
                    max = height[j] * (j - i);
                }
            }
        }
    }

    return max;
};
```
