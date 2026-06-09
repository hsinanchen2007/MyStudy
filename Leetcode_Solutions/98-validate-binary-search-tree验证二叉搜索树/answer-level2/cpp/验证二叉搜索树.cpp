### 解题思路
1、中序遍历，front保存上一个节点的指针。
2、当前的root节点值和上一节点值比较，如果非法，则置false。

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
	void zhongxuValid(TreeNode* root, TreeNode** front, bool &result)
	{
		if (!root)
			return;

		zhongxuValid(root->left, front, result);
		if (*front && root->val <= (*front)->val)
		{
			result = false;
			return;
		}
		else
			*front = root;

		zhongxuValid(root->right, front, result);
	}
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* comp = NULL;
		bool result = true;
		zhongxuValid(root, &comp, result);
		return result;
	}
};

```