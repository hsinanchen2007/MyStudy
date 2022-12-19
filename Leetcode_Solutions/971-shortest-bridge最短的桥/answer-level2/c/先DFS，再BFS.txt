### 解题思路
仔细检查==与=，调试了好久
1、DFS找出第一个岛，并置成2；
2、BFS不断往外搜索，第二个岛的坐标记录在一个数组中，搜索一次将0置成1，刷新数组，再BFS

### 代码

```c
#define DIR 4

void dfs(int** A, int ASize, int* AColSize, int m, int n) {
    int Row[DIR] = {-1, 0, 1, 0};
    int Col[DIR] = {0, 1, 0, -1};
    
    A[m][n] = 2;
    for (int i = 0; i < DIR; i++) {
        if (m + Row[i] >= 0 && m + Row[i] < ASize && n + Col[i] >= 0 && n + Col[i] < AColSize[n]) {
            if (A[m + Row[i]][n + Col[i]] == 1) {
                dfs(A, ASize, AColSize, m + Row[i], n + Col[i]);
            }
        }
    }
}

int bfs(int** A, int ASize, int* AColSize, int* row, int* col, int Num1) {
    int Row[DIR] = {-1, 0, 1, 0};
    int Col[DIR] = {0, 1, 0, -1};

    for (int j = 0; j < Num1; j++) {
        for (int i = 0; i < DIR; i++) {
            if (row[j] + Row[i] >= 0 && row[j] + Row[i] < ASize && col[j] + Col[i] >= 0 && col[j] + Col[i] < AColSize[col[j]]) {
                if (A[row[j] + Row[i]][col[j] + Col[i]] == 0) {
                    A[row[j] + Row[i]][col[j] + Col[i]] = 1;
                }         

                if (A[row[j] + Row[i]][col[j] + Col[i]] == 2) {
                    return 1;
                }  
                
            }
        }
    }
    return 0;
}

void refresh_arr(int** A, int ASize, int* AColSize, int* row, int *col, int* Num1) {
    int tmp = 0;
    for (int m = 0; m < ASize; m++) {
        for (int n = 0; n < AColSize[m]; n++) {
            if (A[m][n] == 1) {
                row[tmp] = m;
                col[tmp] = n;
                tmp++;
            }
        }
    }   
    *Num1 = tmp;
}

int shortestBridge(int** A, int ASize, int* AColSize){
    int m, n;
    bool isFound = false;

    int row[10000] = {0};
    int col[10000] = {0};
    for (m = 0; m < ASize; m++) {
        for (n = 0; n < AColSize[m]; n++) {
            if (A[m][n] == 1) {
                isFound = true;
                break;
            }
        }
        if (isFound) {
            break;
        }
    }
    dfs(A, ASize, AColSize, m, n);
    
    int MinStep = 0;
    int Num1;
    refresh_arr(A, ASize, AColSize, row, col, &Num1);

    while (1) {
        if (bfs(A, ASize, AColSize, row, col, Num1) == 1) {
            break;
        }
        MinStep++;
        refresh_arr(A, ASize, AColSize, row, col, &Num1);
    }

    return MinStep;
}
```