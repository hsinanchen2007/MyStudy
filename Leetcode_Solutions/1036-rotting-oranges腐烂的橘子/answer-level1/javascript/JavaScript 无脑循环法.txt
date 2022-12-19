### 解题思路
你站在这别动，我去买几个橘子😂😂😂
1. 写一个函数把 每次坏掉的橘子记录下来，存在数组里面，函数的返回值是坏掉橘子的位置,组成的数组
```js
  function count(grid) {
    let arr = []
    for (let i = 0; i < grid.length; i++) {
      for (let j = 0; j < grid[0].length; j++) {
        if (grid[i][j] === 2) {
          arr.push([i, j])
        }
      }
    }
    return arr
  }
```
2. 定义一个 坏橘子的操作,取出上面统计的结果，循环遍历每个元素,把数组中的每个坏橘子，周围的好橘子腐烂掉。
每次，所有的腐烂操作结束后，再进行一次，统计坏橘子的位置，如果发现，统计函数返回的坏橘子的位置数组，和上次一样。说明能被腐烂的已经全腐烂了，此时返回times(即bad函数被调用的次数-1),否则继续调用bad函数，进行坏橘子的操作。
```js
  let times = 0;
  let badsArr = count(grid)
  function bad() {
    badsArr.forEach(([i, j]) => {
      if (i - 1 >= 0 && grid[i - 1][j] == 1) {
        grid[i - 1][j] = 2
      }
      if (i + 1 < grid.length && grid[i + 1][j] == 1) {
        grid[i + 1][j] = 2
      }
      if (j - 1 >= 0 && grid[i][j - 1] ==1) {
        grid[i][j - 1] = 2
      }
      if (j + 1 < grid[0].length && grid[i][j + 1] ==1) {
        grid[i][j + 1] = 2
      }
    })
    let newBadsArr = count(grid)
    if (newBadsArr.length === badsArr.length) {
      return times
    } else {
      times++
      badsArr = newBadsArr
      return bad()
    }
  }
  bad()
```
3. 上述，两个过程都结束之后，我们再次看一下现在的二维橘子数组，如果在数组里面，找到了好的橘子。说明，没完全腐烂成功，返回 `-1`,否则 返回 `times`
```js
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === 1) {
        return -1
      }
    }
  }
```
### 完整代码如下

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function (grid) {
  function count(grid) {
    let arr = []
    for (let i = 0; i < grid.length; i++) {
      for (let j = 0; j < grid[0].length; j++) {
        if (grid[i][j] === 2) {
          arr.push([i, j])
        }
      }
    }
    return arr
  }
  let times = 0;
  let badsArr = count(grid)
  function bad() {
    badsArr.forEach(([i, j]) => {
      if (i - 1 >= 0 && grid[i - 1][j] == 1) {
        grid[i - 1][j] = 2
      }
      if (i + 1 < grid.length && grid[i + 1][j] == 1) {
        grid[i + 1][j] = 2
      }
      if (j - 1 >= 0 && grid[i][j - 1] ==1) {
        grid[i][j - 1] = 2
      }
      if (j + 1 < grid[0].length && grid[i][j + 1] ==1) {
        grid[i][j + 1] = 2
      }
    })
    let newBadsArr = count(grid)
    if (newBadsArr.length === badsArr.length) {
      return times
    } else {
      times++
      badsArr = newBadsArr
      return bad()
    }
  }
  bad()
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === 1) {
        return -1
      }
    }
  }
  return times
};
```