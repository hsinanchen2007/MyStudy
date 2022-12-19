矩阵或链式存储图，利用节点的度概念，每层遍历删除度为1的节点，注意删除度为1的节点时，需要判断这个节点所在边的对端节点的度不为1，如果对端为1，这不能删除，这是这两个节点均为有效解，该题解个个数范围，可能是1个，可能是2个。


```
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    short *map = malloc(sizeof(short) * n * n);
    int *retEdges = malloc(sizeof(int) * n);
    char *flag = malloc(sizeof(char) * n);
    char *tmpflag = malloc(sizeof(char) * n);
    short *alldu = malloc(sizeof(short) * n);
    short *tmpalldu = malloc(sizeof(short) * n);
    int bcontinue = 1;
    int du = 0;
    int index = 0;
    memset(map, 0 , sizeof(short) * n * n);
    memset(flag, 0 , sizeof(char) * n);
    memset(tmpflag, 0 , sizeof(char) * n);
    memset(alldu, 0 , sizeof(short) * n);
    memset(tmpalldu, 0 , sizeof(short) * n);
    
    for (int i = 0; i < edgesSize; ++i) {
        map[edges[i][0] * n + edges[i][1]] = 1;
        map[edges[i][1] * n + edges[i][0]] = 1;
        alldu[edges[i][0]]++;
        alldu[edges[i][1]]++;
    }
    memcpy(tmpalldu, alldu, sizeof(short) * n);
    while (bcontinue) {
        bcontinue = 0;
        for (int i = 0; i < n; ++i) {
            if (flag[i] == 1 || alldu[i] != 1)
                continue;
            du = 0;
            for (int j = 0; j < n; ++j) {
                if (flag[j] == 1)
                    continue;
                if (map[i * n + j] == 1) {
                    index = j;
                    break;
                }
            }
            
            if (alldu[index] != 1) {
                tmpflag[i] = 1;
                tmpalldu[index]--;
                bcontinue = 1;
            }
        }
        memcpy(flag, tmpflag, sizeof(char) * n);
        memcpy(alldu, tmpalldu, sizeof(short) * n);
    }
    
    *returnSize = 0;
    for (int i = 0; i < n; ++i) {
        if(flag[i] == 0) {
            retEdges[*returnSize] = i;
            *returnSize += 1;
        }
    }

    return retEdges;
}


```
