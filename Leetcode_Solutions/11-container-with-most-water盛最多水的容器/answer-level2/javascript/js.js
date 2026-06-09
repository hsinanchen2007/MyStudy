### 解题思路
定义左右两个指针，从两边向中间靠拢，每次短的指针向中央靠拢一位，并计算最大面积，直到两个指针重合
### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  let len = height.length
  let left = 0 // 左边指针
  let right = len - 1 // 右边指针
  let max_area = 0
  while (left!==right){
    if (height[left] >= height[right]) {
      // 左边的比较高则右边的向中间靠拢
      max_area = Math.max((right - left) * height[right],max_area)
      right --
    }else {
      // 同理
      max_area = Math.max((right - left) * height[left],max_area)
      left ++
    }
  }
  return max_area
}
```