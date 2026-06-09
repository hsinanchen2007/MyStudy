1.层次遍历
2.反转结果
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** result = levelOrder(root, returnSize, returnColumnSizes);
    if (result == NULL) {
        return NULL;
    }
    int count = *returnSize;
    
    for (int i = 0 ; i < count / 2; ++i) {
        int *data = result[i];
        int volNum = (*returnColumnSizes)[i];
        result[i] = result[count - 1 - i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[count - 1 - i];
        result[count - 1 - i] = data;
        (*returnColumnSizes)[count - 1 - i] = volNum;
    }
    
    return result;
}
```
