### 解题思路
还是使用哈希来减少遍历的次数。。。只不过这一次是从一位数组变成了二维数组，哈希一直是优化数组遍历的一个好方案。

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    const row = {}
    const col = {}
    const box = {}
    for(let i = 0;i<9;i++) {
        for(let j=0;j<9;j++) {
            let box_index = Math.floor((i / 3)) * 3 + Math.floor((j/3))
            let value = board[i][j]
            if(value!=='.') {
                if(!box[box_index]) {
                    box[box_index] = {}
                }
                if(box[box_index][value]) {
                    console.log('box',box_index, value,i,j,box)
                    return false
                } else {
                    box[box_index][value] = true
                }
                if(!row[i]) {
                    row[i] = {}
                }
                if(row[i][value]) {
                    console.log('row',row)
                    return false
                } else{
                    row[i][value] = true
                }
                if(!col[j]) {
                    col[j] = {}
                }
                if(col[j][value]) {
                    console.log('col',col)
                    return false
                } else {
                    col[j][value] = true
                }
            }
        }
    }
    return true
};
```