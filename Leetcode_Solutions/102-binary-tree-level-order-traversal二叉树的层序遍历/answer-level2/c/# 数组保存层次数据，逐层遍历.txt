# 数组保存层次数据，逐层遍历
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
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    const int max = 1000;
    *returnSize = 0;
    int **returnArry = (int **)malloc(max * sizeof(int *));
    int *columnSizes = (int *)malloc(max * sizeof(int));
    memset(columnSizes, 0, max * sizeof(int));
    
    struct TreeNode **firstTreeNode = (struct TreeNode **)malloc(max * sizeof(struct TreeNode *));
    memset(firstTreeNode, 0, max * sizeof(struct TreeNode *));
    struct TreeNode **lastTreeNode = (struct TreeNode **)malloc(max * sizeof(struct TreeNode *));
    memset(lastTreeNode, 0, max * sizeof(struct TreeNode *));
    
    firstTreeNode[0] = root;
    while(root != NULL) { 
        int firstIndex = 0;
        int LastIndex = 0;
        returnArry[*returnSize] = (int *)malloc(1000 * sizeof(int));
        while(firstTreeNode[firstIndex] != NULL) {
            returnArry[*returnSize][columnSizes[*returnSize]++] = firstTreeNode[firstIndex]->val;
            if (firstTreeNode[firstIndex]->left != NULL) {
                lastTreeNode[LastIndex++] = firstTreeNode[firstIndex]->left;
            }
            if (firstTreeNode[firstIndex]->right != NULL) {
                lastTreeNode[LastIndex++] = firstTreeNode[firstIndex]->right;
            }
            firstIndex++;
        }
        *returnSize = *returnSize + 1;/*leav计数*/
        if (LastIndex == 0) {
            break;
        }
        memcpy(firstTreeNode, lastTreeNode, 1000 * sizeof(struct TreeNode *));
        memset(lastTreeNode, 0, 1000 * sizeof(struct TreeNode *));
    }
    *returnColumnSizes = columnSizes;
    return returnArry;
}
```
