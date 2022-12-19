注意只能吃一个卒子就得停止
```
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int row, col;
    int idxrow, idxcol;
    int numpawn = 0;
    for (row = 0; row < boardSize; row++) {
        for (col = 0; col < * boardColSize; col++) {
            if (board[row][col] == 'R') {
                idxcol = col;
                idxrow = row;
                break;
            }
        }
    }
    int t1 = idxrow;
    int t2 = idxcol;
    while (idxrow >= 0) {
        if (board[idxrow][t2] == 'B') {
            break;
        } else if (board[idxrow][t2] == 'p') {
            numpawn++;
            break;
        }
        idxrow--;
    }
    
    idxrow = t1;
    while (idxrow < boardSize) {
        if (board[idxrow][t2] == 'B') {
            break;
        } else if (board[idxrow][t2] == 'p') {
            numpawn++;
            break;
        }
        idxrow++;
    }
    
    while (idxcol >= 0) {
        if (board[t1][idxcol] == 'B') {
            break;
        } else if (board[t1][idxcol] == 'p') {
            numpawn++;
            break;
        }
        idxcol--;
    }
    idxcol = t2;
    while (idxcol < * boardColSize) {
        if (board[t1][idxcol] == 'B') {
            break;
        } else if (board[t1][idxcol] == 'p') {
            numpawn++;
            break;
        }
        idxcol++;
    }
    return numpawn;
}
```
