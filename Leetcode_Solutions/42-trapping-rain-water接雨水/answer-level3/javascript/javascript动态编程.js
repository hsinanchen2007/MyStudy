
找到数组中从下标 i 到最左端最高的条形块高度 \text{left\_max}left_max。
找到数组中从下标 i 到最右端最高的条形块高度 \text{right\_max}right_max。
扫描数组 \text{height}height 并更新答案：
累加 \min(\text{max\_left}[i],\text{max\_right}[i]) - \text{height}[i]min(max_left[i],max_right[i])−height[i] 到 ansans 上
 
### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    const len = height.length;
    if (len < 3) {
        return 0;
    } 

    const left_arr = new Array(len);
    const right_arr = new Array(len);
    let res = 0;
    left_arr[0] = height[0];
    right_arr[len - 1] = height[len - 1];
    for (let i = 1; i < len; i++) {
        left_arr[i] = Math.max(left_arr[i - 1], height[i]);
    }
    for (let i = len - 2; i >= 0; i--) {
        right_arr[i] = Math.max(right_arr[i + 1], height[i]);
    }
    for (let i = 0; i < len; i++) {
        res += Math.min(left_arr[i], right_arr[i]) - height[i];
    }
    return res;
};
```