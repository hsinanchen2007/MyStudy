### 解题思路

大家好，我是 17

因为好多题解已经说了思路，我着重说下细节。

构造单调递减栈。从左向右构造，遇到小的就进栈，栈内元素不会有出栈。

#### 为什么是递减栈？
因为产生最大坡度有两个因素，一个是距离，一个是落差。远距离小落差也可能产生大坡度。

#### 如果要进栈的元素和栈顶元素相等，要不要进栈
这得从哪个更有利于产生最大坡度。如果相等肯定是栈内的元素能产生最大坡度，所以如果相等不进栈

#### 判断结束为什么是  `i > max`

max 表示当前的最大坡度。因为 `i <= max` 的时候，不会产生更大的坡度



### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var maxWidthRamp = function (A) {
  let stack = []
  for (let i = 0; i < A.length; i++) {
    if (stack.length == 0 || stack[stack.length - 1].val > A[i])
      stack.push({
        val: A[i],
        index: i
      })
  }
  let max = 0

  for (let i = A.length - 1; i >= max; i--) {

    while (stack.length > 0 && A[i] >= stack[stack.length - 1].val) {
      max = Math.max(i - stack.pop().index, max)
    }
  }
  return max
};
```