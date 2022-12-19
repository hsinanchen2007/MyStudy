### 解题思路
1. 写find函数
2. 初始化find数组
3. 合并父节点
4. 计算不同祖先节点数量

### 代码

```c
int *F;
int *circle;

int find(int x)
{
    if (F[x] != x) {
        F[x] = find(F[x]);
    }
    return F[x];
}

int findCircleNum(int** M, int MSize, int* MColSize){
    int i;
    int j;
    int fx, fy;
    int n = MSize;
    int count = 0;
    F = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        F[i] = i;
    }
    circle = malloc(sizeof(int) * n);
    memset(circle, 0, sizeof(int) * n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (M[i][j] == 1) {
                fx = find(i);
                fy = find(j);
                if (fx != fy)
                    F[fy] = find(fx);
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (circle[find(i)] == 0) {
            count++;
            circle[find(i)]++;
        }
    }

    free(F);
    free(circle);
    return count;
}
```