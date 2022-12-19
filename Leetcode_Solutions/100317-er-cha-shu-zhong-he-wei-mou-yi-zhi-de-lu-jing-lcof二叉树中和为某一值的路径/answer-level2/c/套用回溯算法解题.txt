知识点：
1、二维属组的申请与赋值；
2、回溯算法的套用。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs_(int **retArray, struct TreeNode* node, int sum, int curSum, int *tempAr, int curNum, int *returnSize, int *returnColumnSize)
{
    int count = 0;
    
    if (node->left == NULL && node->right == NULL) {
        printf("[FINAL]current val is %d and curSum is %d.\n", node->val, curSum);
        if (node->val + curSum == sum) {
            returnColumnSize[(*returnSize)] = curNum + 1;
            retArray[*returnSize] = (int *)malloc(sizeof(int) * (curNum + 1));
            for (count = 0; count < curNum; ) {
                retArray[*returnSize][count] = tempAr[count];
                count++;
            }
            retArray[*returnSize][count] = node->val;
            (*returnSize) = (*returnSize) + 1;
        }
        return;
    }

    if (node->left != NULL) {
        printf("[LEFT]current val is %d and curSum is %d.\n", node->val, curSum);
        tempAr[curNum] = node->val;
        dfs_(retArray, node->left, sum, (node->val + curSum), tempAr, curNum + 1, returnSize, returnColumnSize);
        //tempAr[curNum] = 0;
    }
    
    if (node->right != NULL) {
        printf("[RIGHT]current val is %d and curSum is %d.\n", node->val, curSum);
        tempAr[curNum] = node->val;
        dfs_(retArray, node->right, sum, (node->val + curSum), tempAr, curNum + 1, returnSize, returnColumnSize);
    }
    
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define LEN 0xffff
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
    int **retArray = (int **)malloc(sizeof(int *) * LEN);
    int *tempAr = (int *)malloc(sizeof(int) * LEN);

    if (root == NULL) {
        (*returnSize) = 0;
        return retArray;
    }
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * LEN);
    (*returnSize) = 0;
    
    
    dfs_(retArray, root, sum, 0, tempAr, 0, returnSize, *returnColumnSizes);
    return retArray;
}
```
