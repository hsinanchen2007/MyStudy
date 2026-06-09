### 解题思路
遍历，如果比当前值大，即更新最大值

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    const length = height.length;
    let curIndex = length - 1;
    let curMaxArea = 0;
    for(let i = 0; i < length - 1; i += 1){
        for(let j = i + 1; j < length; j += 1){
            const curArea = (j - i) * Math.min(height[i], height[j]);
            curMaxArea = curArea > curMaxArea ? curArea : curMaxArea;
        }
    }
    return curMaxArea;
};
```