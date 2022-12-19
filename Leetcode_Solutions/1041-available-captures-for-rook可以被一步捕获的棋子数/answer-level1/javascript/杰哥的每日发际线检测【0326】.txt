### 解题思路
乍一看是一个图算法，但是其实没有那么复杂。
第一步是找到R的位置，复杂度n^2，感觉没什么好优化的。

接下来就是定义【四个方向】
其实用坐标系就可以解决。

真正的坑点在于，遇到p和b之后，都需要中止循环，此处稍不注意就会用contine。

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let eat = 0;


    let posRow = posCol = 0;
    for (let i = 0; i <= 7; i++) {
        for (let j = 0; j <= 7; j++) {
            if (board[i][j] === 'R') {
                posRow = i;
                posCol = j;
                break;
            }
        }
    }

    console.log('位置', posRow, posCol)

    const directionsRow = [-1, 0, 1, 0];
    const directionsCol = [0, -1, 0, 1];
    for (let d = 0; d <= 3; d++) {
        const next = [directionsRow[d], directionsCol[d]];
        console.log('方向', next)
        for (let s = 0; s <= 7; s++) {
            if ((posRow + next[0] * s) >= 8 || (posCol + next[1] * s) >= 8) {
                continue;
            }

            if ((posRow + next[0] * s) < 0 || (posCol + next[1] * s) < 0) {
                continue;
            }

            const nextPos = board[posRow + next[0] * s][posCol + next[1] * s];
            console.log('nextPos', '(',posRow + next[0] * s, ',', posCol + next[1] * s, ')' , nextPos);
            if (nextPos === 'B') {
                console.log('遇到b中止')
                break;
            }
            if (nextPos === 'p') {
                console.log('遇到p,牛逼')
                eat += 1;
                break;
            }
        }
    }
    return eat;
};
```