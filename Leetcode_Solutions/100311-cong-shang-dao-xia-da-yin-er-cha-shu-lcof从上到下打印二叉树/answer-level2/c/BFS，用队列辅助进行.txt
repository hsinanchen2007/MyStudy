### 解题思路
此处撰写解题思路

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

typedef struct TreeNode* QDataType;
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _head;
	QNode* _tail;
}Queue;

//初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = NULL;
	q->_tail = NULL;
}
//队尾入
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_next = NULL;

	if (q->_tail == NULL)
	{
		q->_head = q->_tail = newnode;
	}
	else
	{
		q->_tail->_next = newnode;
		q->_tail = newnode;
	}
}
//队头出
void QueuePop(Queue* q)
{
	assert(q);
	QNode* cur = q->_head;
	if (q->_head->_next != NULL)
	{
		q->_head = q->_head->_next;
		free(cur);
	}
	else
	{
		free(q->_head);
		q->_head = q->_tail = NULL;
	}

}
//获得队列头部元素
QDataType QueueHead(Queue* q)
{
	assert(q);
	return q->_head->_data;
}
//检查队列是否为空(空 - 0  非空 - 1)
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_head == NULL ? 0 : 1;
}
//销毁队列
void QueueDestroy(Queue* q)
{
	QNode* cur = q->_head;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_head = q->_tail = NULL;
}

int* levelOrder(struct TreeNode* root, int* returnSize)
{
    int* Arr = (int*)malloc(sizeof(int) * 100000);
    if(root == NULL)
    {
        *returnSize = 0;
        return Arr;
    }
    Queue st;
    QueueInit(&st);
    QueuePush(&st,root);
    int i = 0;
    while(QueueEmpty(&st))   //队不空就继续
    {
        struct TreeNode* root = QueueHead(&st);
        QueuePop(&st);
        Arr[i++] = root->val;
        if(root->left)
           QueuePush(&st,root->left);
        if(root->right)
           QueuePush(&st,root->right);
    }
    *returnSize = i;
    QueueDestroy(&st);  //销毁队列
    return Arr;
}
```