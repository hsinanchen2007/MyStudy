### 解题思路
此处撰写解题思路

![image.png](https://pic.leetcode-cn.com/f8a4792e8ffe6f75a3fc9ad26f428fa41b72205ed8014e643425f73ce2bd9dee-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int *g_dest = NULL;
static const int g_maxSize = 1001;

static bool Init(void)
{
    g_dest = (int *)malloc(g_maxSize * sizeof(int));
    if (g_dest == NULL) {
        return false;
    }

    for (int i = 0; i < g_maxSize; i++) {
        g_dest[i] = i;
    }
    return true;
}

static int FindRoot(int i)
{
    int son = i;
    while (g_dest[i] != i) {
        i = g_dest[i];
    }
    int tmp;
    /* 路径压缩 */
    while (son != i) {
        tmp = g_dest[son];
        g_dest[son] = i;
        son = tmp;
    }
    return i;
}

static void FreeCircle(void)
{
    if (g_dest != NULL) {
        free(g_dest);
        g_dest = NULL;
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    if (!Init()) {
        return NULL;
    }

    for (int i = 0; i < edgesSize; i++) {
        int root1 = FindRoot(edges[i][0]);
        int root2 = FindRoot(edges[i][1]);
        if (root1 != root2) {
            g_dest[root1] = root2;
            continue;
        }
        FreeCircle();
        *returnSize = 2;
        return edges[i];
    }
    return NULL;
}
```