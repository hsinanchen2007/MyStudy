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
int g_out[1000][1000] = {0};
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes[0] = 0;
        return NULL;
    }
    memset(g_out, 0, sizeof(g_out));
    struct TreeNode *pre[1000];
    struct TreeNode *aft[1000];
    g_out[0][0] = root->val;
    int preCnt = 1;
    int aftCnt = 0;
    int layer = 1;
    int record[1000];
    record[0] = 1;
    pre[0] = root;
    while (preCnt) {
        aftCnt = 0;
        for (int i = 0; i < preCnt; i++) {
            struct TreeNode *lftTree = pre[i]->left;
            struct TreeNode *rgtTree = pre[i]->right;
            if (lftTree) {
                aft[aftCnt] = lftTree;
                //printf("lft :g_out[%d][%d] = %d\n", layer, aftCnt, lftTree->val);
                g_out[layer][aftCnt] = lftTree->val;
                aftCnt++;
            }
            if (rgtTree) {
                aft[aftCnt] = rgtTree;
                //printf("rgt: g_out[%d][%d] = %d\n", layer, aftCnt, rgtTree->val);
                g_out[layer][aftCnt] = rgtTree->val;
                aftCnt++;
            }
        }
        preCnt = aftCnt;
        if (preCnt) {
            memcpy(pre, aft, aftCnt * sizeof(struct TreeNode *));
            record[layer] = aftCnt; 
            layer++;
        }   
    }
    *returnSize = layer;
    returnColumnSizes[0] = (int *)malloc(layer * sizeof(int));
    int **output = (int **)malloc(layer * sizeof(int *));
    for (int i = 0; i < *returnSize; i++) {
        returnColumnSizes[0][i] = record[i];
        output[i] = (int *)malloc(record[i] * sizeof(int));
        for (int j = 0; j < record[i]; j++) {
            output[i][j] = g_out[i][j];
        }
    }
    return output;
}
```
