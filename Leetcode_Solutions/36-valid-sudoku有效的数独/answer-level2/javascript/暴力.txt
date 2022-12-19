
### 暴力循环
应该没有捷径，直接暴力循环即可
```
var isValidSudoku = function (board) {
    for (let i = 0; i < 9; i++) {
        let vSet = new Set()
        let hSet = new Set()
        for (let j = 0; j < 9; j++) {
            let cValue = board[i][j]
            if (cValue !== '.') {
                if (vSet.has(cValue)) {
                    return false
                }
                vSet.add(cValue)
            }
            let hValue = board[j][i]
            if (hValue !== '.') {
                if (hSet.has(hValue)) {
                    return false
                }
                hSet.add(hValue)
            }
        }
    }

    for (let bi = 0; bi < 9; bi += 3) {
        for (let bj = 0; bj < 9; bj += 3) {
            let set = new Set()
            for (let i = bi; i < bi + 3; i++) {
                for (let j = bj; j < bj + 3; j++) {
                    let cValue = board[i][j]
                    if (cValue !== '.') {
                        if (set.has(cValue)) {
                            return false
                        }
                        set.add(cValue)
                    }
                }
            }
        }
    }
    return true
};


```