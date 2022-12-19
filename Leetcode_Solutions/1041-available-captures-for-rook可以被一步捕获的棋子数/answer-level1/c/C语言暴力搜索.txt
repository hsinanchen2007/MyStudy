### 解题思路
![image.png](https://pic.leetcode-cn.com/5c25912852a0417c83a27310b0468c52807d1e6255a504f6a763dd331823e9f1-image.png)
先找到rook位置（分黑白两种情况），然后往rook上下左右四个位置遍历即可
### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int rook1, rook2;
    int black = 0;
    int sum = 0;
    int i, j;
    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < boardSize; j++) {
            if(board[i][j] == 'R' || board[i][j] == 'r') {
                rook1 = i;
                rook2 = j;
                black = board[i][j] == 'R' ? 1 : 2;
                break;
            }
        }
    }

    if(black == 1) {
        for(j = rook2 + 1; j < boardSize; j++) {
            if(board[rook1][j] == '.') {
                continue;
            } else if(board[rook1][j] == 'p') {
                sum++;
                break;
            } else {
                break;
            }
        }
        for(j = rook2 - 1; j >= 0; j--) {
            if(board[rook1][j] == '.') {
                continue;
            } else if(board[rook1][j] == 'p') {
                sum++;
                break;
            } else {
                break;
            }         
        }
        for(i = rook1 + 1; i < boardSize; i++) {
            if(board[i][rook2] == '.') {
                continue;
            } else if(board[i][rook2] == 'p') {
                sum++;
                break;
            } else {
                break;
            }           
        }
        for(i = rook1 - 1; i >= 0; i--) {
            if(board[i][rook2] == '.') {
                continue;
            } else if(board[i][rook2] == 'p') {
                sum++;
                break;
            } else {
                break;
            }           
        }
    }
    if(black == 2) {
        for(j = rook2 + 1; j < boardSize; j++) {
            if(board[rook1][j] == '.') {
                continue;
            } else if(board[rook1][j] == 'P') {
                sum++;
                break;
            } else {
                break;
            }
        }
        for(j = rook2 - 1; j >= 0; j--) {
            if(board[rook1][j] == '.') {
                continue;
            } else if(board[rook1][j] == 'P') {
                sum++;
                break;
            } else {
                break;
            }         
        }
        for(i = rook1 + 1; i < boardSize; i++) {
            if(board[i][rook2] == '.') {
                continue;
            } else if(board[i][rook2] == 'P') {
                sum++;
                break;
            } else {
                break;
            }           
        }
        for(i = rook1 - 1; i >= 0; i--) {
            if(board[i][rook2] == '.') {
                continue;
            } else if(board[i][rook2] == 'P') {
                sum++;
                break;
            } else {
                break;
            }           
        }
    }
    return sum;
}
```