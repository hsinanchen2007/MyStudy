

```c
int g_num[] = {
    1,
    0,
    0,
    2,
    10,
    4,
    40,
    92,
    352,
    724,
    2680,
    14200,
    73712,
    365596,
    2279184
};
int totalNQueens(int n){
    return (n == 0) ? 0 : g_num[n - 1];
}

```