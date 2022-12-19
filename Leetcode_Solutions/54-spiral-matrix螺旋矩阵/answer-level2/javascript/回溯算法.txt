遍历的过程中，假设已经遍历到下标为`[i, j]`的点，下一个点可能是其上下左右其中的一个。
优先按照当前遍历方向继续前进。
如果当前方向的下一个点已经遍历过了或者超出了范围，则根据"右下左上"的顺序继续尝试。
如果每个尝试都失败了，或者我们的结果数组里已经有了`m x n`个元素，表示遍历结束。

遍历的方向我们用一个数组表示`[[0, 1], [1, 0], [0, -1], [-1, 0]]`，以根据当前位置以及方向得到下一个可遍历的点坐标。

判断一个点是否合法的方式很简单，刚开始时只要 `0 < i < m`及`0 < j < n`即可。
然后我们在遍历的过程中，更新i和j的上下边界。
例如如果我们尝试向右遍历失败，那么表示我们以及完成了一次向右遍历，当前这一层都被访问过了，所以更新i的下边界。
其它几个方向同理。

代码如下：

```javascript
var spiralOrder = function(matrix) {
  if (matrix.length === 0) return []
  const total = matrix.length * matrix[0].length
  const result = []
  const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
  let direction = 0
  
  let x_min = 0
  let x_max = matrix.length - 1
  let y_min = 0
  let y_max = matrix[0].length - 1

  result.push(matrix[0][0])
  
  function back(node) {
    if (result.length === total) {
      updateBoundary()
      return
    }
    for (let i = 0; i < 4; i++) {
      direction = (direction + i) % 4
      let nextNode = [
        node[0] + directions[direction][0],
        node[1] + directions[direction][1]
      ]
      if (isValid(nextNode)) {
        result.push(matrix[nextNode[0]][nextNode[1]])
        back(nextNode)
      } else {
        updateBoundary()
      }
    }
  }
  
  back([0, 0])
  return result
  
  function isValid(node) {
    const [x, y] = node
    return x >= x_min && x <= x_max && y >= y_min && y <= y_max
  }
  function updateBoundary () {
    if (direction === 0) x_min++
    else if (direction === 1) y_max--
    else if (direction === 2) x_max--
    else y_min++
  }
};
```