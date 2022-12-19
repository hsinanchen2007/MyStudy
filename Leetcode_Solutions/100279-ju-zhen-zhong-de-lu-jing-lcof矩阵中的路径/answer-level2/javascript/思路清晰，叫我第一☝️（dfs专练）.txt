### 解题思路

思路清晰，叫我第一☝️（dfs专练）

此题，判断条件忘记加上

```js
board[i][j] == word[path.length]
```

导致超时，需要注意下


### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    if(word == '') return true

    function dfs(i, j, path){
        if(i<0 || j< 0 || i>=board.length || j>=board[0].length) return false

        if(path.length < word.length && board[i][j] == word[path.length] && board[i][j]){
            path.push(board[i][j])
            let tmp = board[i][j]
            board[i][j] = false

            if(path.join('') == word) return true

            if(dfs(i-1, j, path) ||
            dfs(i+1, j, path) ||
            dfs(i, j-1, path) ||
            dfs(i, j+1, path)){
                return true
            }

            path.pop()
            board[i][j] = tmp
        }
        return false
    }

    for(let i = 0; i< board.length; i++){
        for(let j = 0; j< board[0].length; j++){
            if(board[i][j] == word[0]){
                if(dfs(i, j, [])) return true
            }
        }
    }
    return false
};
```