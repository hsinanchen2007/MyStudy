### 解题思路
简单的层次遍历即可。

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

#define MAX_NUMS 10000
typedef struct NODE_
{
    struct TreeNode* tree;
    int val;
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
Queue g_myQue;
int* rightSideView(struct TreeNode* root, int* returnSize){
    
	if(root == NULL) {
	   *returnSize = 0;
	   return 0;
	}
	
	int * ret = malloc(sizeof(int) * 10001);
	QueueInit(&g_myQue);
	Node myNode;
	myNode.val = 0;
	myNode.tree = root;
	
    QueuePush(&g_myQue, myNode);
	int cnt = 0;
    int t = 0;
	while(!Empty(&g_myQue)) {
 	      int cnt = QueueCnt(&g_myQue);
		  for(int i = 0; i < cnt; i++) {
             Node tmpNode = QueueTop(&g_myQue);
	   	     if(i == 0) {
			    ret[t++] = tmpNode.tree->val;
                 
             }
             QueuePop(&g_myQue);		 
             
			 if(tmpNode.tree->right != 0) {
                 myNode.val = tmpNode.val;
                 myNode.tree = tmpNode.tree->right;
			     QueuePush(&g_myQue, myNode);
			 }
			 if(tmpNode.tree->left != 0) {
                 myNode.val = tmpNode.val;
                 myNode.tree = tmpNode.tree->left;
			    QueuePush(&g_myQue, myNode);
			 }
		  }
	
	}
	
	
	printf("%d  ", t);
    *returnSize = t;
    QueueClear(&g_myQue);
    return ret;	
}
```