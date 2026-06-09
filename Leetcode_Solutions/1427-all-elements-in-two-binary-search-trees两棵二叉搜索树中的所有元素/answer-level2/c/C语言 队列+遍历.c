### 解题思路
遍历一遍，合并两个队列
![image.png](https://pic.leetcode-cn.com/05ea6079cd0cb123c3c4c9f5d33472fc8d5de3cf3946ccc0cc40ad527d343c21-image.png)

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
#define MY_QUEUE_BASE_SIZE 2048
#define MY_OK 0
#define MY_FAIL (-1)
struct MyQueue{
	int size;
	int cnt;
	int *buf;
};

int qInit(struct MyQueue *q)
{
	q->size = MY_QUEUE_BASE_SIZE;
	q->cnt = 0;
	q->buf = (int*)calloc(q->size, sizeof(int));
	if (q->buf == NULL) {
		return MY_FAIL;
	}
	return MY_OK;
}

int qAdd(struct MyQueue *q, int val)
{
	int *buf = NULL;
	if (q->cnt == q->size) {
		buf = (int*)calloc(q->size + MY_QUEUE_BASE_SIZE, sizeof(int));
		if (buf == NULL) {
			return MY_FAIL;
		}
		memcpy(buf, q->buf, q->cnt * sizeof(int));
		free(q->buf);
		q->buf = buf;
		q->size += MY_QUEUE_BASE_SIZE;
	}
	q->buf[q->cnt] = val;
	q->cnt += 1;
	return MY_OK;
}
void qFree(struct MyQueue *q)
{
	q->cnt = 0;
	q->size = 0;
	if (q->buf != NULL) {
		free(q->buf);
		q->buf = NULL;
	}
	return;
}
int allocBuf(struct MyQueue *q1, struct MyQueue *q2, struct MyQueue *q3)
{
	int ret;
	ret = qInit(q1);
	ret |= qInit(q2);
	ret |= qInit(q3);
	if (ret != MY_OK) {
		qFree(q1);
		qFree(q2);
		qFree(q3);
		return MY_FAIL;
	}
	return MY_OK;
}
void transTree(struct TreeNode* node, struct MyQueue *q)
{
	if (node == NULL) {
		return;
	}
	transTree(node->left, q);
	qAdd(q, node->val);
	transTree(node->right, q);
	return;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
	int cnt1 = 0, cnt2 = 0;
	int ret;
	struct MyQueue q1, q2, q3;
	ret = allocBuf(&q1, &q2, &q3);
	if (ret != MY_OK) {
		*returnSize = 0;
		return NULL;
	}
	transTree(root1, &q1);
	transTree(root2, &q2);
	while(cnt1 < q1.cnt && cnt2 < q2.cnt) {
		if (q1.buf[cnt1] < q2.buf[cnt2]) {
			qAdd(&q3, q1.buf[cnt1++]);
		} else {
			qAdd(&q3, q2.buf[cnt2++]);
		}
	}
	while(cnt1 < q1.cnt) {
		qAdd(&q3, q1.buf[cnt1++]);
	}
	while(cnt2 < q2.cnt) {
		qAdd(&q3, q2.buf[cnt2++]);
	}
	qFree(&q1);
	qFree(&q2);
	*returnSize = q3.cnt;
	return q3.buf;
}
```