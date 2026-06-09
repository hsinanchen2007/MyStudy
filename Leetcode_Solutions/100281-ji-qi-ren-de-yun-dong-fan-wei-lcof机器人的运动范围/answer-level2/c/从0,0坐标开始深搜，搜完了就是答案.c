### 解题思路
从0,0坐标开始深搜，搜完了就是答案

### 代码

```c
inline int calcSum(int m) {
    int sum = 0;
    while (m) {
        sum += (m%10);
        m /= 10;
    }
    return sum;
}

void dfs(int i, int j, char *visited, int m, int n, int k, int *step) {
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    if (visited[i*n+j]) return;
    if (calcSum(i) + calcSum(j) > k) return;

    *step += 1;
    visited[i*n+j] = 1;
    dfs(i+1, j, visited, m, n, k, step);
    dfs(i-1, j, visited, m, n, k, step);
    dfs(i, j+1, visited, m, n, k, step);
    dfs(i, j-1, visited, m, n, k, step);
    return;
}

int movingCount(int m, int n, int k){
    int step = 0;
    char visited[m][n];
    (void)memset(visited, 0, m*n);

    dfs(0, 0, visited, m, n, k, &step);
    return step;
}
```