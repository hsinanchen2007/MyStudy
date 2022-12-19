### 速度
![123.png](https://pic.leetcode-cn.com/0fb572ef338e67c1fd6ccc7790cb7007b47c928605d25ebaf7b6192cb2ee8242-123.png)


### 解题思路
1. 首先，需要判断的是三种，行，列，块
2. 所以，分别定义3个变量记录，行Set，列Set，和块的SetList（因为块不方便遍历，所以不能重复使用，只能用放在数组里）
3. 对于行判断，i为行，j为列，如果是从头开始，`j=0`，那么清空，如果已经存了这个数，就代表重复，返回`false`，否则放入`rowSet`中
4. 对于列判断，道理类似，只是把i看作列，j看作行，所以只用一遍双循环
5. 对于块，首先一共9块，看作3行3列，可以通过除以3操作得到在哪一行哪一列，因为是一维数组，所以通过`行数 * 3 + 列数`得到索引，判断道理类似
（不知道这方法好不好）

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    const rowSet = new Set()
    const columnSet = new Set()
    const setList = Array.from({ length: 9 }, () => new Set())
    for(let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[i].length; j++) {
            const m = parseInt(i / 3)
            const n = parseInt(j / 3)
            const idx = m * 3 + n // setList的索引
            if (j === 0) {
                rowSet.clear()
                columnSet.clear()
            }
            if (rowSet.has(board[i][j]) || columnSet.has(board[j][i])) return false
            if (setList[idx].has(board[i][j])) return false
            board[i][j] !== '.' && setList[idx].add(board[i][j])
            board[i][j] !== '.' && rowSet.add(board[i][j])
            board[j][i] !== '.' && columnSet.add(board[j][i])
        }
    }
    return true
};
```