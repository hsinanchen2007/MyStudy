### 解题思路
此处撰写解题思路
回溯+剪枝吧，比较简单，边界条件要考虑好，还有就是是从根到叶节点；
从数组构造树还是比较难的，嗯，需要注意下
中序遍历构造树：

### 代码

```c
#define N_MAX 1000
int g_stack[N_MAX] = {0};
int g_top = -1;
void dfs(struct TreeNode* root, int sum, int curSum, int **result, int* returnSize, int* columnSizes)
{
    /* 结束条件 */
    if (curSum == sum && root->left == NULL && root->right == NULL) {
        columnSizes[*returnSize] = g_top + 1;
        result[*returnSize] = (int *)malloc(columnSizes[*returnSize] * sizeof(int));        
        for (int i = 0; i <= g_top; i++) {
            result[*returnSize][i] = g_stack[i];
        }
        *returnSize += 1;        
        return;
    }
    /* 遍历各种条件 */
    if (root->left != NULL) {
        curSum += root->left->val;
        g_stack[++g_top] = root->left->val;
        dfs(root->left, sum, curSum, result, returnSize, columnSizes);
        g_stack[g_top] = 0;
        g_top--;
        curSum -= root->left->val;        
    }
    if (root->right != NULL) {
        curSum += root->right->val;
        g_stack[++g_top] = root->right->val;            
        dfs(root->right, sum, curSum, result, returnSize, columnSizes);
        g_stack[g_top] = 0;
        g_top--;          
        curSum -= root->right->val;   
    }
    return;
}


int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    if (root == NULL || returnSize == NULL || returnColumnSizes == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(g_stack, 0, sizeof(g_stack));
    g_top = -1;
    int **result = (int **)malloc(N_MAX * sizeof(int *));
    memset(result, 0, N_MAX * sizeof(int *));
    int *columnSizes = (int *)malloc(N_MAX * sizeof(int));
    int curSum = root->val;
    int resultSize = 0;
    g_stack[++g_top] = root->val;
    dfs(root, sum, curSum, result, &resultSize, columnSizes);
    *returnColumnSizes = columnSizes;
    *returnSize = resultSize;
    return result;
}

struct TreeNode* BuildTree(int *nodeArray, int num)
{
    if (nodeArray == NULL && num == 0) {
        return NULL;
    }
    struct TreeNode* queue[N_MAX] = {NULL};
    int head = 0;
    int tail = -1;
    struct TreeNode* tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    tree->val = nodeArray[0];
    tree->left = NULL;
    tree->right = NULL;
    int index = 0;
    queue[++tail] = tree;
    while (head <= tail) {
        struct TreeNode *curNode = queue[head++];
        if (++index < num) {
            if (nodeArray[index] == 9999) {
                curNode->left = NULL;
            } else {
                curNode->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                curNode->left->val = nodeArray[index];
                curNode->left->left = NULL;
                curNode->left->right = NULL;
                queue[++tail] = curNode->left; 
            }
        }
        if (++index < num) {
            if (nodeArray[index] == 9999) {
                curNode->right = NULL;
            } else {
                curNode->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                curNode->right->val = nodeArray[index];
                curNode->right->left = NULL;
                curNode->right->right = NULL;
                queue[++tail] = curNode->right;
            }
        }              
    }    
    return tree;
}
```