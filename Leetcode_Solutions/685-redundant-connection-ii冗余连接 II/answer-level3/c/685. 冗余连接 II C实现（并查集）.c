### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
inline void UnionFindInit(int* fa, int* rank, int n)
{
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        rank[i] = 1;
    }
    return;
}

int Find(int* fa, int x)
{
    if (x == fa[x]) {
        return x;
    } else {
        return fa[x] = Find(fa, fa[x]);
    }
}

void Union(int* fa, int x, int y, int* rank)
{
    int parentX = Find(fa, x);
    int parentY = Find(fa, y);
    if (rank[parentX] >= rank[parentY]) {
        fa[parentY] = parentX;
    } else {
        fa[parentX] = parentY;
    }
    if (rank[parentX] == rank[parentY] && parentX != parentY) {
        rank[parentX]++;
    }
    return;
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    if (!edges || edgesSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 2;
    int mallocSize = sizeof(int) * edgesSize;
    int* fa = (int*)malloc(mallocSize);
    int* rank = (int*)malloc(mallocSize);
    UnionFindInit(fa, rank, edgesSize);
    int* parent = (int*)malloc(mallocSize);
    memset(parent, -1, mallocSize);
    int* can1 = (int*)malloc(sizeof(int) * 2);
    int* can2 = (int*)malloc(sizeof(int) * 2);
    can1[0] = -1;
    can1[1] = -1;
    can2[0] = -1;
    can2[1] = -1;
    for (int i = 0; i < edgesSize; i++) {
        int start = edges[i][0] - 1;
        int end = edges[i][1] - 1;
        if (parent[end] > -1) {
            can1[0] = parent[end];
            can1[1] = edges[i][1];
            can2[0] = edges[i][0];
            can2[1] = edges[i][1];
            edges[i][0] = -1;
            edges[i][1] = -1;
        }
        parent[end] = start + 1;
    }
    for (int i = 0; i < edgesSize; i++) {
        int x = edges[i][0] - 1;
        int y = edges[i][1] - 1;
        if (x < -1 || y < -1) {
            continue;
        }
        int rX = Find(fa, x);
        int rY = Find(fa, y);
        if (rX == rY) {
            if (can1[0] == -1) {
                free(can1);
                free(can2);
                free(rank);
                free(fa);
                return edges[i];
            } else {
                free(can2);
                free(rank);
                free(fa);
                return can1;
            }
        }
        Union(fa, x, y, rank);
    }
    free(can1);
    free(rank);
    free(fa);
    return can2;
}
```