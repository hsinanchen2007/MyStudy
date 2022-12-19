//改进了上一次数值的记录通过单个int指针记录，避免与真实数据冲突
#define MIN(a, b) ((a) > (b)) ? (b) : (a)
int *g_last;
int g_min;
void InOrderTraverse(struct TreeNode *t)
{
	if (t == NULL) {
		return;
	}
	InOrderTraverse(t->left);
	if (g_last != NULL) {
		g_min = MIN(g_min, abs(t->val - *g_last));
	} else {
		g_last = (int *)calloc(1, sizeof(int));
		if (g_last == NULL) {
			exit(-1);
		}
	}
    *g_last = t->val;
	InOrderTraverse(t->right);
}

int minDiffInBST(struct TreeNode* root){
	g_last = NULL;
	g_min = 0x7fffffff;
	InOrderTraverse(root);
	free(g_last);
	return g_min;
}