### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		int r_label = -1;
		return getTree(preorder, inorder, 0, preorder.size() - 1,r_label);
	}
	TreeNode *getTree(vector<int>& preorder, vector<int>&inorder, int begin, int end,int &r_label) {
		if (begin > end) 
			return NULL;
		r_label++;  // 前序下标每次前进一个
		int pivot = 0;
		for (; pivot <= end && inorder[pivot] != preorder[r_label]; pivot++); // 找到中序中的根节点
		TreeNode *r = new TreeNode(preorder[r_label]); // 创建分支根节点
		r->left = getTree(preorder, inorder, begin, pivot - 1,r_label); // 构建左右子树
		r->right = getTree(preorder, inorder, pivot + 1, end,r_label);
		return r;
	}
};
```