```
typedef struct {
    int floor;
    int val;
    struct TreeNode *root;
}QueueNode;


int  GetDepth(struct TreeNode* root, int *nodeNum)
{
    if (root == NULL) {
        return 0;
    }

    (*nodeNum)++;
    int left = GetDepth(root->left, nodeNum);
    int right = GetDepth(root->right, nodeNum);

    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

QueueNode *g_queue = NULL;
int g_front;
int g_tail;

int InitQueue(int queueSize) 
{
    g_front = 0;
    g_tail = 0;
    g_queue = (QueueNode *)malloc(sizeof(QueueNode) * queueSize);
    if (g_queue == NULL) {
        return -1;
    }
    (void)memset(g_queue, 0, sizeof(QueueNode) * queueSize);

    return 0;
}

void DestroyQueue()
{
    if (g_queue != NULL) {
        free(g_queue);
        g_queue = NULL;
    }
}

int GetQueueSize()
{
    return g_tail - g_front;
}

void Enqueue(int floor, int val, struct TreeNode *root)
{
    g_queue[g_tail].floor = floor;
    g_queue[g_tail].val = val;
    g_queue[g_tail].root = root;
    g_tail++;
}

void Dequeue(QueueNode *node)
{
    node->floor = g_queue[g_front].floor;
    node->val = g_queue[g_front].val;
    node->root = g_queue[g_front].root;
    g_front++;
}

int InitReturnArray(int ***returnArray, int** returnColumnSizes, int depth, int queueSize)
{
    int i;
    int ret;

    *returnArray = (int **)malloc(sizeof(int *) * depth);
    if (*returnArray == NULL) {
        return -1;
    }
    (void)memset(*returnArray, 0, sizeof(int *) * depth);

    ret = 0;

    
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * depth);
    if (returnColumnSizes[0] == NULL) {
        free(*returnArray);
        return -1;
    }
    (void)memset(returnColumnSizes[0], 0, sizeof(int) * depth);

    for (i = 0; i < depth; i++) {
        (*returnArray)[i] = (int *)malloc(sizeof(int) * queueSize);
        if ((*returnArray)[i] == NULL) {
            ret = -1;
            break;
        }
        (void)memset((*returnArray)[i], 0, sizeof(int) * queueSize);
    }

    if (ret == -1) {
        for (int j = 0; j < i; j++) {
            if ((*returnArray)[j] != NULL) {
                free((*returnArray)[j]);
            }

        }

        free(*returnArray);
        free(returnColumnSizes[0]);
        return -1;
    }

    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int queueSize = 0;
    /* 遍历获取树的深度和节点数，作为queue的最大空间 */
    int depth = GetDepth(root, &queueSize);
    if (depth == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    QueueNode tempNode;

    int ret = InitQueue(queueSize + 1);
    if (ret != 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = depth;
    int **returnArray = NULL;

    /* 初始化返回的数组空间 */
    ret = InitReturnArray(&returnArray, returnColumnSizes, depth, queueSize);
    if (ret != 0) {
        DestroyQueue();
        *returnSize = 0;
        return NULL;
    }


    Enqueue(0, root->val, root);
    (void)memset(&tempNode, 0, sizeof(tempNode));

    /* BFS算法依次获取每层数据 */
    while (GetQueueSize() != 0) {
        Dequeue(&tempNode);
        returnArray[tempNode.floor][returnColumnSizes[0][tempNode.floor]] = tempNode.val;
        returnColumnSizes[0][tempNode.floor] += 1;

        if (tempNode.root->left != NULL) {
            Enqueue(tempNode.floor + 1, tempNode.root->left->val, tempNode.root->left);
        }

        if (tempNode.root->right != NULL) {
            Enqueue(tempNode.floor + 1, tempNode.root->right->val, tempNode.root->right);
        }
    }
    
    return returnArray;
}

```
