#if 0
#include "stdafx.h"
#include "stdlib.h"

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool Check(struct TreeNode *left, struct TreeNode *right)
{
	if (!left && !right) {
		return true;
	}
	if (!left || !right) {
		return false;
	}
	if (left->val != right->val) {
		return false;
	}
	return Check(left->left, right->right) && Check(left->right, right->left);
}
bool isSymmetric(struct TreeNode *root){
	return Check(root, root);
}

//int g_src[] = {1,2,2,-1,3,-1,3};//{1,2,2,3,4,4,3};
int g_src[] = {1,2,2,3,4,4,3};
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
bool Check(struct TreeNode *left, struct TreeNode *right)
{
	if (!left && !right) {
		return true;
	}
	if (!left || !right) {
		return false;
	}
	if (left->val != right->val) {
		return false;
	}
	return Check(left->left, right->right) && Check(left->right, right->left);
}
bool isSymmetric(struct TreeNode *root){
	return Check(root, root);
}