### 解题思路

这道题想了半天，后来我问了一下我对象，才反应过来，这不就是找边吗？找到一个左边，找到一个右边，算出面积，然后 `Math.max(areas)` 就可以了。这么一想还是挺简单的。

如果用题目描述中的例子。假如我们遍历到了 第二个 2 的位置，那我们就从 index = 4 向左找，找到最后一个不能容纳 2 的 高度，这就是最左边，然后同理，找右边框，求出面积，放入list，最后求出最大的那一个

### 代码

```javascript
/**
 * @param {number[]} heights
 * @return {number}
 */
const largestRectangleArea = (heights) => {
  const len = heights.length;
  if(!len) return len;
  const stack = [];
  const areas = [];
  for (let i = 0; i < len; i++) {
    let leftIndex = i;
    let rightIndex = i;
    const h = heights[i];
    let j = stack.length - 1;
    while (j >= 0) {
      const ele = stack[j];
      if (ele.h >= h) {
        leftIndex = stack[j].i;
        j--;
      } else { break; }
    }
    for (let k = i + 1; k < len; k++) {
      if (heights[k] > h) {
        rightIndex = k;
      } else { break; }
    }
    stack.push({ h, i });
    const width = rightIndex - leftIndex + 1;
    const height = h;
    const area = width * height;
    areas.push(area);
  }
  const maxArea = Math.max(...areas);
  console.log(maxArea);
  return maxArea;
 };
```