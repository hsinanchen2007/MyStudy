注意点：C语言，BFS用的队列要自己撸，因为不知道二叉树有多少个节点，所以队列这里采用的动态申请内存，而不是定义一个最大规格的数组。循环队列注意二叉树只有1个节点的情况，要做特殊处理，否则PushQueue的时候会判定为队列满。

代码：
```
void GetTotalNodeNum(struct TreeNode *root, int *totalNum)
{
    if (root == NULL) {
        return;
    }
    (*totalNum)++;

    GetTotalNodeNum(root->left, totalNum);
    GetTotalNodeNum(root->right, totalNum);
}

int GetTreeDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    int leftDepth = GetTreeDepth(root->left);
    int rightDepth = GetTreeDepth(root->right);
    return leftDepth < rightDepth ? rightDepth + 1 : leftDepth + 1;
}

typedef struct TreeNode ElemType;
typedef struct MyQueue {
    ElemType* elem;
    int size;
    int front;
    int tail;
}MyQueue;

void InitQueue(MyQueue* Q, int num)
{
    Q->elem = (ElemType*)malloc(sizeof(ElemType) * num);
    if (Q->elem == NULL) {
        return;
    }
    Q->size = 0;
    Q->front = 0;
    Q->tail = 0;
}

bool IsQueueEmpty(MyQueue *Q)
{
    if (Q->front == Q->tail) {
        return true;
    }
    return false;
}

bool IsQueueFull(MyQueue* Q, int num)
{
    if ((Q->tail + 1) % num == Q->front) {
        return true;
    }
    return false;
}

void PushQueue(MyQueue* Q, int num, ElemType e)
{
    if (IsQueueFull(Q, num)) {
        return;
    }
    Q->elem[Q->tail] = e;
    Q->tail = (Q->tail + 1) % num;
    (Q->size)++;
}

void PopQueue(MyQueue* Q, int num, ElemType* e)
{
    if (IsQueueEmpty(Q)) {
        return;
    }
    *e = Q->elem[Q->front];
    Q->front = (Q->front + 1) % num;
    (Q->size)--;
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = (int*)malloc(sizeof(int));
        returnColumnSizes[0][0] = 0;
        return NULL;
    }

    int totalNum = 0;
    GetTotalNodeNum(root, &totalNum);
    if (totalNum == 1) {
        totalNum++;
    }

    int depth = GetTreeDepth(root);
    int** result = (int**)malloc(sizeof(int*) * depth);
    if (result == NULL) {
        return NULL;
    }
    *returnSize = depth;

    *returnColumnSizes = (int*)malloc(sizeof(int) * depth);
    if (*returnColumnSizes == NULL) {
        free(result);
        return NULL;
    }


    MyQueue Q;
    InitQueue(&Q, totalNum);
    PushQueue(&Q, totalNum, *root);
    int depIndex = 0;
    while (!IsQueueEmpty(&Q)) {
        int colSize = Q.size;
        result[depIndex] = (int*)malloc(sizeof(int) * colSize);
        returnColumnSizes[0][depIndex] = colSize;

        int colIndex = 0;
        struct TreeNode temp;
        while (colSize > 0) {
            PopQueue(&Q, totalNum, &temp);
            result[depIndex][colIndex] = temp.val;
            colIndex++;
            colSize--;

            if (temp.left != NULL) {
                PushQueue(&Q, totalNum, *(temp.left));
            }
            if (temp.right != NULL) {
                PushQueue(&Q, totalNum, *(temp.right));
            }
        }

        depIndex++;
    }

    free(Q.elem);
    return result;
}
```
