**思路：**使用stack数组模拟单调栈，用于存储heights数组的index

步骤1：遍历数组，若stack数组为空或者数组元素的高度大于前一项，则将数组元素的index入栈到stack.

步骤2：若情况相反（即遍历的数组元素的高度小于前一项），则将stack的栈顶元素（即原数组的index）出栈。

步骤3：计算出栈的栈顶元素的最大面积。
最大面积的宽：
左边缘是，新的stack数组的栈顶元素（即上一个比出栈元素的height要低的元素index）。
右边缘是，当前遍历到的数组index。
最大面积的高：就是出栈元素的值。

步骤4：比较每次出栈元素的最大面积。直到stack全部出栈。
因为面积在出栈时计算，所以需要stack全部出栈。
为了让stack全部出栈，需要在原数组heights中加入一个height为0的元素。

```
/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    heights.push(0);
    let stack = [];
    let maxArea = 0;
    for (let i = 0; i < heights.length; i++) {
        if (stack.length === 0 || heights[i] > heights[i-1]) {
            stack.push(i);
        } else {
            let arrIndex = stack.pop();
            while (heights[arrIndex] >= heights[i]) {
                let height = heights[arrIndex];
                let stackTop = stack[stack.length - 1];
                let width = stack.length === 0 ? i : (i - stackTop - 1);
                maxArea = Math.max(maxArea, (height * width));
                if (stack.length === 0) break;
                if (heights[stackTop] < heights[i]) break;
                arrIndex = stack.pop();
            };
            stack.push(i);
        };
    };
    return maxArea;
};
```
