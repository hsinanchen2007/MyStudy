```
var isValidSudoku = function(board) {
    let flag = true
    for (let i = 0; i < 9; i++) {
        if (!flag) break;
        if (!checkArr(board[i])) flag = false
        const arr = []
        for (let j = 0; j < 9; j++) {
            if (!flag) break
            if (i % 3 === 1 && j % 3 === 1 && !checkCenter(i, j, board)) flag = false
            arr.push(board[j][i])
            if (j === 8 && !checkArr(arr)) flag = false
        }
    }
    return flag
}

function checkArr(arr) {
    return arr.reduce(([result, cacheObj], item) => {
        if (cacheObj[item]) cacheObj[item]++
        else cacheObj[item] = 1
        if (item !== '.' && cacheObj[item] > 1) result = false
        return [result, cacheObj]
    }, [true, {}])[0]
}

function checkCenter(posX, posY, board) {
    const arr = []

    for (let i = posX - 1; i <= posX + 1; i++) {
        for (let j = posY - 1; j <= posY + 1; j++) {
            arr.push(board[i][j])
        }
    }

    return checkArr(arr)
}
```
