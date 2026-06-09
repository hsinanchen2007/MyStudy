![image.png](https://pic.leetcode-cn.com/2888551f462be2d0698009bb90a8a21236d19514442ad87b12db93b6615988e1-image.png)


```
void getDeep(struct TreeNode* root,int tempDeep, int* returnSize)
{
    if (!root) return;
    if (tempDeep > * returnSize) {
        *returnSize = tempDeep;
    }
    if (root->left) {
        getDeep(root->left, tempDeep + 1,returnSize);
    }
    if (root->right) {
        getDeep(root->right, tempDeep + 1, returnSize);
    }
}
void getColumn(struct TreeNode* root, int** returnColumnSizes, int tempRow)
{
    if (!root) return;
    (*returnColumnSizes)[tempRow]++;
    getColumn(root->left, returnColumnSizes, tempRow + 1);
    getColumn(root->right, returnColumnSizes, tempRow + 1);
}

void track(struct TreeNode* root, int** returnColumnSizes, int **ret, int tempRow)
{
    if (!root) return;
    ret[tempRow][(*returnColumnSizes)[tempRow]++] = root->val;
    track(root->left, returnColumnSizes, ret, tempRow + 1);
    track(root->right, returnColumnSizes, ret, tempRow + 1);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int row = 0, i;
    int **ret;
    getDeep(root, 1, &row);
    ret = malloc(sizeof(int *) * row);
    *returnColumnSizes = malloc(sizeof(int) * row);
    for (i = 0; i < row; i++)
    {
        (*returnColumnSizes)[i] = 0;
    }
    getColumn(root, returnColumnSizes, 0);
    for (i = 0; i < row; i++)
    {
        ret[i] = malloc(sizeof(int) * (*returnColumnSizes)[i]);
        (*returnColumnSizes)[i] = 0;
    }
    track(root, returnColumnSizes, ret, 0);
    *returnSize = row;
    return ret;
}
```
