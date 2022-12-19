### 解题思路
![image.png](https://pic.leetcode-cn.com/a3b68ffbe11ad686786b8aa5f35bd79526e9366c458f88e711c87a5cb90294cc-image.png)

经典的回溯算法题，和八皇后问题类似。

### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    //这里可以采用回溯算法的思想，和八皇后问题类似
    const xLen = board.length;
    const yLen = board[0].length;
    const k = 0;
    for(let x = 0; x < xLen; x ++) {
        for(let y = 0; y < yLen; y ++) {
            if(findFun(board,word,x,y,k,xLen,yLen)) return true;
        }
    }
    return false;
};
//用于判断board[x][y]的上下左右是否有work[k+1]，若有返回true
//这里有个细节，没必要一直求值的数据就以参数的形式传到函数中，不要每次都计算，比如此题中的xLen，yLen
function findFun(board, word, x, y, k, xLen, yLen) {
        if(x < 0 || x >= xLen || y < 0 || y >= yLen || board[x][y] != word[k])
            return false;
        if(k == word.length -1)//word到底了
            return true;
        let temp = board[x][y];
        board[x][y] = '-';
        let res = findFun(board, word, x - 1, y, k + 1, xLen, yLen) || findFun(board, word, x, y + 1, k + 1, xLen, yLen) || findFun(board, word, x + 1, y,  k + 1, xLen, yLen) || findFun(board, word, x, y-1, k+1, xLen, yLen);//上 右 下 左
        // board[x][y] = word[k];
        board[x][y] = temp;
        return res;
    }
```