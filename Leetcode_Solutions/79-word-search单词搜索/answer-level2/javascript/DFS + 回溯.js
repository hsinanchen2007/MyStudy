### 解题思路
深度优先搜索 + 回溯

从每一个点出发，进行 DFS，如果不行则回溯

注意：
- 二维平面的移动可以定义一个 offsetArr 数组

### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */

const offsetArr = [{x: -1, y: 0}, {x: 1, y: 0}, {x: 0, y: -1}, {x: 0, y: 1}];

const backTrace = (board, word, wordIndex, x, y) => {
    if (board[x][y] !== word[wordIndex]) return false;
    if (wordIndex === word.length - 1) return true;
    const temp = board[x][y]; // 记录当前的字符，方便后面回溯
    board[x][y] = 0;
    ++wordIndex;
    // 只要四周有一个元素满足，则返回 true
    for (let i = 0; i < 4; ++i) {
        const x1 = offsetArr[i].x + x;
        const y1 = offsetArr[i].y + y;
        if (x1 >= 0 && x1 < board.length && y1 >= 0 && y1 < board[0].length && backTrace(board, word, wordIndex, x1, y1)) return true;
    }
    board[x][y] = temp; // 回溯
    return false;
}

var exist = function(board, word) {
    for (let i = 0; i < board.length; ++i) {
        for (let j = 0; j < board[0].length; ++j) {
            if (backTrace(board, word, 0, i, j)) return true;
        }
    }
    return false;
};
```

### 复杂度
- 时间复杂度 O(M*N^2)
- 空间复杂度 O(M*N)