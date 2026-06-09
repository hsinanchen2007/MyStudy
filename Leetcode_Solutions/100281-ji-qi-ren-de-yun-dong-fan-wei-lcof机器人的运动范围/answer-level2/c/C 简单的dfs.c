### 解题思路
此处撰写解题思路

### 代码

```c
int cnt = 0;
int visted[101][101];
int isValid(int i, int j, int k)
{
    int sum = 0;
    int a = i % 10;
    int b = i/10;
    sum = a;
    while (b)
    {     
        a = b % 10;
        b = b / 10;
        sum += a;
    }

    a = j % 10;
    b = j/10;
    sum += a;
    while (b)
    {     
        a = b % 10;
        b = b / 10;
        sum += a;
    }
    if (sum > k) {
        return 1;
    }
    return 0;
    
}
void dfs(int m, int n ,int k, int i, int j)
{
    if (i < 0 || j < 0 || i >=m || j>=n || isValid(i, j, k) || visted[i][j]) {
        return;
    }
    
    cnt += 1;
    visted[i][j] = 1;
    dfs(m, n, k, i-1, j);
    dfs(m, n, k, i+1, j);
    dfs(m, n, k, i, j-1);
    dfs(m, n, k, i, j+1);
}

int movingCount(int m, int n, int k)
{
    int i, j;
    cnt = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            visted[i][j] = 0;
        }
    }
    dfs(m, n, k, 0, 0);
    return cnt;
}
```