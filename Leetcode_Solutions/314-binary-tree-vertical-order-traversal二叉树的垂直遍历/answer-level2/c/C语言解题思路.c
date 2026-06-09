### 解题思路
以根节点为Y坐标轴（坐标为0），其左节点坐标为-1，右节点坐标为1；前序遍历树，将各个节点的data和坐标记录下来；然后根据坐标降序排列（注意同一列输出时上层元素在前）。

### 代码

```c
#define         MY_TRUE     1
#define         MY_FALSE    0

typedef struct {
    int             data;
    int             x;
    int             layer;
}Data;

int         g_treeNum       = 0;
int         g_curNum        = 0;
Data        *g_data         = NULL;

void InitGlobal(void)
{
    g_treeNum               = 0;
    g_curNum                = 0;
    if (g_data == NULL) {
        free(g_data);
    }
    g_data                   = NULL;
}

void InitPara(void)
{
    if (g_data != NULL) {
        return;
    }

    if (g_treeNum == 0) {
        return;
    }

    g_data      = (Data *)malloc(sizeof(Data) * g_treeNum);
    if (g_data == NULL) {
        return;
    }
    memset(g_data, 0, sizeof(Data) * g_treeNum);
    return;
}

void GetTreeDataNum(struct TreeNode* root)
{
    if (root == NULL) {
        return;
    }

    g_treeNum++;

    if (root->left != NULL) {
        GetTreeDataNum(root->left);
    }

    if (root->right != NULL) {
        GetTreeDataNum(root->right);
    }
}

int IsTreeEmpty(void)
{
    if (g_treeNum == 0) {
        return MY_TRUE;
    }
    return MY_FALSE;
}

void BeforeSearch(struct TreeNode* root, int x, int layer) 
{
    if (root == NULL) {
        return;
    }

    /* 遍历根节点 */
    if (g_curNum >= g_treeNum) {
        return;
    }
    g_data[g_curNum].data    = root->val;
    g_data[g_curNum].x       = x;
    g_data[g_curNum].layer   = layer;
    g_curNum++;

    /* 遍历左节点 */
    if (root->left != NULL) {
        BeforeSearch(root->left, x - 1, layer + 1);
    }

    /* 编列右节点 */
    if (root->right != NULL) {
        BeforeSearch(root->right, x + 1, layer + 1);
    }
    return;
}


void SortData(void)
{
    Data            temp;

    for (int loopI = 0; loopI < g_treeNum - 1; loopI++) {
        for (int loopJ = 0; loopJ < g_treeNum - 1 - loopI; loopJ++) {
            if ((g_data[loopJ].x > g_data[loopJ + 1].x) ||
                ((g_data[loopJ].x == g_data[loopJ + 1].x) && (g_data[loopJ].layer > g_data[loopJ + 1].layer))){
                memcpy(&temp, &g_data[loopJ], sizeof(Data));
                memcpy(&g_data[loopJ], &g_data[loopJ + 1], sizeof(Data));
                memcpy(&g_data[loopJ + 1], &temp, sizeof(Data));
            }
        }
    }
}

int GetTypeNum(void)
{
    int     x       = g_data[0].x;
    int     count   = 1;

    for (int loop = 1; loop < g_treeNum; loop++) {
        if (x != g_data[loop].x) {
            count++;
            x       = g_data[loop].x;
        }
    }
    return count;
}

void StoreRslt(int **rslt, int *colNum)
{
    int         typeNum     = 0;
    int         curCount    = 0;
    int         curX        = g_data[0].x;
    
    rslt[typeNum]       = (int *)malloc(sizeof(int)*g_treeNum);
    if (rslt[typeNum] == NULL) {
        return;
    }
    rslt[typeNum][curCount] = g_data[0].data;
    curCount++;

    for (int loop = 1; loop < g_treeNum; loop++) {
        if (curX != g_data[loop].x) {
            colNum[typeNum] = curCount;
            typeNum++;
            curCount    = 0;
            rslt[typeNum]       = (int *)malloc(sizeof(int)*g_treeNum);
            if (rslt[typeNum] == NULL) {
                return;
            }
            rslt[typeNum][curCount] = g_data[loop].data;
            curCount++;
            curX        = g_data[loop].x;

        } else {
            rslt[typeNum][curCount] = g_data[loop].data;
            curCount++;
        }
    }

    colNum[typeNum] = curCount;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** verticalOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int             **rslt          = NULL;
    int             *colNum         = NULL;

    InitGlobal();
    GetTreeDataNum(root);

    if (returnSize == NULL) {
        return NULL;
    }

    *returnSize     = g_treeNum;

    if (IsTreeEmpty() == MY_TRUE) {
        g_treeNum       = 1;
    }
    rslt        = (int **)malloc(sizeof(int *) * g_treeNum);
    if (rslt == NULL) {
        return NULL;
    }

    if ((returnColumnSizes == NULL) || (root == NULL)) {
        return rslt;
    }

    if (rslt != NULL) {
        free(rslt);
    }

    InitPara();
    BeforeSearch(root, 0, 0);
    SortData();
    *returnSize = GetTypeNum();

    rslt        = (int **)malloc(sizeof(int *) * (*returnSize));
    if (rslt == NULL) {
        return NULL;
    }

    colNum      = (int *)malloc(sizeof(int) * (*returnSize));
    if (colNum == NULL) {
        *returnSize     = 0;
        return rslt;
    }

    StoreRslt(rslt, colNum);

    *returnColumnSizes  = colNum;

    InitGlobal();
    return rslt;
}
```