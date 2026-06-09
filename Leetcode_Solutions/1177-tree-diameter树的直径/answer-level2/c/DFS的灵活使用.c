1、树的最大直径实际上实际只可能有两种情况，要么为子树的最大直径，要么从根节点到叶子节点的最大的非重复的两条边之和。
2、可以用递归来完成该题,递归每次返回两个值，一个值为该树的最大直径，另一个值为该树从根节点到叶子节点的最长距离。

```
int g_treeDiameter;
void printf_Matrices(int** pMatrices, int matricesSize)
{
    int i, j;
    for (i = 0; i < matricesSize; i++) {
        for (j = 0; j < matricesSize; j++) {
            printf("%d ", pMatrices[i][j]);
        }
        printf("\n");
    }
}

int dfs(short** pMatrices, int matricesSize, int flag, char* visited)
{
    visited[flag] = 1;
    int max1 = 0;
    int max2 = 0;
    int num;

    for (int j = 0; j < matricesSize; j++) {
        if ((1 == pMatrices[flag][j]) && (0 == visited[j])) {
            visited[j] = 1;
            num = dfs(pMatrices, matricesSize, j, visited);
            if(num>max1){
                max2 = max1;
                max1 = num;
            } else if(num>max2){
                max2 = num;
            }
        }
        //visited[j] = 0;
    }
    // 树的最大直径实际上实际只可能有两种情况，要么为子树的最大直径，要么从根节点到叶子节点的最大的非重复的两条边之和。
    g_treeDiameter = (g_treeDiameter < (max1+max2)) ? max1+max2 : g_treeDiameter;

    return max1+1; // 最大子树的边数
}

int treeDiameter(int** edges, int edgesSize, int* edgesColSize){
    int max_flag = 0;
    int i;
    short** pMatrices = NULL;
    g_treeDiameter = 0;

    for (i = 0; i < edgesSize; i++) {
        if (edges[i][0] < edges[i][1]) {
            max_flag = (max_flag < edges[i][1]) ? edges[i][1] : max_flag;
        } else { // 大于。题目限制edges[i][0] != edges[i][1]
            max_flag = (max_flag < edges[i][0]) ? edges[i][0] : max_flag;
        }
    }

    pMatrices = (short**)malloc(sizeof(short*)*(max_flag+1));
    if (NULL == pMatrices) {
        return 0;
    }

    for (i = 0; i <= max_flag; i++) {
        pMatrices[i] = (short*)malloc(sizeof(short)*(max_flag+1));
        if (NULL == pMatrices[i]) {
            return 0;
        }
        memset(pMatrices[i], 0, sizeof(short)*(max_flag+1));
    }

    for (i = 0; i < edgesSize; i++) {
        pMatrices[edges[i][0]][edges[i][1]] = 1;
        pMatrices[edges[i][1]][edges[i][0]] = 1;
    }
    //printf_Matrices(pMatrices, max_flag+1);
    char visited[(max_flag+1)];
    memset(visited, 0, sizeof(char)*(max_flag+1));
    dfs(pMatrices, max_flag+1, 0, visited);
    return g_treeDiameter;
}
```
