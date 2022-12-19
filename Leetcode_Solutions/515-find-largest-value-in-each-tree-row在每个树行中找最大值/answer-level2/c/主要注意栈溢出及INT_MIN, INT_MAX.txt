### 解题思路
INT_MIN,INT_MAX的使用。

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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUMS 10000001
typedef struct NODE_
{
    struct TreeNode *tree;
    int level;
}Node;
typedef struct Queue_ {
    Node arr[MAX_NUMS];
    int front;
    int rear;
}Queue;

void QueueInit(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}

int QueueCnt(Queue *queue)
{
    return abs(queue->rear - queue->front);
}
bool Full(Queue* queue)
{
    if ((queue->rear + 1) % MAX_NUMS == queue->front) {
        return true;
    }
    return false;
}
bool Empty(Queue* queue)
{
    return queue->front == queue->rear;
}
void QueuePush(Queue* queue, Node node)
{
    if (!Full(queue)) {
        queue->arr[queue->rear] = node;
        queue->rear = (queue->rear + 1) % MAX_NUMS;
    }
}
void QueuePop(Queue* queue)
{
    if (!Empty(queue)) {
        queue->front = (queue->front + 1) % MAX_NUMS;
    }
}
void QueueClear(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}
Node QueueTop(Queue* queue)
{
    return queue->arr[queue->front];
}

#define MAXV 100001
Queue myQue;
int* largestValues(struct TreeNode* root, int* returnSize){


if(root == 0) {
    *returnSize = 0;
    return 0;
}
int *ret = malloc(sizeof(int) * MAXV);

QueueInit(&myQue);
Node myNode;
myNode.tree = root;
myNode.level  = root->val;
QueuePush(&myQue,myNode);
int maxval = INT_MIN;
int k = 0;
while(!Empty(&myQue)) {
    int cnt = QueueCnt(&myQue);
    for(int i = 0; i < cnt; i++) {
        myNode = QueueTop(&myQue);
        if(myNode.level > maxval) {
            maxval = myNode.level;
        }
        QueuePop(&myQue);
        if(myNode.tree->left != 0) {
            Node tmpL;
            tmpL.tree = myNode.tree->left;
            tmpL.level = myNode.tree->left->val;
            QueuePush(&myQue,tmpL);
        }        
        if(myNode.tree->right != 0) {
            Node tmpL;
            tmpL.tree = myNode.tree->right;
            tmpL.level = myNode.tree->right->val;
            QueuePush(&myQue,tmpL);
        }        

    }
    ret[k++] = maxval;
    maxval = INT_MIN;
}
*returnSize = k;
QueueClear(&myQue);
return ret;
}
```