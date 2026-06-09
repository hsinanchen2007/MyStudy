```c
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    if (!root)
    {
        *returnSize = 0;
        return 0;
    }
    // last 用来指向每层的最后一个结点
    int front = 0, rear = 0, last = 0, columnSizes = 0;
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode) * 1000);
    int **result = (int **)malloc(sizeof(int *) * 1000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    struct TreeNode *p = NULL;
    *returnSize = 0;
    queue[front++] = root;
    result[(*returnSize)] = (int *)malloc(sizeof(int) * (front - rear));
    while (front != rear)
    {
        p = queue[rear++];
        result[(*returnSize)][columnSizes] = p->val;
        columnSizes++;
        if (p->left != NULL)
        {
            queue[front++] = p->left;
        }
        if (p->right != NULL)
        {
            queue[front++] = p->right;
        }
        if (rear - 1 == last)
        {
            (*returnColumnSizes)[(*returnSize)] = columnSizes;
            (*returnSize)++;
            result[(*returnSize)] = (int *)malloc(sizeof(int) * (columnSizes * 2));
            last = front - 1;
            columnSizes = 0;
        }
    }
    return result;
}
```
