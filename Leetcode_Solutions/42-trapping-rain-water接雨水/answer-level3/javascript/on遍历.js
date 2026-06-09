### 解题思路

 * 找出最大值maxIndex
 * 遍历左侧到max, 维护当前数字，向右侧补全。同样遍历右侧
 * 每格都向中间填满
 * 
### 代码

```javascript
/**
 * 找出最大值maxIndex
 * 遍历左侧到max, 维护当前数字，向右侧补全。同样遍历右侧
 * 每格都向中间填满
 * 
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let res = 0;
    let maxIndex = 0;
    for(let i = 0; i < height.length; i++) {
        if(height[i] > height[maxIndex]) {
            maxIndex = i;
        }
    }

    let curr = 0;
    //左侧
    for(let i = 0; i < maxIndex; i++) {
        if(height[i] > curr) {
            curr = height[i];
        } else {
            res += curr - height[i];
        }
    }

    //right
    curr = 0;
    for(let i = height.length - 1; i > maxIndex; i--) {
        if(height[i] > curr) {
            curr = height[i];
        } else {
            res += curr - height[i];
        }
    }

    return res;
};
```