### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    let visited = [];
    let xlen = board.length;
    let ylen = board[0].length;
    let now = 0;
    for(let i = 0; i < board.length; i++){
        visited[i] = [];
    }
    for(let x = 0; x < xlen; x++){
        for(let y = 0; y < ylen; y++){
            if(search(visited, now, x, y)){
                return true;
            }
        }
    }
    function search(visited, now, x, y){
        if(now == word.length){
            return true;
        }
        let hasPath = false;
        if(x >= 0 && x < xlen && y >= 0 && y < ylen && board[x][y] == word[now] && !visited[x][y]){
            now++;
            visited[x][y] = true;
            hasPath =   search(visited, now, x+1, y) || 
                        search(visited, now, x-1, y) || 
                        search(visited, now, x, y+1) || 
                        search(visited, now, x, y-1);
            if(!hasPath){
                now--;
                visited[x][y] = false;
            }
        }
        return hasPath;
    }
    return false
};
```