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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// - - - - - 包含头文件 - - - - -
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// - - - - - 代换 ElemType - - - - -
typedef struct TreeNode* QElemType;

// - - - - - 函数结果状态代码 - - - - -
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// - - - - - Status 是函数的类型，其值是函数结果状态代码 - - - - -
typedef int Status;

// - - - - - 队列的链式存储结构 (单链队列) - - - - -
typedef struct QNode {
	QElemType data;
	struct QNode * next;
} QNode, *QNodePtr;

typedef struct LinkQueue {
	QNodePtr front; // 队头指针
	QNodePtr rear; // 队尾指针
} LinkQueue;

// - - - - - 单链队列的基本操作的函数原型声明 (5 个) - - - - -
Status InitQueue(LinkQueue *);
// 操作结果：构造一个空队列 Q。
Status DestroyQueue(LinkQueue *);
// 初始条件：队列 Q 已存在。
// 操作结果：队列 Q 被销毁，Q 不再存在。
Status QueueEmpty(LinkQueue);
// 初始条件：队列 Q 已存在。
// 操作结果：若队列 Q 为空队列，则返回 TRUE，否则 FALSE。
Status EnQueue(LinkQueue *, QElemType);
// 初始条件：队列 Q 已存在。
// 操作结果：插入元素 e 为 Q 的新的队尾元素。
Status DeQueue(LinkQueue *, QElemType *);
// 初始条件：Q 为非空队列。
// 操作结果：若队列不为空，则删除 Q 的队头元素，并用 e 返回其值，返回 OK，否则返回 ERROR。

// - - - - - 单链队列的基本操作的函数实现 (5 个) - - - - -
Status InitQueue(LinkQueue * Q) {
	// 构造一个空队列 Q。
	Q->front = (QNodePtr) malloc(sizeof(QNode));
	if (!(Q->front)) { // 存储分配失败
		exit(OVERFLOW);
	}
	Q->rear = Q->front;
	(Q->front)->next = NULL;
	return OK;
} // InitQueue

Status DestroyQueue(LinkQueue * Q) {
	// 队列 Q 被销毁，不再存在。
	while (Q->front) {
		Q->rear = (Q->front)->next;
		free(Q->front);
		Q->front = Q->rear;
	} // while loop 结束时 Q->front = Q->rear = NULL
	  // Q->front = NULL;
	  // Q->rear = NULL;
	return OK;
} // DestroyQueue

Status QueueEmpty(LinkQueue Q) {
	// 若 Q 为空队列，则返回 TRUE，否则 FALSE。
	if (Q.front == Q.rear) {
		return TRUE;
	} else {
		return FALSE;
	}
} // QueueEmpty

Status EnQueue(LinkQueue * Q, QElemType e) {
	// 插入元素 e 为 Q 的新的队尾元素。
	(Q->rear)->next = (QNodePtr) malloc(sizeof(QNode));
	if (!((Q->rear)->next)) { // 存储分配失败
		exit(OVERFLOW);
	}
	Q->rear = (Q->rear)->next;
	(Q->rear)->data = e;
	(Q->rear)->next = NULL;
	return OK;
} // EnQueue

Status DeQueue(LinkQueue * Q, QElemType * e) {
	// 删除 Q 的队头元素，并用 e 返回其值。
	if (Q->front != Q->rear) {
		*e = ((Q->front)->next)->data;
		QNodePtr p = Q->front;
		Q->front = (Q->front)->next;
		free(p);
		return OK;
	} else {
		return ERROR;
	}
} // DeQueue

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int value[10000] = { 0 };
    int columnSizes[10000] = { 0 };
    
    LinkQueue Q;
    InitQueue(&Q);

    QElemType e = root;
    EnQueue(&Q, e);
    *returnSize = 0;
    for (int i = 1, j = 0, k = 0; QueueEmpty(Q) == FALSE; i++) {
        DeQueue(&Q, &e);
        if (e == NULL) {
            // nothing
        } else {
            value[k++] = e->val;
            j++;
            EnQueue(&Q, e->left);
            EnQueue(&Q, e->right);
        }
        if ((*returnSize == 0 || i == 2 * columnSizes[*returnSize - 1]) && j != 0) {
            columnSizes[(*returnSize)++] = j;
            i = 0;
            j = 0;
        }
    }
    
    *returnColumnSizes = (int *) malloc ((*returnSize) * sizeof(int));
    int** result = (int**) malloc(*returnSize * sizeof(int*));
    for (int i = 0, k = 0; i < *returnSize; i++) {
        returnColumnSizes[0][i] = columnSizes[i];
        result[i] = (int*) malloc (columnSizes[i] * sizeof(int));
        for (int j = 0; j < columnSizes[i]; j++) {
            result[i][j] = value[k++];
        }
    }

    DestroyQueue(&Q);

    return result;
}
```
