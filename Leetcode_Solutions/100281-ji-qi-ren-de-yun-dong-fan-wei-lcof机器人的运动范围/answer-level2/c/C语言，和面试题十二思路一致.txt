### 解题思路
此处撰写解题思路

### 代码

```c
int toDigit(int num) {
    int res = 0;    

    while (num) {
        res += num % 10;
        num /= 10;
    }

    return res;
}

bool checked(int **arr, int rows, int cols, int row, int col, int k)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        if (toDigit(row) + toDigit(col) <= k) {
            if (arr[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

int myMovingCount(int **arr, int rows, int cols, int row, int col, int k)
{
    int cnt = 0;
    if (checked(arr, rows, cols, row, col, k)) {
        arr[row][col] = 1;

        /* 这里的1表示当前的数组是满足要求的 */
        cnt = 1 + myMovingCount(arr, rows, cols, row - 1, col, k) +
               myMovingCount(arr, rows, cols, row, col - 1, k) +
               myMovingCount(arr, rows, cols, row + 1, col, k) + 
               myMovingCount(arr, rows, cols, row, col + 1, k);
    }

    return cnt;
}

int movingCount(int m, int n, int k){
    if (m <= 0 || n <= 0) {
        return 0;
    } 

    int i, j;
    int res = 0;
    int **arr = (int *)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++) {
        arr[i] = (int *)malloc(sizeof(int) * n);
        memset(arr[i], 0, sizeof(int) * n);
    }

    res = myMovingCount(arr, m, n, 0, 0, k);

    for (i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return res;
}

```