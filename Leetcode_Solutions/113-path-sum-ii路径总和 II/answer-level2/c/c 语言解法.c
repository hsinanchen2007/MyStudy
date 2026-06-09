int retPath[1000][1000] = {0}; // 记录路径
int size = 0; // 记录有多少条路径
int sizeCal[1000] = {0}; // 记录每条路径有多少val

int stack[1000] = {0};
int top = 0;

void dfs(struct TreeNode *node, int sum, int calValue) {
    if (node == NULL) {  
        return;
    }

    calValue += node->val;
    stack[top] = node->val;
    top++;
    
    if ((node->left == NULL) && (node->right == NULL) && (sum == calValue)) {
        
        for (int i = 0; i < top; i++) {
            retPath[size][i] = stack[i];
        }
        sizeCal[size] = top;
        size++;
        top--;
        return;
    }

    if ((node->left == NULL) && (node->right == NULL) && (sum != calValue)) {
        top--;
        return;
    }

    dfs(node->left, sum, calValue);
    dfs(node->right, sum, calValue);
    top--;

}
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
    int calValue = 0; // 计算总和
    int *columnSizes = NULL;
    
    // 初始化
    size = 0; 
    memset(sizeCal, 0, sizeof(int));
    memset(stack, 0, sizeof(int));
    top = 0;

    dfs(root, sum, calValue);

    *returnSize = size;
    columnSizes = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        columnSizes[i] = sizeCal[i]; 
    }

    *returnColumnSizes = columnSizes;
    
    int **retAttr = NULL;
    retAttr = (int **)malloc(sizeof(int*) * size);
    
    for (int i = 0; i < size; i++) {
        *(retAttr+i) = (int *)malloc(sizeof(int) * sizeCal[i]); 
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            retAttr[i][j] = retPath[i][j];
        }
    }

    return retAttr;
}
