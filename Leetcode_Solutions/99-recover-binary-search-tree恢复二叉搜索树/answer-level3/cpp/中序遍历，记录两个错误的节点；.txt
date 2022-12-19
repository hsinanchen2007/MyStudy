myfirst记录第一个被错误交换的节点指针，mysecond记录第二个被错误交换的节点指针，mylast记录在中序遍历中上一个被遍历到的节点指针；通过比较当前节点的值和上一个节点的值来判断其是否是myfirst或者mysecond；注意：若被错误交换的两个节点在中序遍历中是相邻的两个节点（相邻是指以相邻的顺序被遍历到），与不相邻的有一点点区别；
代码如下：
class Solution {
public:
	int judge = 0;
	TreeNode* myfirst = NULL;
	TreeNode* mysecond = NULL;
	TreeNode* mylast = NULL;
	void recoverTree(TreeNode* root) {
		trackback(root);
		int first = myfirst->val;
		myfirst->val = mysecond->val;
		mysecond->val = first;
		return;
	}
	void trackback(TreeNode* root)
	{
		if (root == NULL)
			return;
		trackback(root->left);
		if (mylast!=NULL&&root->val < mylast->val&&judge == 0)
		{
			judge = 1;
			myfirst = mylast;
			mysecond = root;
		}
		else if (mylast!=NULL&&root->val < mylast->val&&judge == 1)
		{
			judge = 2;
			mysecond = root;
		}
		mylast = root;
		trackback(root->right);
	}
};