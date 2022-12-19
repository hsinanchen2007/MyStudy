![图片.png](https://pic.leetcode-cn.com/db455278451700b79d9d1c91b116572cbc98d2a1099f297252ed27e21251e0b9-%E5%9B%BE%E7%89%87.png)

```
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */

var directs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
var inArea = function (x, y, m, n) {
    return (x >= 0 && x < m && y >= 0 && y < n)
}
var serachWord = function(board, word, index, startx, starty, m, n, visited) {
    // 如果当前递归的深度已经等于当前单词的长度  直接返回是否匹配
    if (index === word.length - 1) {
        return board[startx][starty] === word[index]
    }
    // 如果匹配
    if (word[index] === board[startx][starty]) {
        visited[startx][starty] = true
        // 从startx starty 出发  向四个方向寻找
        for(let i=0; i<4; i++) {
            let newx = startx + directs[i][0]
            let newy = starty + directs[i][1]
            // 如果新方向没有越界  且  没有被访问过递归
            if (inArea(newx, newy, m, n) && !visited[newx][newy]) {
                // 找到匹配的单词
                if(serachWord(board, word, index + 1, newx, newy, m, n, visited)){
                    return true
                }
            }
        }
        // 遍历四个方向依然没有找到  回溯
        visited[startx][starty] = false
    }
    return false
}

var exist = function(board, word) {
    let m = board.length
    let n = board[0].length
    // 创建一个二维数组记录 这里不能直接fill一个对象  小坑
    let visited = new Array(m).fill(undefined).map(item => { return new Array(n).fill(false)})
    // 遍历二维数组
    for (let i=0; i<board.length; i++) {
        for(let j=0; j<board[i].length; j++) {
            if(serachWord(board, word, 0, i, j, m, n, visited)){
                return true
            }
        }
    }
    return false
};
```
