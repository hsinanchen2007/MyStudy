```
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
int tmp[1000] = {0};
void DFS(struct TreeNode* root, int sum, int** res, int *rows, int *cols, int depth)
{
    if (root == NULL) {
        return;
    }
    tmp[depth] = root->val;
    //printf("tmp[%d]=%d\n", depth, tmp[depth]);
    depth++;
    sum -= root->val;
    //printf("sum=%d\n", sum);
    if (root->left == NULL && root->right == NULL) {
        if (sum == 0) {
            //printf("copy\n");
            cols[*rows] = depth;
            //printf("cols[%d]=%d\n", *rows, cols[*rows]);
            res[*rows] = (int *)malloc(sizeof(int) * depth);
            memcpy(res[*rows], tmp, depth * sizeof(int));
            //for (int i =0; i < depth; i++) {
                //printf("res[%d][%d]=%d\n", *rows, i, res[*rows][i]);
            //}
            
            (*rows)++;
        }
        return;
    }
    DFS(root->left, sum, res, rows, cols, depth);
    DFS(root->right, sum, res, rows, cols, depth);

}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int **res= (int **)malloc(sizeof(int *) * 1000);
    int rows = 0;
    int cols[1000] = {0};
    
    * returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    DFS(root, sum, res, &rows, cols, 0);

    *returnSize = rows;
    for (int i = 0; i < *returnSize; i++) {
        returnColumnSizes[0][i] = cols[i];
    }
    return res;
}
```
