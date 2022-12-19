### 解题思路
记得考虑空树的情况,前面是我自己写的队列

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

typedef struct TreeNode* QDataType;    //要存节点，存别的找不到左右子树
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize)
{
    int* arr = (int*)malloc(sizeof(int) * 500);
    if(root == NULL)
    {
        *returnSize = 0;
        return arr;
    }
    Queue p;
    QueueInit(&p);
    QueuePush(&p,root);
    int phead = -1, ptail = 0,cur = 0,i = 0;   //设置三个变量，cur用来记录每一层最后一个的位置
    while(QueueEmpty(&p))     //当队列不为空
    {
        struct TreeNode* root = QueueHead(&p);
        QueuePop(&p);
        ++phead;
        if(root->left)
        {
            QueuePush(&p,root->left);
            ++ptail;
        }
        if(root->right)
        {
            QueuePush(&p,root->right);
            ++ptail;
        }
        if(phead == cur)
        {
            arr[i++] = root->val;
            cur = ptail;
        }
    }
    *returnSize = i;
    QueueDestroy(&p);
    return arr;
}

```