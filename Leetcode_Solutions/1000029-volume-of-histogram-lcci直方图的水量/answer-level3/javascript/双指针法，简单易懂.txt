### 解题思路
双指针，根据两边的柱子中较矮的柱子来计算当前柱子能装多少水。

举个栗子

目前有三根柱子，第一根(高度记为 `h1`)、第三根(高度记为 `h3`)都不可能装水，只有第二个根(高度记为 `h2`)可能装水。

当且仅当 `(min(h1, h3) > h2)`，才能装水，装水量由第一、第三两根柱子中较矮的柱子决定，则装水量为 `(min(h1, h3) - h2)`。

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
  const len = height.length
  let res = 0
  let maxLeft = height[0]
  let maxRight = height[len - 1]
  let left = 1
  let right = len - 2
  
  // 第一个和最后一个不可能存水
  for (let i = 1; i < len - 1; i++) {
    if (height[left - 1] < height[right + 1]) {
      maxLeft = Math.max(maxLeft, height[left - 1])
      if (maxLeft > height[left]) {
        res += maxLeft - height[left]
      }
      left++
    } else {
      maxRight = Math.max(maxRight, height[right + 1])
      if (maxRight > height[right]) {
        res += maxRight - height[right]
      }
      right--
    }
  }

  return res
};
```