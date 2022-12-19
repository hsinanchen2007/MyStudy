利用map
```
var isValidSudoku = function (board) {
  let col = new Map() // 列数据
  let box = new Map() // 小方格数据
  for (let i = 0; i < 9; i++) {
    const row = board[i]
    for (let j = 0; j < 9; j++) {
      const e = board[i][j]
      if (e !== '.') {
        k =  ~~(i / 3) * 3 + ~~(j / 3)  // 两次取反取整
        if (row.indexOf(e) != j || col.get(j + '-' + e) || box.get(k + '-' + e)) { // 存在重复
          return false
        }
        col.set(j + '-' + e, true)
        box.set(k + '-' + e, true)
      }
    }
  }
  return true
};

```


