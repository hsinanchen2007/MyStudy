### 解题思路
递归：难者不会，会者不难，初学递归容易绕晕

### 代码

```c
int CheckPos(int x, int y) 
{
   int count = 0;

   while (x != 0) {
       count += x % 10;
       x = x / 10;
   }
   while (y != 0) {
       count += y % 10;
       y = y / 10;
   }
   return count;
}

void MoveStep(int x, int y, int m, int n, int** visit, int k, int *count)
{
    int debug = 0;
    if(debug) printf("==check x %d,y %d, count %d\n",x, y, *count);
    if (x >= m || y >= n || x < 0 || y < 0 || visit[x][y] == 1) {
        return;
    }
    if (debug) printf("====check vist %d, check k %d\n",visit[x][y], CheckPos(x,y));
    if (k < CheckPos(x, y)) {
        return;
    }
    (*count)++;
    visit[x][y] = 1;
    // 向上
    MoveStep(x - 1, y, m, n, visit, k, count);
    // 向右
    MoveStep(x, y + 1, m, n, visit, k, count);
    // 向下
    MoveStep(x + 1, y, m, n, visit, k, count);
    // 向左
    MoveStep(x, y - 1, m, n, visit, k, count);
    
    return;
}
int movingCount(int m, int n, int k){
    int **visit = NULL;
    int count = 0;

    visit = (int**)calloc(m, sizeof(int*));
    for (int i = 0; i < m; i++) {
        visit[i] = (int*)calloc(n, sizeof(int));
    }
    MoveStep(0, 0, m, n, visit, k, &count);   
    for (int i = 0; i < m; i++) {
        free(visit[i]);
    }
    free(visit);
    return count;
}
```