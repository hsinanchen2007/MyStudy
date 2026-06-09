### 解题思路
基于队列的BFS，由于C语言不支持动态数组，需要手动造轮子。

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
#define MAXSIZE 1000

struct Queue
{
    int front;   ///指向队列的头
    int rear;    ///指向队列的尾
    int size;    ///队列当前的大小
    struct TreeNode *node[MAXSIZE];
};

void initQueue(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    memset(queue->node, 0, sizeof(struct TreeNode *) * MAXSIZE);
}

int push(struct Queue *queue, struct TreeNode *node)
{
    if (NULL == queue || NULL == node)
        return 0;
    
    queue->rear = (queue->rear + 1) % MAXSIZE;   //// 如果超过队列深度，就从头开始
    queue->node[queue->rear] = node;
    queue->size ++;
    return 1;
}

//弹出front，并返回node
int pop(struct Queue *queue, struct TreeNode **node)
{
    if (NULL == queue || NULL == node || queue->size == 0)
        return 0;

    queue->front = (queue->front + 1) % MAXSIZE;
    *node = queue->node[queue->front];
    queue->size --;

    return 1;

}

int getTreeDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    
    int left = getTreeDepth(root->left);
    int right = getTreeDepth(root->right);
    return left > right ? left + 1 : right + 1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (NULL == root || NULL == returnSize || NULL == returnColumnSizes)
    {
        *returnSize = 0;
        *returnColumnSizes = (int *)malloc(sizeof(int));
        *returnColumnSizes[0] = 0;
        return NULL;
    }

    struct Queue q;
    initQueue(&q);
    push(&q, root);

    int deepth = getTreeDepth(root);
    int row = 0;
    *returnSize = deepth;
    int **res = (int **)malloc(sizeof(int *) * deepth);
    *returnColumnSizes = (int *)malloc(sizeof(int) * deepth); //表示动态列数的二维数组
    if (NULL == res || NULL == returnSize)
        return NULL;

    while(q.size != 0)
    {
        int levelSize = q.size;
        (*returnColumnSizes)[row] = levelSize;
        res[row] = (int *)malloc(sizeof(int) * levelSize);
        int col = 0;
        while(levelSize --)
        {
            struct TreeNode *node;
            pop(&q, &node);
            res[row][col] = node->val;
            if (node->left)
            {
                push(&q, node->left);
            }
            if (node->right)
            {
                push(&q, node->right);
            }
            col ++;
        }
        row ++;
    }

    return res;
}
```