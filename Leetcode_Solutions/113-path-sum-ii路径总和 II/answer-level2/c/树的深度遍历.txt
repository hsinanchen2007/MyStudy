### 解题思路
树的深度遍历，记录沿途的每个节点，最后找到符合要求的路径添加到返回数组中。

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
void DFS(struct TreeNode* node, int sum, int** arr, int *returnSize, int curIndex, int *tmpArr,int** returnColumnSizes)
{
    int ret = 0;
    if (node == NULL) {
        return;
    } 

    tmpArr[curIndex] = node->val;
    curIndex++;
    if (node->val == sum && node->left == NULL && node->right == NULL) {
        //printf("find ");
        arr[*returnSize] = (int*)malloc(sizeof(int)*curIndex);
        (*returnColumnSizes)[*returnSize] = curIndex;
        for (int i = 0; i < curIndex; i++) {
            arr[*returnSize][i] = tmpArr[i];
            //printf("%d ",arr[*returnSize][i]);
        }
        (*returnSize)++;
       // printf("find %d size %d arrSize %d\r\n", node->val, *returnSize,(*returnColumnSizes)[(*returnSize)-1]);
        return;
    }
    DFS(node->left, sum - node->val, arr, returnSize, curIndex, tmpArr, returnColumnSizes);

    DFS(node->right, sum - node->val, arr, returnSize, curIndex, tmpArr, returnColumnSizes);
    return;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int **retArr;
    int curIndex = 0;
    int tmpArr[10000] = {0};
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    retArr = (int **)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    memset((*returnColumnSizes), 0, sizeof(int) * 10000);

    DFS(root, sum, retArr, returnSize,curIndex,tmpArr,returnColumnSizes);

    return retArr;
}
```