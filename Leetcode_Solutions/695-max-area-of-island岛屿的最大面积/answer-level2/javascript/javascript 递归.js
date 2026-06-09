# 先上代码
```
var maxAreaOfIsland = function (grid) {
  let result = []
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      result.push(spread(grid, i, j))
    }
  }
  return Math.max.apply(null, result)
};

function spread(grid, i, j) {
  if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] === 1) {
    grid[i][j] = 0
    return 1 + spread(grid, i - 1, j) + spread(grid, i + 1, j) + spread(grid, i, j - 1) + spread(grid, i, j + 1)
  } else {
    return 0
  }
}
```
为了清晰，这里分了两个函数
第一个函数作用，遍历grid里的每一个位置，然后得到每一个位置的最大岛屿数，最后返回一个最大值
核心在于第二个函数的递归，这里我们要知道要找出一个位置的最大岛屿需要注意什么：
- 首先我们需要判断当前位置是否是岛屿，也就是值是否等于1
- 如果不等于1，直接返回0个岛屿。如果等于1，则需要递归的去判断它上下左右的位置的值是否等于1，假设当前位置为（i, j），那么它上下左右的位置为（i - 1, j）、（i + 1, j）、（i, j - 1）、（i, j + 1）
- 还有一个需要注意的点是，在我们判断完当前位置的时候，将其置为0，这一步的作用是为了防止重复计算。
- 最后在判断一下边界条件ok了
