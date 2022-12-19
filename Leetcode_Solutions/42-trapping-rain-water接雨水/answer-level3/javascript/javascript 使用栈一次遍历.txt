### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
// 我们在遍历数组时维护一个栈。如果当前的条形块小于或等于栈顶的条形块，我们将条形块的索引入栈，意思是当前的条形块被栈中的前一个条形块界定。如果我们发现一个条形块长于栈顶，我们可以确定栈顶的条形块被当前条形块和栈的前一个条形块界定，因此我们可以弹出栈顶元素并且累加答案到ans。
var trap = function(height) {
    const len = height.length
    const stack = [];
    let ans = 0, current = 0;
    while (current < height.length) {
        while (stack.length && height[current] > height[stack[stack.length - 1]]) {
            const top = stack.pop();
            if (!stack.length)
                break;
            const distance = current - stack[stack.length - 1] - 1;
            const bounded_height = Math.min(height[current], height[stack[stack.length - 1]]) - height[top];
            ans += distance * bounded_height;
        }
        stack.push(current++);
    }
    return ans;
};
```