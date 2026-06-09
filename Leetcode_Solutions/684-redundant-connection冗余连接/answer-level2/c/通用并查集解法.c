### 解题思路
union的时候直接做路径压缩

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXLEN 1001

int FindPar(int *index, int x)
{
    while (index[x] != x) {
        x = index[x];
    }
    return x;
}

int myunion(int *index, int x, int y)
{
    int px = FindPar(index, x);
    int py = FindPar(index, y);

    if (px == py) {
        return 0;
    } else if (px > py) {
        index[py] = px;
        return 1;
    } else {
        index[px] = py;
        return 1;
    }
}

int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
    int index[MAXLEN];
    for (int i = 0; i < MAXLEN; i++) {
        index[i] = i;
    }

    int *buf = (int *)malloc(sizeof(int) * edgesColSize[0]);
    for (int j = 0; j < edgesSize; j++) {
        if (myunion(index, edges[j][0], edges[j][1]) == 0) {
            buf[0] = edges[j][0];
            buf[1] = edges[j][1];
        }
    }
    *returnSize = edgesColSize[0];
    return buf;
}
```