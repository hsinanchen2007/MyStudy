### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    if(height.length < 2){
        return 0;
    }
    let maxArea = 0;
    for(let i=0;i<height.length;i++){
        for(let j=i+1;j<height.length;j++){
            let areaHeight = height[i] > height[j] ? height[j] : height[i];
            let areaWidth = j-i;
            let curArea = areaHeight * areaWidth;
            maxArea = maxArea > curArea ? maxArea : curArea;
        }
    }
    return maxArea;
};
```