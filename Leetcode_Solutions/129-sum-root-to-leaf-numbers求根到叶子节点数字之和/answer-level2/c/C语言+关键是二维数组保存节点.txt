### 解题思路
此处撰写解题思路

关键是二维数组保存节点

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXCOL 1000
int g_col = 0;

void mySumNumbers(struct TreeNode* root, int **arr, int *temp, int *col, int perCol) 
{
    int i;
    if (root == NULL) {
        return;
    }

    temp[perCol++] = root->val;
    if (root->left == NULL && root->right == NULL) {
        col[g_col] = perCol;
        arr[g_col] = (int *)malloc(sizeof(int) * perCol);
        for (i = 0; i < perCol; i++) {
            arr[g_col][i] = temp[i];
        }
        g_col++;
    }

    mySumNumbers(root->left, arr, temp, col, perCol);
    mySumNumbers(root->right, arr, temp, col, perCol);
}

int sumNumbers(struct TreeNode* root){
    int **arr = NULL;   //记录从根节点到叶子节点的不同路径；
    int *temp = NULL;   //记录每一组数据；
    int *col = NULL;    //记录每一行有多少列
    int *perColSum = NULL;
    int i, j, res;

    arr = (int **)malloc(sizeof(int *) * MAXCOL);
    temp = (int *)malloc(sizeof(int) * MAXCOL);
    col = (int *)malloc(sizeof(int) * MAXCOL);
    g_col = 0;

    mySumNumbers(root, arr, temp, col, 0);
    perColSum = (int *)malloc(sizeof(int) * g_col);
    memset(perColSum, 0, sizeof(int) * g_col);
    res = 0;

    for (i = 0; i < g_col; i++) {
        for (j = 0; j < col[i]; j++) {
            perColSum[i]  = perColSum[i] * 10 + arr[i][j];
        }
    }

    for (i = 0; i < g_col; i++) {
        res += perColSum[i];
    }

    return res;
}

```