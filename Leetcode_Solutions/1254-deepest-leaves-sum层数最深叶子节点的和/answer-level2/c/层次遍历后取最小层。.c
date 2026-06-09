### 解题思路
层次遍历后取最后一层。

### 代码

```c

#define MAX_NUMS 10000001
typedef struct NODE_
{
    struct TreeNode* tr;
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
Queue myQueue;
int deepestLeavesSum(struct TreeNode* root){



QueueInit(&myQueue);

if(root==0)
{
   return 0;
}
Node myNode;
myNode.tr = root;
myNode.level = 0;
QueuePush(&myQueue, myNode);
int sum = 0;
while(!Empty(&myQueue)){

int cnt = QueueCnt(&myQueue);
sum = 0;
for(int i = 0; i < cnt; i++)
{
   Node tmpNode = QueueTop(&myQueue);
   sum+= tmpNode.tr->val;
   QueuePop(&myQueue);
   if(tmpNode.tr->left != 0){
       Node pushNode;
	   pushNode.tr = tmpNode.tr->left;
	   pushNode.level= tmpNode.level+1;
	   QueuePush(&myQueue, pushNode);
   }
   if(tmpNode.tr->right != 0){
       Node pushNode;
	   pushNode.tr = tmpNode.tr->right;
	   pushNode.level= tmpNode.level+1;
	   QueuePush(&myQueue, pushNode);
   }   
}

}
QueueClear(&myQueue);
return sum;
}
```