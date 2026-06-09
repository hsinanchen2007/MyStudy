### 解题思路
这题和岛屿数量的做法一模一样，都是将遇到的战舰（岛屿）下沉。
1. sink函数，逻辑是如果遇到'X'，将该坐标处改成'.'（下沉） ，并且向周围扩散，将四周的战舰（岛屿）一同下沉，因为战舰（岛屿）是连在一起的。遇到终止条件即停止扩散
2. 双重循环遍历二维数组，如果遇到'X'，count++，然后调用sink函数

![Snipaste_2020-02-16_13-32-58.png](https://pic.leetcode-cn.com/d68cf381dab849a4fe50a6a2953e0984648bbb9fec63d0d10d523a1707dde500-Snipaste_2020-02-16_13-32-58.png)
![Snipaste_2020-02-16_13-34-59.png](https://pic.leetcode-cn.com/85133b31f283b6ce0d38db3c0af8bb878357ffdf7cca7bcd6d5d51bf43889c68-Snipaste_2020-02-16_13-34-59.png)
![Snipaste_2020-02-16_13-35-28.png](https://pic.leetcode-cn.com/3a9d2773f7c85771515aaccfae26b37c76d755bdfaa566d5f43e7bdee6669ffb-Snipaste_2020-02-16_13-35-28.png)
![Snipaste_2020-02-16_13-36-15.png](https://pic.leetcode-cn.com/38470d1dd639ae7cff95c71672094848e8c084dc8983578b9ae2be556f197974-Snipaste_2020-02-16_13-36-15.png)
![Snipaste_2020-02-16_13-37-10.png](https://pic.leetcode-cn.com/6d17d65061ef23bae62e4ee6f69ab140f1f1b100b97e6ca3e97f5543621522ff-Snipaste_2020-02-16_13-37-10.png)
![Snipaste_2020-02-16_13-37-42.png](https://pic.leetcode-cn.com/416fe9219c5e09cf5975a1128d792b72aeaffbc16bb2b39a28653e5b80bae392-Snipaste_2020-02-16_13-37-42.png)







### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var countBattleships = function(board) {
    let count = 0

    const sink = (row, col) => {
        //如果超出范围则终止，遇到'.'也终止
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length || board[row][col] == '.') {
            return
        }
        //下沉
        board[row][col] = '.'
        //向四周扩散
        sink(row + 1, col)
        sink(row - 1, col)
        sink(row, col + 1)
        sink(row, col - 1)
    }

    for (let row = 0; row < board.length; row++) {
        for (let col = 0; col < board[0].length; col++) {
            if (board[row][col] == 'X') {
                count++
                sink(row, col)
            }
        }
    }

    return count
}
```