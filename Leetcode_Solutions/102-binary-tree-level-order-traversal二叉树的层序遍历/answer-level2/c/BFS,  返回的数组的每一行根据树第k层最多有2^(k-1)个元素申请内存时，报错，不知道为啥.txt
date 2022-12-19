/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 #include <math.h>
int GetTreeDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    int leftTreeDep = GetTreeDepth(root->left);
    int rightTreeDep = GetTreeDepth(root->right);

    return (leftTreeDep < rightTreeDep ? rightTreeDep + 1 : leftTreeDep + 1);

}
// BFS , k表示节点所在的层数
void IterationFunc(struct TreeNode* root, int k, int *rowIdx, int **arr) 
{
    if (root == NULL) {
        return ;
    }

    int pos = rowIdx[k];
    arr[k][pos] = root->val;
    rowIdx[k]++; //第k层数组索引加1

    IterationFunc(root->left, k+1, rowIdx, arr);
    IterationFunc(root->right, k+1, rowIdx, arr);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        returnColumnSizes = NULL;
        return NULL;
    }

    int treeDepth = GetTreeDepth(root);
    int **arr = (int **)malloc(sizeof(int *) * treeDepth);
    if (arr == NULL) {
        *returnSize = 0;
        returnColumnSizes = NULL;
        return NULL;
    }

    int i;
    int rowSize ;
    for (i = 0; i < treeDepth; i++) {
        rowSize = 1000; // 这里改成pow(2, i), 会报超出内存限制，没搞懂为什么
        //double x = 2.0;
        //rowSize = (int)pow(x, i); 
        arr[i] = (int *)malloc(sizeof(int) * rowSize);
        memset(arr[i], 0, sizeof(int) * rowSize);
    }

    int *rowIdx = (int *)malloc(sizeof(int) * treeDepth); // 记录arr[i]可以写入数字的位置
    memset(rowIdx, 0, sizeof(int) * treeDepth);

    IterationFunc(root, 0, rowIdx, arr);
    *returnSize = treeDepth;
    *returnColumnSizes = rowIdx;
    return arr;
}