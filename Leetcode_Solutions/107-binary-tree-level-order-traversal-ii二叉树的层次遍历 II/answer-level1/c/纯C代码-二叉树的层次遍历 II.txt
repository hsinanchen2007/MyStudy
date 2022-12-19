### 解题思路
此处撰写解题思路

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
#define DEEP_MAX 800
#define COLUMN_SIZE 2000
int setData(struct TreeNode *root, int ***data, int deep, int **returnColumnSizes){
    int deep1 = deep + 1;
    int deep2 = deep + 1;

    if (root == NULL){
        return deep;
    }
    if ((*data)[deep] == NULL){
        (*data)[deep] = (int *)calloc(1, COLUMN_SIZE*sizeof(int));
    }

    (*data)[deep][(*returnColumnSizes)[deep]++] = root->val;

    if (root->left != NULL){
        deep1 = setData(root->left, data, deep1, returnColumnSizes);
    }
    if (root->right != NULL){
        deep2 = setData(root->right, data, deep2, returnColumnSizes);
    }

    return deep1>deep2 ? deep1:deep2;
 }
 
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **data = (int **)calloc(1, DEEP_MAX * sizeof(int *));
    *returnColumnSizes = (int *)calloc(1, DEEP_MAX * sizeof(int));
    int *tmpData = NULL;
    int tmpLen = 0; 
    int tmp;
    int i = 0;

    //按自顶向下层次遍历，把数据存入二维数组data，并返回二叉树深度。
    *returnSize = setData(root, &data, 0, returnColumnSizes);

    //把二维数组data的数据上下翻转，即为自底向上的层次遍历
    for (i = 0; i < (*returnSize)/2; i++){
        tmp = (*returnSize) - 1 - i;

        tmpData = data[i];
        data[i] = data[tmp];
        data[tmp] = tmpData;

        tmpLen = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[tmp];
        (*returnColumnSizes)[tmp] = tmpLen;
    }

    return data;
}
```