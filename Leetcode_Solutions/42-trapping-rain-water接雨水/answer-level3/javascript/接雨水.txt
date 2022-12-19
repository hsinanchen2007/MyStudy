思路：
两边必须比中间高才能储水，所以遍历数组，将中间的低洼处出栈，计算低洼处的雨水量，遍历结束时，保证栈单调递减，就完成了储水量计算。

建立一个单调栈，用于存储数组height的index。
遍历数组，进行出入栈操作。

入栈与出栈规则大致分为两种情况：
1.栈为空 或者 小于栈底元素（即相对的高点）
——1.1 栈为空时，入栈遍历的数组元素
——1.2 遍历的元素height 小于 栈底元素时
————1.2.1 遍历的元素height 大于 前一个元素时，出栈，计算雨水量（满足了中间低，两边高的低洼条件）
————1.2.1 遍历的元素height 小于 前一个元素时，入栈（栈仍单调递减，不满足低洼条件）
2.大于栈底元素
——2.1 出栈，计算雨水量

关键点：雨水量的计算方法，使用与X轴平行的切面来计算。
雨水量的计算公式：（左右两边相对较小的height元素 - 出栈元素）* （当前遍历index - 新的栈顶元素的index - 1）


```
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let stack = [];
    let trap = 0;
    for (let i = 0; i < height.length; i++) {
        if (stack.length === 0 || height[i] < height[stack[0]]) {
            if (height[i] < height[i-1]) {
                stack.push(i);
            } else {
                while (height[i] >= height[stack[stack.length-1]]) {
                    let stackOldTop = stack.pop();
                    let stackNewTop = stack[stack.length-1];
                    if (height[i] < height[stackNewTop]) {
                        trap = trap + (height[i] - height[stackOldTop]) * (i - stackNewTop -1);
                    } else {
                        trap = trap + (height[stackNewTop] - height[stackOldTop]) * (i - stackNewTop -1);
                    };
                };
                stack.push(i);
            };
        } else {
            while (stack.length !== 0) {
                let stackTop1 = stack.pop();
                let stackTop2 = stack[stack.length-1];
                if (stack.length ===0) break;
                trap = trap + (height[stackTop2] - height[stackTop1]) * (i - stackTop2 -1);
            };
            stack.push(i);
        };
    };
    return trap;
};
```

