### 解题思路
![image.png](https://pic.leetcode-cn.com/fc14709051b1a790b04dfbd02cb0a8d1e9713ec1c4cf06bd94dd25b885250700-image.png)

做题10分钟，读题90分钟。。。最后才反应过来，R是“同一点”出发往四个方向。我原来以为是“一路走，只允许一整个行走转四个方向”。。。。还纳闷这能算“简单”题？！

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let a = 0,
        b = 0,
        ret = 0;

    findR: {
        for (let i = 0; i < 8; i++) {
            for (let j = 0; j < 8; j++) {
                if (board[i][j] === "R") {
                    a = i;
                    b = j;
                    break findR;
                }
            }
        }
    }
    // Up
    for (let i = a - 1; i >= 0; i--) {
        if (board[i][b] === "B") {
            break;
        } else if (board[i][b] === "p") {
            ret++;
            break;
        }
    }
    // Down
    for (let i = a + 1; i < 8; i++) {
        if (board[i][b] === "B") {
            break;
        } else if (board[i][b] === "p") {
            ret++;
            break;
        }
    }
    // Left
    for (let j = b - 1; j >= 0; j--) {
        if (board[a][j] === "B") {
            break;
        } else if (board[a][j] === "p") {
            ret++;
            break;
        }
    }
    // Right
    for (let j = b + 1; j < 8; j++) {
        if (board[a][j] === "B") {
            break;
        } else if (board[a][j] === "p") {
            ret++;
            break;
        }
    }
    return ret;
};
```