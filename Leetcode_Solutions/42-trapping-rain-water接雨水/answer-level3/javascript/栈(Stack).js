### 解题思路
##### 创建一个栈(stack)，元素单调不增
##### 遍历数组元素height[i]
- 小于栈顶的元素height[i]，将索引i存入栈中
- 大于栈顶的元素height[i]与栈顶前两个元素对应数组元素形成‘凹’形，必能盛雨，计算雨量大小
- 等于栈顶元素的height[i]，更新栈顶元素为数组元素索引i
- 以上维护了栈的单调性

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
  let sum = 0;
  let stack = [0];
  for (let i = 1; i < height.length; i++) {
    if (height[i] < height[stack[0]]) {
      stack.unshift(i);
    } else if (stack.length > 1 && height[i] > height[stack[0]]) {
      while (stack.length > 1 && height[i] > height[stack[0]]) {
        sum += (Math.min(height[i], height[stack[1]]) - height[stack[0]]) * (i - stack[1] - 1);
        stack.shift();
      }
      if (stack.length === 1 && height[i] >= height[stack[0]]) {
        stack = [i];
      } else {
        stack.unshift(i);
      }
    } else if (stack.length === 1 && height[i] > height[stack[0]]) {
      stack = [i];
    } else if (height[i] === height[stack[0]]) {
      stack[0] = i;
    }
  }
  return sum;
};
```