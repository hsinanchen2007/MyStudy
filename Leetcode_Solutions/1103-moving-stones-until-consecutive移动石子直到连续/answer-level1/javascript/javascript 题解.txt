### 解题思路

大家好，我是 17

解决的关键在于分类讨论。

为了简化一些，首先对 a,b,c排个序。

找到最大值比较简单，直接 c-a-2

找到最小值麻烦一些需要分四种情况。

1. 完全挨着，不用移动
2. 有一边是挨着，只需要移动另一边 
3. 有一边的空位只有一个，把另一边进来正好三个都变成紧挨着。
4. 两边都得移动

2,3 可以合在一起判断 `(left < 2 || right < 2)`

### 代码

```javascript
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number[]}
 */
var numMovesStones = function (a, b, c) {
  [a, b, c] = [a, b, c].sort((a, b) => a - b)

  let left = b - a - 1
  let right = c - b - 1

  let max = right + left
  let min = 0
  if (left == 0 && right == 0) min = 0
  else if (left < 2 || right < 2) {
    min = 1
  }
  else {
    min = 2
  }


  return [min, max]

};
```