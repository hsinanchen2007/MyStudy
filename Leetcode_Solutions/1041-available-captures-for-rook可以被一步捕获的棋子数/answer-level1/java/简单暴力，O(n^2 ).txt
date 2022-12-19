### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
    int res = 0;
    int x = 0, y = 0;
    a : 
    for(; x < 8; x++){
        for(int k = 0; k < 8; k++){
            if(board[x][k] == 'R'){
                y = k;
                break a;
            }            
        }
    }
     //行相等
    for(int i = y; i < 8; i++){
        if(board[x][i] == 'p'){
            res++;
            break;
        }
        else if(board[x][i] == 'B') {
            break;    
        }
    }
    for(int i = y; i >= 0; i--){
        if(board[x][i] == 'p'){
            res++;
            break;
        }
        else if(board[x][i] == 'B') {
            break;    
        }
    }
    //列相等
    for(int i = x; i < 8; ++i){
        if(board[i][y] == 'p' ){
            res++;
            break;
        }
        else if(board[i][y] == 'B') {
            break;    
        }
    }
    for(int i = x; i >= 0; --i){
        if(board[i][y] == 'p' ){
            res++;
            break;
        }
        else if(board[i][y] == 'B') {
            break;    
        }
    }
    return res;
    }
}
```