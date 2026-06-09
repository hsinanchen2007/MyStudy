#if 0
#include "stdafx.h"
#include "stdlib.h"

#define FALG 0x7fffffff
 // Definition for a binary tree node.
 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 
 int g_a[] = {0,2,4,1,FALG,3,-1,5,1,FALG,6,FALG,8};
 #define CREAT_MAX sizeof(g_a) / sizeof(g_a[0])
void CreatTree(struct TreeNode **tree, int idx)
{
	struct TreeNode *each = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
	if (!each) {
		exit(-1);
	}
	each->val = g_a[idx++];
	*tree = each;
	struct TreeNode *queue[CREAT_MAX] = {0};
	int head = 0;
	int tail = 0;
	queue[tail++] = each;
	while (head != tail && idx < CREAT_MAX) {
		struct TreeNode *tmp = queue[head++];
		if (g_a[idx] != FALG) {
			struct TreeNode *left = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
			if (!left) {
				exit(-1);
			}
			left->val = g_a[idx];
			tmp->left = left;
			queue[tail++] = left;
		}
		idx++;
		if (g_a[idx] != FALG) {
			struct TreeNode *right = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
			if (!right) {
				exit(-1);
			}
			right->val = g_a[idx];
			tmp->right = right;
			queue[tail++] = right;
		}
		idx++;	
	}
}

void Bfs(struct TreeNode *tree)
{
	struct TreeNode *queue[2 * CREAT_MAX] = {0};
	int head = 0;
	int tail = 0;
	queue[tail++] = tree;
	while (head != tail) {
		struct TreeNode *tmp = queue[head++];
		if (!tmp) {
			continue;
		}
		printf("%d ", tmp->val);
		queue[tail++] = tmp->left;
		queue[tail++] = tmp->right;
	}
	printf("\n");
}

#define MAX_SIZE 10000
typedef struct {
	int *val;
	int *level;
} Data_t;

void BfsSearch(struct TreeNode *root, Data_t *ret, int *idx, int *lev)
{
	struct TreeNode *queue[MAX_SIZE] = {0};
	int head = 0;
	int tail = 0;
	queue[tail++] = root;
	ret->val[*idx] = root->val;
	ret->level[*idx] = *lev;
	*idx += 1;
	*lev += 1;
	struct TreeNode *bQueue[MAX_SIZE] = {0};
	int bHead = 0;
	int bTail = 0;
	struct TreeNode **qptr = queue;
	struct TreeNode **qback = bQueue;
	while (head != tail) {
		struct TreeNode *tmp = qptr[head++];
		if (!tmp) {
			continue;
		}
		if (tmp->left) {
			qback[bTail++] = tmp->left;
			ret->val[*idx] = tmp->left->val;
			ret->level[*idx] = *lev;
			*idx += 1;
		}
		if (tmp->right) {
			qback[bTail++] = tmp->right;
			ret->val[*idx] = tmp->right->val;
			ret->level[*idx] = *lev;
			*idx += 1;
		}	
		if (head == tail && bHead != bTail) {
			head = 0;
			tail = bTail;
			bHead = 0;
			bTail = 0;
			struct TreeNode **tmpPtr = qptr;
			qptr = qback;
			qback = tmpPtr;
			*lev += 1;
		}
	}
	*lev -= 1;
}

void PrintQueue(Data_t *queue, int len)
{
	for (int i = 0; i < len; i++) {
		printf("data:%d lev:%d\n", queue->val[i], queue->level[i]);
	}
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	*returnSize = 0;
	if (!root) {
		return NULL;
	}
	int cnt = 0;
	Data_t queue;
	queue.val = (int *)calloc(MAX_SIZE, sizeof(int));
	queue.level = (int *)calloc(MAX_SIZE, sizeof(int));
	if (!queue.val || !queue.level) {
		exit(-1);
	}
	int lev = 1;
	int idx = 0;
	BfsSearch(root, &queue, &idx, &lev);
	//printf("\nlev:%d idx:%d\n", lev, idx);
	//PrintQueue(&queue, idx);
	*returnSize = lev;
	int **ret = (int **)calloc(lev, sizeof(int *));
	int *cntArr = (int *)calloc(lev, sizeof(int));
	if (!ret || !cntArr) {
		exit(-1);
	}
	for (int i = 0; i < lev; i++) {
		cntArr[i] = 1;
	}
	int j = 1;
	for (int i = 1; i < idx - 1 && j < lev; i++) {
		if (queue.level[i] == queue.level[i + 1]) {
			cntArr[j]++;
			continue;
		}
		j++;
	}
	//for (int i = 0; i < lev; i++) {
		//printf("\ncnt:%d i:%d\n", cntArr[i], i);	
	//}
	*returnColumnSizes = cntArr;
	for (int i = 0; i < lev; i++) {
		int *each = (int *)calloc(cntArr[i], sizeof(int));
		if (!each) {
			exit(-1);
		}
		ret[i] = each;
	}
	int sum = 0;
	for (int i = 0; i < lev; i++) {
		//printf("index:%d num:%d\n", sum, cntArr[i]);
		memcpy(ret[i], &(queue.val[sum]), cntArr[i] * sizeof(int));
		sum += cntArr[i];
	}
	free(queue.level);
	free(queue.val);
	return ret;
}

void PrintRet(int **ret, int len, int *col)
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < col[i]; j++) {
			printf("%d ", ret[i][j]);
		}
		printf("\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{

	struct TreeNode *root = NULL;
	CreatTree(&root, 0);
	Bfs(root);
	int size = 0;
	int *colSize = NULL;
	int **ret = levelOrder(root, &size, &colSize);
	PrintRet(ret, size, colSize);
	return 0;
}
#endif

#define MAX_SIZE 10000
typedef struct {
	int *val;
	int *level;
} Data_t;
void BfsSearch(struct TreeNode *root, Data_t *ret, int *idx, int *lev)
{
	struct TreeNode *queue[MAX_SIZE] = {0};
	int head = 0;
	int tail = 0;
	queue[tail++] = root;
	ret->val[*idx] = root->val;
	ret->level[*idx] = *lev;
	*idx += 1;
	*lev += 1;
	struct TreeNode *bQueue[MAX_SIZE] = {0};
	int bHead = 0;
	int bTail = 0;
	struct TreeNode **qptr = queue;
	struct TreeNode **qback = bQueue;
	while (head != tail) {
		struct TreeNode *tmp = qptr[head++];
		if (!tmp) {
			continue;
		}
		if (tmp->left) {
			qback[bTail++] = tmp->left;
			ret->val[*idx] = tmp->left->val;
			ret->level[*idx] = *lev;
			*idx += 1;
		}
		if (tmp->right) {
			qback[bTail++] = tmp->right;
			ret->val[*idx] = tmp->right->val;
			ret->level[*idx] = *lev;
			*idx += 1;
		}
		if (head == tail && bHead != bTail) {
			head = 0;
			tail = bTail;
			bHead = 0;
			bTail = 0;
			struct TreeNode **tmpPtr = qptr;
			qptr = qback;
			qback = tmpPtr;
			*lev += 1;
		}
	}
	*lev -= 1;
}
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
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	*returnSize = 0;
	if (!root) {
		return NULL;
	}
	int cnt = 0;
	Data_t queue;
	queue.val = (int *)calloc(MAX_SIZE, sizeof(int));
	queue.level = (int *)calloc(MAX_SIZE, sizeof(int));
	if (!queue.val || !queue.level) {
		exit(-1);
	}
	int lev = 1;
	int idx = 0;
	BfsSearch(root, &queue, &idx, &lev);
	//printf("\nlev:%d idx:%d\n", lev, idx);
	//PrintQueue(&queue, idx);
	*returnSize = lev;
	int **ret = (int **)calloc(lev, sizeof(int *));
	int *cntArr = (int *)calloc(lev, sizeof(int));
	if (!ret || !cntArr) {
		exit(-1);
	}
	for (int i = 0; i < lev; i++) {
		cntArr[i] = 1;
	}
	int j = 1;
	for (int i = 1; i < idx - 1 && j < lev; i++) {
		if (queue.level[i] == queue.level[i + 1]) {
			cntArr[j]++;
			continue;
		}
		j++;
	}
	//for (int i = 0; i < lev; i++) {
		//printf("\ncnt:%d i:%d\n", cntArr[i], i);	
	//}
	*returnColumnSizes = cntArr;
	for (int i = 0; i < lev; i++) {
		int *each = (int *)calloc(cntArr[i], sizeof(int));
		if (!each) {
			exit(-1);
		}
		ret[i] = each;
	}
	int sum = 0;
	for (int i = 0; i < lev; i++) {
		//printf("index:%d\n", sum);
		memcpy(ret[i], &(queue.val[sum]), cntArr[i] * sizeof(int));
		//ret[i] = &(queue.val[sum]);
		sum += cntArr[i];
	}
	free(queue.level);
	free(queue.val);
	return ret;
}