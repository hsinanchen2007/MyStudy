#if 0
#include "stdafx.h"
#include "stdlib.h"

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct queue_{
	struct TreeNode *each;
	struct queue_ *next;
} Item_t;

typedef struct {
	Item_t header;
	Item_t tail;
	int cnt;
} Queue_t;

bool IsEmpty(Queue_t *q)
{
	if (!q->header.next && !q->tail.next) {
		return true;
	}
	return false;
}

void EnQueue(Queue_t *q, struct TreeNode *each)
{
	Item_t *tmp = (Item_t *)calloc(1, sizeof(Item_t));
	if (tmp == NULL) {
		exit(-1);
	}
	tmp->each = each;
	if (IsEmpty(q)) {
		q->header.next = q->tail.next = tmp;
		q->cnt = 1;
		return;
	}
	q->tail.next->next = tmp;
	q->tail.next = tmp;
	q->cnt++;

}
struct TreeNode *DeQueue(Queue_t *q)
{
	if (IsEmpty(q)) {
		return NULL;
	}
	Item_t *tmp = q->header.next;
	q->header.next = tmp->next;
	struct TreeNode *ret = tmp->each;
	free(tmp);
	q->cnt--;
	if (!q->cnt) {
		q->header.next = NULL;
		q->tail.next = NULL;
	}
	return ret;

}
bool BfsCheck(struct TreeNode *left, struct TreeNode *right)
{
	Queue_t queue = {0, 0};
	EnQueue(&queue, left);
	EnQueue(&queue, right);
	while(!IsEmpty(&queue)) {
		struct TreeNode *lef = DeQueue(&queue);
		struct TreeNode *righ = DeQueue(&queue);
		if (!lef && !righ) {
			continue;
		}
		if (!lef || !righ) {
			return false;
		}
		if (lef->val != righ->val) {
			return false;
		}
		EnQueue(&queue,lef->left);
		EnQueue(&queue, righ->right);
		EnQueue(&queue, righ->left);
		EnQueue(&queue, lef->right);
	}
	return true;
}
bool isSymmetric(struct TreeNode *root){
	return BfsCheck(root, root);
}
//int g_src[] = {1,2,2,-1,3,-1,3};//{1,2,2,3,4,4,3};
int g_src[] = {9,-42,-42,-1,76,76,-1,-1,13,-1,13};
#define MAX_VALUE (sizeof(g_src) / sizeof(g_src[0]))

void CreatTree(struct TreeNode **root, int idx)
{
	struct TreeNode *queue[MAX_VALUE] = {0};
	int head = 0;
	int tail = 0;
	struct TreeNode *each = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
	if (each == NULL) {
		exit(-1);
	}
	each->val = g_src[idx++];
	*root = each;
	queue[tail++] = each;
	while (head != tail) {
		struct TreeNode *tmp = queue[head++];
		if (idx + 1 >= MAX_VALUE) {
			return;
		}
		struct TreeNode *left = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
		if (!left) {
			exit(-1);
		}
		left->val = g_src[idx++];
		tmp->left = left;
		queue[tail++]= left;

		struct TreeNode *right = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
		if (!right) {
			exit(-1);
		}
		right->val = g_src[idx++];
		tmp->right = right;
		queue[tail++]= right;
		
	}
}

void Bfs(struct TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	struct TreeNode *queue[MAX_VALUE] = {0};
	printf("%d ", root->val);
	int head = 0;
	int tail = 0;
	queue[tail++] = root;
	while (head != tail) {
		struct TreeNode *tmp = queue[head++];
		if (tmp->left) {
			printf("%d ", tmp->left->val);
			queue[tail++] = tmp->left;
		}
		if (tmp->right) {
			printf("%d ", tmp->right->val);
			queue[tail++] = tmp->right;
		}
	}
}
void FreeTree(struct TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;
	free(left);
	free(right);
}
int _tmain(int argc, _TCHAR* argv[])
{

	struct TreeNode *root = NULL;
	CreatTree(&root, 0);
	Bfs(root);
	printf("\nhello\n");
	bool ret = isSymmetric(root);
	FreeTree(root);
	printf("ret:%d", ret);
	return 0;
}
#endif
typedef struct queue_{
	struct TreeNode *each;
	struct queue_ *next;
} Item_t;

typedef struct {
	Item_t header;
	Item_t tail;
	int cnt;
} Queue_t;

bool IsEmpty(Queue_t *q)
{
	if (!q->header.next && !q->tail.next) {
		return true;
	}
	return false;
}

void EnQueue(Queue_t *q, struct TreeNode *each)
{
	Item_t *tmp = (Item_t *)calloc(1, sizeof(Item_t));
	if (tmp == NULL) {
		exit(-1);
	}
	tmp->each = each;
	if (IsEmpty(q)) {
		q->header.next = q->tail.next = tmp;
		q->cnt = 1;
		return;
	}
	q->tail.next->next = tmp;
	q->tail.next = tmp;
	q->cnt++;

}
struct TreeNode *DeQueue(Queue_t *q)
{
	if (IsEmpty(q)) {
		return NULL;
	}
	Item_t *tmp = q->header.next;
	q->header.next = tmp->next;
	struct TreeNode *ret = tmp->each;
	free(tmp);
	q->cnt--;
	if (!q->cnt) {
		q->header.next = NULL;
		q->tail.next = NULL;
	}
	return ret;
}
bool BfsCheck(struct TreeNode *left, struct TreeNode *right)
{
	Queue_t queue = {0, 0};
	EnQueue(&queue, left);
	EnQueue(&queue, right);
	while(!IsEmpty(&queue)) {
		struct TreeNode *lef = DeQueue(&queue);
		struct TreeNode *righ = DeQueue(&queue);
		if (!lef && !righ) {
			continue;
		}
		if (!lef || !righ) {
			return false;
		}
		if (lef->val != righ->val) {
			return false;
		}
		EnQueue(&queue,lef->left);
		EnQueue(&queue, righ->right);
		EnQueue(&queue, righ->left);
		EnQueue(&queue, lef->right);
	}
	return true;
}
bool isSymmetric(struct TreeNode *root){
	return BfsCheck(root, root);
}