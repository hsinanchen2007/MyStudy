### 解题思路
此处撰写解题思路
![a.png](https://pic.leetcode-cn.com/07439943d96d3a7f241410cb4102d0ecf3c0a2be1284c94a67f1a76353c9dfb1-a.png)
![b.png](https://pic.leetcode-cn.com/b6241dcad4b6eb4bee5bfa6554d9ded5afbd0f39aeb87a75208eca50b82bf7cf-b.png)
![c.png](https://pic.leetcode-cn.com/ca527b833b0c7af99f53973e0f1a9dde2cdbfdc72ccf6aca304f11dd10cd49bb-c.png)
![d.png](https://pic.leetcode-cn.com/17d965b3e3aaa36bc46d34978aa2140635eee1ef343c0e2bd82a6142f4634900-d.png)



### 代码

```c
bool myExist(char **board, int rows, int cols, int **arr, int row, int col, int *strLen, char* str)
{
    if (str[*strLen] == '\0') {
        return true;
    } 

    int res = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == str[*strLen] && arr[row][col] == 0) {
        (*strLen)++;
        arr[row][col] = 1;
        res = myExist(board, rows, cols, arr, row - 1, col, strLen, str) ||
              myExist(board, rows, cols, arr, row, col + 1, strLen, str) ||
              myExist(board, rows, cols, arr, row + 1, col, strLen, str) ||
              myExist(board, rows, cols, arr, row, col - 1, strLen, str);

        if (!res) {
            (*strLen)--;
            arr[row][col] = 0;
        }              
    }

    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
    if (board == NULL || boardSize <= 0 || word == NULL) {
        return false;
    }

    int rows = boardSize;
    int cols = *boardColSize;
    int i, j;
    int **arr = (int **)malloc(sizeof(int *) * rows);
    bool res = false;
    int strLen = 0;

    for (i = 0; i < rows; i++) {   
        arr[i] = (int *)malloc(sizeof(int) * cols);
        memset(arr[i], 0, sizeof(int) * cols);
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (myExist(board, rows, cols, arr, i, j, &strLen, word)) {
                res = true;
                break;;
            }
        }
    }

    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    if (res) {
        return true;
    } else {
        return false;
    }
}

```

![f.png](https://pic.leetcode-cn.com/f2c20f6a78ad25ef9bef2abbee300328ab85e3a6684f26b86c55aab2f9a97b86-f.png)
