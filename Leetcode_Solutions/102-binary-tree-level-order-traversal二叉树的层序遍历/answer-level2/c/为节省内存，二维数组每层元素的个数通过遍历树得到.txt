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
// k表示节点所在的层数
void IterationFunc(struct TreeNode* root, int k, int *rowIdx, int **arr) 
{
    if (root == NULL) {
        return ;
    }

    int pos = rowIdx[k];
    arr[k][pos] = root->val;
    rowIdx[k]++;

    IterationFunc(root->left, k+1, rowIdx, arr);
    IterationFunc(root->right, k+1, rowIdx, arr);
}

//参考网友step的函数，计数每层的节点数
void CountTreeNode(struct TreeNode* root, int depth, int *nodecout)
{
    nodecout[depth] += 1;

    if ((root->left == NULL)&&(root->right == NULL)) {
        return;
    } 

    depth += 1;
    if (root->left != NULL) {
        CountTreeNode(root->left, depth, nodecout);
    }
    if (root->right != NULL) {
        CountTreeNode(root->right, depth, nodecout);
    }

    return;
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

    //初始化
    int *rowSizeArr = (int *)malloc(treeDepth * sizeof(int));
    int i;
    for (i=0; i<treeDepth; i++) {
        rowSizeArr[i] = 0;
    }
    CountTreeNode(root, 0, rowSizeArr);


    int rowSize ;
    for (i = 0; i < treeDepth; i++) {
        //参考网友step的方法，获得每一层的节点个数
        arr[i] = (int *)malloc(sizeof(int) * rowSizeArr[i]);
        memset(arr[i], 0, sizeof(int) * rowSizeArr[i]); 
    }

    int *rowIdx = (int *)malloc(sizeof(int) * treeDepth); // 记录arr[i]可以写入数字的位置
    memset(rowIdx, 0, sizeof(int) * treeDepth);

    IterationFunc(root, 0, rowIdx, arr);
    *returnSize = treeDepth;
    *returnColumnSizes = rowIdx; // rodIdx数组中各元素的值就是该元素所对应的在树中相应层上元素///的个数

    return arr;
}