每次找前序的第一个数，看它在中序中的位置，中序中该位置左边n个数为左子树的中序，右边m个数为右子树的中序,前序中第二个数开始的n个数为左子树的前序，最后的m个数为右子树的前序。
下面代码处理时只对中序递归，没有对前序递归，因为前序中要找的数的位置每次随调用中序的递归函数加一。

```C++ []
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int pre_pos = 0, in_pos = 0;
		TreeNode* root = helper(preorder, inorder, pre_pos, 0, (int)inorder.size() - 1);
		return root;
	}
	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& pre_pos, int in_lpos, int in_rpos) {
		if (pre_pos >= preorder.size())
			return NULL;
		if (in_lpos > in_rpos)
			return NULL;
		int tmp = preorder[pre_pos];
		pre_pos++;
		TreeNode* root = new TreeNode(tmp);
		int in_pos = find(inorder.begin()+ in_lpos, inorder.begin()+ in_rpos, tmp) - inorder.begin();
		root->left = helper(preorder, inorder, pre_pos, in_lpos, in_pos - 1);
		root->right = helper(preorder, inorder, pre_pos, in_pos + 1, in_rpos);
		return root;
	}
};
```
