![image.png](https://pic.leetcode-cn.com/da62f1403105196a17a06e18f8e3834c2678ee4db815cffeecce59f19f5ca5fa-image.png)
```
#define COLNUM 2

int Cmp(const void *a, const void *b)
{
    return (*(int **)a)[1] - (*(int **)b)[1];
}

bool IsSame(int** edges, int edgesSize, int* edgesColSize, int num, int *visitedEdge, int *outIndex)
{
    int i;
    bool returnValue = false;
    for (i = 0; i < edgesSize; i++) {
        if (visitedEdge[i] == 0) {
            if (edges[i][0] == num) {
                *outIndex = edges[i][1];
                returnValue = true;
                visitedEdge[i] = 1;
                goto _END_;
            }
            if (edges[i][1] == num) {
                *outIndex = edges[i][0];
                returnValue = true;
                visitedEdge[i] = 1;
                goto _END_;
            }
        }
    }
    _END_:
    return returnValue;
}

void SubFuncDFS(int** edges, int edgesSize, int* edgesColSize, int index, int level, int *maxLevel, int *visitedEdge)
{
    int i;
    bool isSame = false;
    int outIndex = 0;
    level++;
    //printf("index: %d\n", index);
    if (level > *maxLevel) {
        *maxLevel = level;
    }
    
    for (i = 0; i < edgesSize; i++) {
        if (visitedEdge[i] == 0) {
            isSame = IsSame(edges, edgesSize, edgesColSize, index, visitedEdge, &outIndex);
            //printf("index: %d, outIndex: %d, isSame: %d, true: %d\n", index, outIndex, isSame, true);
            if (isSame == true) {
                SubFuncDFS(edges, edgesSize, edgesColSize, outIndex, level, maxLevel, visitedEdge);
            }
        }
    }
    return;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    int i;
    if ((edges == NULL) || (edgesSize == 0) || (edgesColSize == NULL) || (*edgesColSize == 0)) {
        *returnSize = n;        
        int *returnVal = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) {
            returnVal[i] = i;
        }
        return returnVal;
    }

    int level = 0;
    int maxLevel = 0;
    int noteLevel;
    int count = 1;
    int **visited = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        visited[i] = (int *)malloc(COLNUM * sizeof(int));
        memset(visited[i], 0, COLNUM * sizeof(int));
    }

    int *visitedEdge = (int *)malloc(edgesSize * sizeof(int));
    memset(visitedEdge, 0, edgesSize * sizeof(int));
    
    for (i = 0; i < n; i++) {
        maxLevel = 0;
        level = 0;
        SubFuncDFS(edges, edgesSize, edgesColSize, i, level, &maxLevel, visitedEdge);
        visited[i][0] = i;
        visited[i][1] = maxLevel;        
        //printf("i: %d, visited[i][0]: %d, visited[i][1]: %d\n", i, visited[i][0], visited[i][1]);
        memset(visitedEdge, 0, edgesSize * sizeof(int));
    }
    
    qsort(visited, edgesSize, sizeof(visited[0]), Cmp);

    noteLevel = visited[0][1];
    for (i = 1; i < n; i++) {
        if (noteLevel == visited[i][1]) {
            count++; 
        }
        else {
            break;
        }
    }
    
    *returnSize = count;        
    int *returnVal = (int *)malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        returnVal[i] = visited[i][0];
    }

    free(visitedEdge);
    for (i = 0; i < n; i++) {
        free(visited[i]);
    }
    free(visited);

    return returnVal;
}
```
