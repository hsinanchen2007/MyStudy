![1DD52376-6AB1-4FDB-A04D-93C9CD923BD9.jpeg](https://pic.leetcode-cn.com/09171f24b2d5ac9a7618976adf1d22be1bf6a6ca62933c2b08da8660c5f568e0-1DD52376-6AB1-4FDB-A04D-93C9CD923BD9.jpeg)

```
//并查集

int Find(int *graph, int a)
{
    while (graph[a] != -1) {
        a = graph[a];
    }
    return a;
}

void Union(int *graph, int a, int b) 
{
    int tmpA = Find(graph, a);
    int tmpB = Find(graph, b);
    if (tmpA != tmpB) {
        graph[tmpA] = tmpB;
    }
}

int findCircleNum(int** M, int MSize, int* MColSize)
{
    int i;
    int j;
    int *graph = (int *)malloc(MSize * sizeof(int));
    for (i = 0; i < MSize; i++) {
        graph[i] = -1;
    }

    int tmpA;
    int tmpB;
    for (i = 0; i < MSize; i++) {
        for (j = i + 1; j < MSize; j++) {
            if (M[i][j] == 1) {
                tmpA = Find(graph, i);
                tmpB = Find(graph, j);
                if (tmpA == tmpB) {
                    ;
                } else {
                    Union(graph, i, j);
                }
            }
        }
    }
    int returnVal = 0;
    for (i = 0; i < MSize; i++) {
        if (graph[i] == -1) {
            returnVal++;
        }
    }
    return returnVal;
}
```
