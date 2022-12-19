### 解题思路

![image.png](https://pic.leetcode-cn.com/456b0037258ba7726451e0dba67b8201223d4a5813cbfa5f37b6a229ebbd3df7-image.png)

### 代码

```c
#define MY_SIZE 9
#define MY_NUM_3 3
#define MY_INVALID (-1)
int trans(char cur)
{
    if (cur == '.') {
        return MY_INVALID;
    }
    return cur - '1'; 
}
bool isSqureValid(char** board, int boardSize, int* boardColSize)
{
    int i, j, k;
    int x, y;
    int inx;
    int hash[MY_SIZE];
    for (i = 0; i < MY_SIZE; i++) {
        x = (i / MY_NUM_3) * MY_NUM_3;
        y = (i % MY_NUM_3) * MY_NUM_3;
        memset(hash, 0x00, sizeof(int) * MY_SIZE);
        for (j = x; j < x + MY_NUM_3; j++) {
            for (k = y; k < y + MY_NUM_3; k++) {
                inx = trans(board[j][k]);
                if (inx == MY_INVALID) {
                    continue;
                }
                if (hash[inx] != 0) {
                    return false;
                }
                hash[inx]++;
            }
        }
    }
    return true;
}

bool isColValid(char** board, int boardSize, int* boardColSize)
{
    int i, j;
    int hash[MY_SIZE];
    int inx;
    for (i = 0; i < MY_SIZE; i++) {
        memset(hash, 0x00, sizeof(int) * MY_SIZE);
        for (j = 0; j < MY_SIZE; j++) {
            inx = trans(board[j][i]);
            if (inx == MY_INVALID) {
                continue;
            }
            if (hash[inx] != 0) {
                return false;
            }
            hash[inx]++;
        }
    }
    return true;
}

bool isRowValid(char** board, int boardSize, int* boardColSize)
{
    int i, j;
    int hash[MY_SIZE];
    int inx;
    for (i = 0; i < MY_SIZE; i++) {
        memset(hash, 0x00, sizeof(int) * MY_SIZE );
        for (j = 0; j < MY_SIZE; j++) {
            inx = trans(board[i][j]);
            if (inx == MY_INVALID) {
                continue;
            }
            if (hash[inx] != 0) {
                return false;
            }
            hash[inx]++;
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    return isRowValid(board, boardSize, boardColSize) && 
        isColValid(board, boardSize, boardColSize) &&
        isSqureValid(board, boardSize, boardColSize);
}
```