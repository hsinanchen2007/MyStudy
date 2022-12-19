思路：定义变量res =0； 先搜索到 车 的坐标。然后 上下左右遍历，碰到黑色的卒 res加1终止循环 或碰到白色的象终止循环， 最后返回res数量 。

```
var numRookCaptures = function(board) {
    let n = board.length
    let res = 0
    for(let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let val = board[i][j]
            if (val === 'R') {
                let top = i -1
                while(top >= 0) {
                    let current = board[top][j]
                    if (current === 'p') {
                        res++
                        break
                    } else if (current === 'B') {
                        break
                    }
                    top--
                }
                let bottom = i + 1
                while (bottom < n) {
                    let current = board[bottom][j]
                    if (current === 'p') {
                        res++
                        break
                    } else if (current === 'B') {
                        break
                    }
                    bottom++
                }
                let left = j -1
                while (left >= 0) {
                    let current = board[i][left]
                    if(current === 'p') {
                        res++
                        break
                    } else if (current === 'B') {
                        break
                    }
                    left--
                }
                let right = j + 1
                while (right < n) {
                    let current = board[i][right]
                    if (current === 'p') {
                        res++
                        break
                    } else if (current === 'B') {
                        break
                    }
                    right++
                }
                return res
            }
        }
    }
}
```