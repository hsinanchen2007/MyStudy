## 思路
1. 先草稿一个矩阵自己转一下看看，找出规律
2. 找出转移路径方程：`[i, j] = [j, length - i - 1]`
3. 再注意几个点：
    - 每次转换要转换四个位置
    - 大矩阵切分成四个小方阵的边界：`i < l / 2`, `j < l / 2 + (l % 2)`
4. 转换的时候有个小技巧：
    遍历的节点按顺时针方向，与剩下的三个节点依次做交换操作（理解起来可能有点绕，可以结合代码看看）

## ES6 新特性
通过数组新特性，在一句语句里交换两个值：
```javascript
y = [x, x = y][0]
```
> 主要是面试被问到了，印象深刻。。。
> 代码里也大量使用了这个特性

## 代码
```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
  let l = matrix.length
  let b = parseInt(l / 2)
  for (let i = 0; i < b; i++) {
    for (let j = 0; j < b + (l % 2); j ++) {
      let x = j, y = l - i - 1
      matrix[i][j] = [matrix[x][y], matrix[x][y] = matrix[i][j]][0]
      y = [l - x - 1, x = y][0]
      matrix[i][j] = [matrix[x][y], matrix[x][y] = matrix[i][j]][0]
      y = [l - x - 1, x = y][0]
      matrix[i][j] = [matrix[x][y], matrix[x][y] = matrix[i][j]][0]
    }
  }
};
```

