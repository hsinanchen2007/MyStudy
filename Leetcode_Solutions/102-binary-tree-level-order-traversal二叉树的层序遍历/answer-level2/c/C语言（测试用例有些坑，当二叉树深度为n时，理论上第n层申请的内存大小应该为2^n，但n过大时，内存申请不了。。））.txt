#define MAX_DEPTH 1000

void orderLeaf(struct TreeNode* root, int depth, int* returnSize, int* ColumnSizes, int** result){
    if ((NULL == root) || 
        (NULL == returnSize) || 
        (NULL == ColumnSizes) || 
        (NULL == result) ){
        return;
    }
    if (depth >= MAX_DEPTH){
        return;
    }
    
    result[depth][ColumnSizes[depth]] = root->val;
    ColumnSizes[depth]++;
    if (depth >= *returnSize){
        *returnSize = depth +1;
    }
    
    orderLeaf(root->left, (depth + 1), returnSize, ColumnSizes, result);
    orderLeaf(root->right, (depth + 1), returnSize, ColumnSizes, result);
    
    return;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = 0;
    int *array = NULL;
    int *size = NULL;
    int **result = NULL;
    
    if (NULL == returnSize){
        return NULL;
    }
    *returnSize = 0;
    
    /* 返回数组申请内存 */
    result = (int **)malloc(sizeof(int *) * MAX_DEPTH);
    if (NULL == returnSize){
        return NULL;
    }
    memset(result, 0, (sizeof(int *) * MAX_DEPTH));
    
    /* returnColumnSizes申请内存 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_DEPTH);
    if (NULL == *returnColumnSizes){
        free(result);
        return NULL;
    }
    memset(*returnColumnSizes, 0, (sizeof(int) * MAX_DEPTH));

    /* 为每行申请一个内存 */
    for (depth = 0; depth < MAX_DEPTH; depth++){
        result[depth] = (int *)malloc(sizeof(int) * 500);
        if (NULL == result[depth]){
            for (; depth < 0; depth--){
                free(result[depth]);
            }
            free(result);
            free(returnColumnSizes);
            return NULL;
        }
        memset(result[depth], 0, (sizeof(int) * 500));
    }
    
    /* returnColumnSizes填充数据 */
    if (NULL != root){
        depth = 0;
        orderLeaf(root, depth, returnSize, *returnColumnSizes, result);
    }
    
    return result;
}