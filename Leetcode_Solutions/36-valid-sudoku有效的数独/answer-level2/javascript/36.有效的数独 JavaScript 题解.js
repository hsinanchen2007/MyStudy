![javascript.jpg](https://pic.leetcode-cn.com/e01cc32e664a6ba11875de17a91f144f9b0ab6418c3d5fdbec9e3db45d1e8173-javascript.jpg)

<br />

> 我总觉得的使用map没有意义, 这里不需要键值映射, 只需要has方法判断是否重复 `(小声bb: 如果这道题不是分类在哈希表下面, 我用indexOf都能省了set)`

```javascript []
const isValidSudoku = arr => {
  for (let i = 0; i < 9; i++) {
    // 遍历行*列
    let row = new Set(), col = new Set()
    for (let j = 0; j < 9; j++) {
      if (arr[i][j] !== '.') {
        if (row.has(arr[i][j])) return false
        row.add(arr[i][j])
      }
      if (arr[j][i] !== '.') {
        if (col.has(arr[j][i])) return false
        col.add(arr[j][i])
      }
    }
    // 遍历3*3小宫格
    let block = new Set()
    let x = (i / 3 >> 0) * 3, y = i % 3 * 3
    for (let j = 0; j < 9; j++) {
      if (arr[x][y] !== '.') {
        if (block.has(arr[x][y])) return false
        block.add(arr[x][y])
      }
      y++
      if ((j + 1) % 3 === 0) {
        x += 1
        y -= 3
      }
    }
  }
  return true
}
```

<br />

- 遍历行

![row.png](https://pic.leetcode-cn.com/00373a6a733cfed6c766527ef4dbf88cfb4b856949dc9028470155c87c90b1af-row.png)

- 遍历列

![col.png](https://pic.leetcode-cn.com/fc6d4779665e0c1f202dd31b7eaeaacbf63f425cc192c861368a618aa4f06e5b-col.png)

- 遍历3*3小宫格

![block.png](https://pic.leetcode-cn.com/4a55d03477a663c7bc4428b8324bdb8b37a27e36e2b67bb5bb22b9bd2eb399f5-block.png)