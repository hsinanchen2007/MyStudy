/*1、四个for循环计数四个方向
执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5 MB
, 在所有 C 提交中击败了
100.00%
的用户
*/
/*int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int count = 0;
    bool isFind = false;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (board[i][j] == 'R') {
                if (i > 0) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (board[k][j] == 'p') {
                            count++;
                            break;
                        }else if (board[k][j] != '.') {
                            break;
                        }
                    }
                }
                if (i < boardSize - 1) {
                    for (int k = i + 1; k < boardSize; k++) {
                        if (board[k][j] == 'p') {
                            count++;
                            break;
                        }else if (board[k][j] != '.') {
                            break;
                        }
                    }
                }
                if (j > 0) {
                    for (int k = j - 1; k >= 0; k--) {
                         if (board[i][k] == 'p') {
                            count++;
                            break;
                        }else if (board[i][k] != '.') {
                            break;
                        }
                    }
                }
                if (j < *boardColSize - 1) {
                    for (int k = j + 1; k < *boardColSize; k++) {
                        if (board[i][k] == 'p') {
                            count++;
                            break;
                        }else if (board[i][k] != '.') {
                            break;
                        }
                    }
                }
                isFind = true;
                break;
            }
        }
        if (isFind) {
            break;
        }
    }
    return count;
}*/
/*2、四个方向向量坐标求解
执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.2 MB
, 在所有 C 提交中击败了
100.00%
的用户
*/
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i;
    int j;
    bool isFind = false;
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            if (board[i][j] == 'R') {
                isFind = true;
                break;
            }
        }
        if (isFind) {
            break;
        }
    }
    if (isFind == false) {
        return 0;
    }
    int count = 0;
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int k = 0; k < 4; k++) {
        int x = i + d[k][0];
        int y = j + d[k][1];
        while(x >= 0 && x < boardSize && y >= 0 && y < *boardColSize) {
            if (board[x][y] == 'p') {
                count++;
                break;
            }else if (board[x][y] != '.') {
                break;
            }
            x = x + d[k][0];
            y = y + d[k][1];
        } 
    }
    return count;
}