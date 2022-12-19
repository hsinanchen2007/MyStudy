```
#define MAXSIZE 1001

int Find(int a, int *graph) {
    while (a != graph[a]) {
        a = graph[a];
    }
    return a;
}

void Union(int a, int b, int *graph) {
    int tmpA = Find(a, graph);
    int tmpB = Find(b, graph);
    if (tmpB >= tmpA) {
        graph[tmpB] = tmpA;
    } else {
        graph[tmpA] = tmpB;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    if ((edges == NULL) || (edgesSize == 0) || (edgesColSize == NULL) || (*edgesColSize == 0)) {
        *returnSize = 0;
        return NULL;
    }
    if (returnSize == NULL) {
        return;
    }

    int i;
    int n = MAXSIZE;
    int *returnVal = (int *)malloc(2 * sizeof(int));
    memset(returnVal, 0, 2 * sizeof(int));
    int *graph = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        graph[i] = i;
    }
    *returnSize = 2;

    for (i = 0; i < edgesSize; i++) {
        //printf("before: Find(edges[%u][0], graph): %u, Find(edges[%u][1], graph): %u\n", i, Find(edges[i][0], graph), i, Find(edges[i][1], graph));
        if (Find(edges[i][0], graph) == Find(edges[i][1], graph)) {
            returnVal[0] = edges[i][0];
            returnVal[1] = edges[i][1];
            break;
        } else {
            Union(edges[i][0], edges[i][1], graph);
        }
        //printf("after: Find(edges[%u][0], graph): %u, Find(edges[%u][1], graph): %u\n", i, Find(edges[i][0], graph), i, Find(edges[i][1], graph));
    }

    free(graph);
    return returnVal;
}
```
