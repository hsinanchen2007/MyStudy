### 解题思路
使用队列横向遍历树

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
#define RET_OK 0
#define RET_ERR 1
#define BASE_SIZE	1000
#define MAX_LEVEL   1000
struct Queue {
	struct TreeNode **buf;
	int size;
	int cnt;
	int head;
	int tail;
};
int qInit(struct Queue *q)
{
	q->size = BASE_SIZE;
	q->buf = (struct TreeNode**)calloc(BASE_SIZE, sizeof(struct TreeNode*));
	if (q->buf == NULL) {
		return RET_ERR;
	}
	q->cnt = 0;
	q->head = 0;
	q->tail = 0;
	return RET_OK;
}
int qEnq(struct Queue *q, struct TreeNode* node)
{
	if (q->cnt == q->size) {
		printf("buf is to small, size = %d\n", q->size);
		return RET_ERR;
	}
	q->buf[q->tail] = node;
	q->tail += 1;
	q->tail %= q->size;
	q->cnt++;
	return RET_OK;
}
int qPollHead(struct Queue *q, struct TreeNode** node)
{
	if (q->cnt == 0) {
		return RET_ERR;
	}
	*node = q->buf[q->head];
	q->head += 1;
	q->head %= q->size;
	q->cnt--;
	return RET_OK;
}
int qPeekTail(struct Queue *q, struct TreeNode** node)
{
	if (q->cnt == 0) {
		return RET_ERR;
	}
	*node = q->buf[(q->tail + q->size - 1) % q->size];
	return RET_OK;
}
bool qIsEmpty(struct Queue *q)
{
	return q->cnt == 0;
}
void qFree(struct Queue *q)
{
	if (q->buf != NULL) {
		free(q->buf);
		q->buf = NULL;
	}
	return;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize){
	int ret;
	double *rlt = NULL;
	int level, levelCnt;
	struct Queue q = { 0 };
	struct TreeNode* last = NULL;
	struct TreeNode* cur = NULL;
	double sum;
	
	rlt = (double*)calloc(MAX_LEVEL, sizeof(double));
	if (rlt == NULL) {
		*returnSize = 0;
		return NULL;
	}
	ret = qInit(&q);
	if (ret != RET_OK) {
		free(rlt);
		qFree(&q);
		*returnSize = 0;
		return NULL;
	}
	qEnq(&q, root);
	level = 0;
	levelCnt = 0;
	sum = 0;
	last = root;
	while(qIsEmpty(&q) == false) {
		qPollHead(&q, &cur);
		sum += cur->val;
		levelCnt++;
		if (cur->left != NULL) {
			qEnq(&q, cur->left);
		}
		if (cur->right != NULL) {
			qEnq(&q, cur->right);
		}
		if (cur == last) {
			rlt[level] = sum / levelCnt;
			level++;
			sum = 0;
			levelCnt = 0;
			qPeekTail(&q, &last);
		}
	}
	qFree(&q);
	*returnSize = level;
	return rlt;
}
```