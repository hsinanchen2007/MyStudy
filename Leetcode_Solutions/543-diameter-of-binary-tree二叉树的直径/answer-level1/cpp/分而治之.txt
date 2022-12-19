### 解题思路
最长的路径可能出现在三个地方。
分而治之，分别分析以下三种情况：
（1）左子树中（2）右子树中（3）经过根节点的路径
分别求出三个地方的最大值再求出三个最大值中的最大值即可。
下面分别求（1）（2）（3）
（1）（2）比较简单，直接递归调用即可。
（3）通过分析可知，经过根节点的最长路径=左子树深度+右子树深度+2。



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
	int diameterOfBinaryTree(TreeNode* root)
	{
		return max(0, diameterOfBinaryTree_help(root));
	}

	int diameterOfBinaryTree_help(TreeNode* root) {
		if (root == NULL)
			return -1;
		int m;
		m = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
		m = max(m, heightOfTree(root->left) + heightOfTree(root->right) + 2);
		return m;

	}

	int heightOfTree(TreeNode* root)
	{
		if (root == NULL)
			return -1;
		return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
	}
};
```