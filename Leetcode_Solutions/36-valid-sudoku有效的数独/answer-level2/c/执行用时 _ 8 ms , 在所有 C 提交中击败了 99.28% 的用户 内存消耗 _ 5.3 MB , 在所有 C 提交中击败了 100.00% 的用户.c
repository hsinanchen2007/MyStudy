### 解题思路
此处撰写解题思路

### 代码

```c

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[9][10] = {0};
    int arr[9][10] = {0};
    int box[9][10] = {0};
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '0';
                row[i][num]++;
                arr[j][num]++;
                box[(i / 3) * 3 + (j / 3)][num]++;
                if ((row[i][num] > 1) || (arr[j][num] > 1) || (box[(i / 3) * 3 + (j / 3)][num] > 1)) {
                    return false;
                }
            }
        }
    }
    return true;
}



```