### 解题思路
此处撰写解题思路

本题的关键点在于（1）识别到所有从根节点到叶子节点的所有路径（2）怎么保存寻到的路径？


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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define ARRROW 1000

int g_col = 0;

bool dfs(struct TreeNode* root, int sum, int total, int **arr, int** returnColumnSizes, int* temp, int num)
{
    int i;
    bool left, right;

    if (root == NULL) {
        return false;
    }

    total += root->val;
    /* 如果找到一条路径的和为给定值，则记录此条路径：从根节点到叶子节点 */
    if (root->left == NULL && root->right == NULL) {
        if (total == sum) {
            temp[num++] = root->val;
            (*returnColumnSizes)[g_col] = num;
            arr[g_col] = (int *)malloc(sizeof(int) * num);
            for (i = 0; i < num; i++) {
                arr[g_col][i] = temp[i];
            }
            g_col++;
            return true;
        }
        return false;
    }

    /* 如果还没有到根节点 */
    temp[num] = root->val;
    num++;

    left = dfs(root->left, sum, total, arr, returnColumnSizes, temp, num);
    right = dfs(root->right, sum, total, arr, returnColumnSizes, temp, num);

    /* 注意：这里必须先求出左再求出右，然后返回二者的或值，否则可能造成只求了左就已经返回了 */
    return left || right;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int num = 0; //记录当前行元素的个数
    int total = 0; //记录当前路径的和
    int i;
    int **arr = (int **)malloc(sizeof(int *) * ARRROW); //最后需要返回的路径
    int *temp = (int *)malloc(sizeof(int) * ARRROW); //用于辅助记录从根节点到叶子结点的结点值

    (*returnColumnSizes) = (int *)malloc(sizeof(int) * ARRROW);
    *returnSize = 0;
    g_col = 0;

    if (dfs(root, sum, total, arr, returnColumnSizes, temp, num)) {
        *returnSize = g_col;
        return arr;
    } else {
        /* 如果不符合条件，需要将申请的内存释放掉 */
        free(temp);
        for (i = 0; i < g_col; i++) {
            free(arr[i]);
        }
        free(arr);
        return NULL;
    }
}

```