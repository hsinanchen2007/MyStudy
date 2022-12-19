### 解题思路
考虑两个矩形在x轴和y轴的映射同时线性重叠，则矩形相交

### 代码

```javascript
const isRectangleOverlap = function (rec1, rec2) {
  const [a, b, c, d] = rec1
  const [A, B, C, D] = rec2
  return Math.max(a, A) < Math.min(c, C) &&
  Math.max(b, B) < Math.min(d, D)
}
```