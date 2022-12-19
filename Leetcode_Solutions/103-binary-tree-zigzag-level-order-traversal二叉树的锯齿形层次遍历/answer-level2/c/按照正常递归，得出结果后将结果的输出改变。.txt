### 解题思路
按照正常递归，得出结果后将结果的输出改变。

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
int getDeep(struct TreeNode* root, int curDeep) {
    if (root == NULL){
        return curDeep;
    }
    int right = getDeep(root->right, curDeep + 1);
    int left = getDeep(root->left, curDeep + 1);
    return (right > left ? right : left);
}

void getRes(struct TreeNode* root, int** returnColumnSizes, int** res, int curDeep) {
    if (root == NULL) {
        return;
    }
    res[curDeep][returnColumnSizes[0][curDeep]] = root->val;
    returnColumnSizes[0][curDeep]++;
    getRes(root->left, returnColumnSizes, res, curDeep + 1);
    getRes(root->right, returnColumnSizes, res, curDeep + 1);
    return;
}
#define MAX 0xff
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        **returnColumnSizes = 0;
        return NULL;
    }
    int deep = getDeep(root,0);
    int **res = (int **)malloc(sizeof(int *) * deep);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * deep);
    for (int i = 0; i < deep; i++) {
        res[i] = (int *)malloc(sizeof(int) * MAX);
        returnColumnSizes[0][i] = 0;
    }
    getRes(root, returnColumnSizes, res, 0);
    for (int i = 0; i < deep; i++) {
        if (i % 2 != 0) {
            for (int j = 0; j < returnColumnSizes[0][i] / 2; j++){
                int temp = res[i][j];
                res[i][j] = res[i][returnColumnSizes[0][i] - j - 1];
                res[i][returnColumnSizes[0][i] - j - 1] = temp;
            }
        }
    }
    *returnSize = deep;
    return res;
}
```