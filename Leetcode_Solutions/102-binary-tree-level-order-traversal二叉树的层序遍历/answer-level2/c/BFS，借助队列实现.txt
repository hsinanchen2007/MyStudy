### 解题思路
创建两个一维数组，一个树每层元素的个数，一个存整个树的元素
创建一个二维数组，根据每层元素的个数，将全部元素存入到二维数组中去

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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//借助队列完成
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if(root == NULL)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }  
    int* num1= (int*)malloc(sizeof(int) * 10000);  //存储每层的元素个数
    int* num2 = (int*)malloc(sizeof(int) * 10000); //存储全部的元素，开大点，不然后面超长的存不下
    Queue p;
    QueueInit(&p);
    QueuePush(&p,root);
    int phead = -1, ptail = 0,cur = 0,i = 0,i1 = 0,i2 = 0;//i1 记录总层数，i2用来记录总存储元素
    while(QueueEmpty(&p))
    {
        struct TreeNode* root = QueueHead(&p);
        num2[i2++] = root->val;
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
            num1[i1++] = cur;
            cur = ptail;
        }
    }
    *returnSize = i1;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    int t = 0;
    int** arr = (int**)malloc(sizeof(int*) * 10000);
    for(int j = 0; j < *returnSize; ++j)  
    {
        int tmp = 0;      //tmp记录每层所存在的元素个数
        if(num1[j] == 0)
            tmp = num1[j] + 1;
        else
            tmp = num1[j] - num1[j-1];
        returnColumnSizes[0][j] = tmp;
        arr[j] = (int*)malloc(sizeof(int) * tmp);
        for(int k = 0; k < tmp; ++k)
        {
            arr[j][k] = num2[t++];    //按每层的个数将num2中的元素存入arr
        }    
    }
    return arr;
}
```