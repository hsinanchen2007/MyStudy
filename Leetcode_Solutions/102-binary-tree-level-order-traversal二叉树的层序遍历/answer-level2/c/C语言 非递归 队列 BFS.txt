# C语言 非递归 队列 BFS
```reasonml
#define MAX_SIZE 1000

typedef struct {
        int front;
        int rear;
        int size;
        struct TreeNode* data[MAX_SIZE];
} Queue;

void Init(Queue *q)
{
        q->front = -1;
        q->rear = -1;
        q->size = 0;
        memset(q->data, 0, sizeof(struct TreeNode*) * MAX_SIZE);
}

int Push(Queue *q, struct TreeNode* node)
{
        assert(q && node && q->size != MAX_SIZE);
        if (q == NULL || node == NULL || q->size == MAX_SIZE)
                return -1;

        q->rear++;
        q->rear %= MAX_SIZE;
        q->data[q->rear] = node;
        q->size++;
        return 0;
}

int Pop(Queue *q, struct TreeNode** node)
{
        assert(q && node && q->size != 0);
        if (q == NULL || node == NULL || q->size == 0)
                return -1;
        q->front++;
        q->front %= MAX_SIZE;
        *node = q->data[q->front];
        q->size--;
        return 0;
}

int GetTreeDepth(const struct TreeNode* root)
{
        if (root == NULL)
                return 0;

        int left = GetTreeDepth(root->left);
        int right = GetTreeDepth(root->right);

        return left > right ? left + 1 : right + 1;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
        if (root == NULL || returnSize == NULL || returnColumnSizes == NULL) {
            *returnSize = 0;
            *returnColumnSizes = (int *)malloc(sizeof(int) * 1);
            (*returnColumnSizes)[0] = 0;                
            return NULL;
        }
            
        Queue q;
        Init(&q);
        Push(&q, root);

        int depth = GetTreeDepth(root);
        *returnSize = depth;
        int **matrix = (int **)malloc(sizeof(int *) * depth);
        *returnColumnSizes = (int *)malloc(sizeof(int) * depth);
        if (matrix == NULL || returnColumnSizes == NULL)
                return NULL;

        int cur_depth = 0;
        while(q.size != 0) {
                int level_size = q.size;
                /* create raw */
                (*returnColumnSizes)[cur_depth] = level_size;
                matrix[cur_depth] = (int *)malloc(sizeof(int) * level_size);
                int cur = 0;
                while (level_size--) {
                        struct TreeNode* node;
                        Pop(&q, &node);
                        /* add node->val to res */
                        matrix[cur_depth][cur] = node->val;

                        if (node->left)
                                Push(&q, node->left);
                        if (node->right)
                                Push(&q, node->right);
                        cur++;
                }
                cur_depth++;
        }
        return matrix;
}
```
