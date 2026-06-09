```
#define NAME_LEN_MAX    32
typedef struct nodesInfo {
    char name[NAME_LEN_MAX];
}NODESINFO;

int GetNode(char *inputNode, NODESINFO *ndIf, int nodesNum) {
    for (int i = 0; i < nodesNum; i++) {
        if (strncmp(ndIf[i].name, inputNode, strlen(inputNode)) == 0) {
            return i;
        }
    }
    return -1;
}

bool GetretNode(int inputNode, int *retNodes, int retNodesNum) {
    for (int i = 0; i < retNodesNum; i++) {
        if (inputNode == retNodes[i]) {
            return true;
        }
    }
    return false;
}

NODESINFO *GetNodesInfo(char ***equations, int equationsSize, int *nodesNum) {
    NODESINFO *ndIf = NULL;
    int nodesNumMax = equationsSize * 2;
    int nodesId = 0;
    int i, j;

    ndIf = (NODESINFO *)malloc(nodesNumMax * sizeof(NODESINFO));
    memset(ndIf, '\0', nodesNumMax * sizeof(NODESINFO));
    for (i = 0; i < equationsSize; i++) {
        for (j = 0; j < 2; j++) {
            if (GetNode(equations[i][j], ndIf, nodesId) < 0) {
                strncpy(ndIf[nodesId].name, equations[i][j], strlen(equations[i][j]));
                nodesId++;
            }
        }
    }
    *nodesNum = nodesId;
    return ndIf;
}

void FreeNodesInfo(NODESINFO *nodesInfo) {
    free(nodesInfo);
}

double **GetSidesInfo(char *** equations, int equationsSize, double* values, NODESINFO *ndIf, int nodesNum) {
    double **sdIf = NULL;
    unsigned int srcNode = 0;
    unsigned int dstNode = 0;
    int i;

    sdIf = (double **)malloc(nodesNum * sizeof(double *));
    for (i = 0; i < nodesNum; i++) {
        sdIf[i] = (double *)malloc(nodesNum * sizeof(double));
        memset(sdIf[i], 0, nodesNum * sizeof(double));
    }

    for (i = 0; i < equationsSize; i++) {
        srcNode = GetNode(equations[i][0], ndIf, nodesNum);
        dstNode = GetNode(equations[i][1], ndIf, nodesNum);
        if ((srcNode != -1) && (dstNode != -1)) {
            sdIf[srcNode][dstNode] = values[i];
            sdIf[dstNode][srcNode] = 1 / values[i];
        }
    }
    return sdIf;
}

void FreeSidesInfo(double **sdIf, int equationsSize) {
    for (int i = 0; i < equationsSize; i++) {
        free(sdIf[i]);
    }
    free(sdIf);
    return;
}


double CalcResult(int *retNodes, int retNodesNum, double **sdIf, unsigned int nodesNum, unsigned int srcId, unsigned int dstId) {
    int i, j;
    if ((srcId == -1) || (dstId == -1)) {
        return -1.0;
    }
    if (srcId == dstId) {
        return 1.0;
    }
    if (sdIf[srcId][dstId] > 0) {
        return sdIf[srcId][dstId];
    }else {
        for (i = 0; i < nodesNum; i++) {
            if (GetretNode(i, retNodes, retNodesNum) == true) {
                continue;
            }
            if (sdIf[srcId][i] > 0) {
                retNodes[retNodesNum++] = i;
                double ret = CalcResult(retNodes, retNodesNum, sdIf, nodesNum, i, dstId);
                if (ret > 0) {
                    return ret * sdIf[srcId][i];
                }else {
                    continue;
                }
            }
        }
    }
    return -1.0;
}


double* GetResult(char *** queries, int queriesSize, int* returnSize, NODESINFO *ndIf, int nodesNum, double **sdIf){
    double *result = NULL;
    int *queue = NULL;
    int srcNode = 0;
    int dstNode = 0;
    int i, j;

    result = (double *)malloc(queriesSize * sizeof(double));
    memset(result, 0, queriesSize * sizeof(double));
    queue = (int *)malloc(nodesNum * sizeof(int));
    memset(queue, -1, nodesNum *sizeof(int));
    for (i = 0; i < queriesSize; i++) {
        int srcNode = GetNode(queries[i][0], ndIf, nodesNum);
        int dstNode = GetNode(queries[i][1], ndIf, nodesNum);
        result[i] = CalcResult(queue, 0, sdIf, nodesNum, srcNode, dstNode);
    }
    *returnSize = i;
    return result;
}

double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize){
    NODESINFO *ndIf = NULL;
    int nodesNum = 0;

    double **sdIf = NULL;
    double *retValues = NULL;

    // 存储nodes,获取nodes索引id
    ndIf = GetNodesInfo(equations, equationsSize, &nodesNum);
    // 根据nodesid存储sides
    sdIf = GetSidesInfo(equations, equationsSize, values, ndIf, nodesNum);
    // 获取问题节点
    retValues = GetResult(queries, queriesSize, returnSize, ndIf, nodesNum, sdIf);
    FreeNodesInfo(ndIf);
    FreeSidesInfo(sdIf, equationsSize);

    return retValues;
}
```
