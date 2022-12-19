#define MIN(a, b) ((a) > (b)) ? (b) : (a)
int g_last;
int g_min;
void InOrderTraverse(struct TreeNode *t)
{
	if (t == NULL) {
		return;
	}
	InOrderTraverse(t->left);
	if (g_last != 0xffffffff) {
		g_min = MIN(g_min, abs(t->val - g_last));
	}
	g_last = t->val;
	InOrderTraverse(t->right);
}

int minDiffInBST(struct TreeNode* root){
    g_last = 0;
	g_min = 0x7fffffff;
    g_last = 0xffffffff;
	InOrderTraverse(root);
	return g_min;
}
