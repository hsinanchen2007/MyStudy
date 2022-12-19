#### 思路一：O(n^2)
1. 遍历`heights`；
2. 取出每一个高度的左右边界；
3. 计算面积，取最大值。
#### 代码
```
var largestRectangleArea = function(heights) {
    // 判断特殊情况
    if (heights.length === 0) return 0;
    if (heights.length === 1) return heights[0];
    let area = 0;
    for (let i = 0; i < heights.length; i++) {
        // 左边界起始点
        let left = i - 1;
        // 右边界起始点
        let right = i + 1;
        // 判断左边界
        while (left >= 0 && heights[left] >= heights[i]) left--;
        // 判断右边界
        while (right < heights.length && heights[right] >= heights[i]) right++;
        area = Math.max(area, (right - left - 1) * heights[i]);
    }
    return area;
};
```
#### 思路二（栈）：O(n)
1. 遍历`heights`；
2. 将当前高度`current`和栈顶高度`top`比较；
3. 如果`top` < `current`，说明`top`的右边界还没找到，把`current`入栈；
4. 如果`top` >= `current`，说明`top`的右边界找到了，因为整个栈是按从小到大入栈，当前高度的左边界就是它的上一个位置；
5. 计算`top`的面积，然后把`top`出栈，继续第二步开始判断；
6. 遍历完`heights`，如果栈为空了，说明所有情况都计算完了；
7. 如果不为空，类似：`stack = [1,2,3,4,5]`这种情况，从后往前计算每一个高度的面积，右边界为`stack.length - 1`，左边界是它上一个位置。
#### 代码
```
var largestRectangleArea = function(heights) {
    // 判断特殊情况
    if (heights.length === 0) return 0;
    if (heights.length === 1) return heights[0];
    let area = 0;
    // stack维护高度所在的位置，初始入栈-1和0位置，遍历从1开始
    let stack = [-1, 0];
    for (let i = 1; i < heights.length; i++) {
        // 栈顶的高度
        let lastHeight = heights[_peek(stack, 1)];
        if (heights[i] < lastHeight) {
            // 直到栈为空或栈顶高度小于当前高度，退出循环
            while (_peek(stack, 1) !== -1 && heights[_peek(stack, 1)] >= heights[i]) {
                // 栈顶高度
                let height = heights[_peek(stack, 1)];
                // 计算当前栈顶高度构成的面积
                area = Math.max(area, (i - _peek(stack, 2) - 1) * height);
                // 计算完后出栈
                stack.pop();
            }
        }
        stack.push(i);
    }
    for (let i = stack.length - 1; i > 0; i--) {
        let height = heights[stack[i]];
        let rightIndex = stack[stack.length - 1];
        let leftIndex = stack[i - 1];
        area = Math.max(area, (rightIndex - leftIndex) * height);
    }
    return area;

    // 工具方法，返回栈顶的第top个元素
    function _peek(stack, top) {
        return stack[stack.length - top];
    }
};
```
