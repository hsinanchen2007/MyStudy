### 解题思路
双指针 找出最高点 两边向内收缩
### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let max = Math.max(...height)
    let i = height.indexOf(max)
    let left = 0
    let right = height.length - 1
    let ans = 0
    let curLeftMax = 0
    let curRightMax = 0
    while(left < right){

        // 左边收缩
        if(height[left] > curLeftMax) curLeftMax = height[left]
        else ans += curLeftMax - height[left]
        if(left < i) left ++
        // 右边收缩
        if(height[right] > curRightMax) curRightMax = height[right]
        else ans += curRightMax - height[right]
        if(right > i) right --
    }
    return ans
};
```