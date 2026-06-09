![105C9D7E-3BF8-4050-B151-F3CD4441DCFC.jpeg](https://pic.leetcode-cn.com/494aa22b72b2784999c8ce40f7a31e57d88731169197c824dc541b389e45d144-105C9D7E-3BF8-4050-B151-F3CD4441DCFC.jpeg)

```
#define COLSIZE 2

int Find(int *graph, int a)
{
    while (graph[a] != -1) {
        a = graph[a];
    }
    return a;
}

void Union(int *graph, int a, int b)
{
    int tmpA;
    int tmpB;
    tmpA = Find(graph, a);
    tmpB = Find(graph, b);
    if (tmpA != tmpB) {
        graph[tmpB] = tmpA;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int i;
    int graphNum = 0;
    *returnSize = 2;
    int *returnVal = (int *)malloc(COLSIZE * sizeof(int));
    for (i = 0; i < edgesSize; i++) {
        if (graphNum < edges[i][0]) {
            graphNum = edges[i][0];
        }
        if (graphNum < edges[i][1]) {
            graphNum = edges[i][1];
        }
    }
    //printf("graphNum: %d\n", graphNum);
    int *graph = (int *)malloc((graphNum + 1) * sizeof(int));
    for (i = 0; i < graphNum + 1; i++) {
        graph[i] = -1;
    }

    int tmpA;
    int tmpB;
    for (i = 0; i < edgesSize; i++) {
        tmpA = Find(graph, edges[i][0]);
        tmpB = Find(graph, edges[i][1]);
        if (tmpA == tmpB) {
            returnVal[0] = edges[i][0];
            returnVal[1] = edges[i][1];
            break;
        } else {
            Union(graph, edges[i][0], edges[i][1]);
        }
    }
    free(graph);
    return returnVal;
}
```
