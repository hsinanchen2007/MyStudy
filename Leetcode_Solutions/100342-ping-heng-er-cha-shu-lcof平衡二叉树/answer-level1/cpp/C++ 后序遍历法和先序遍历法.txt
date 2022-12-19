### 解题思路
方法一：先序遍历每一个节点，并比较左右子树高度，如果有>1则返回false
方法二：后序遍历每一个节点，时间复杂度小



### 代码

#### 方法一

```cpp
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL) return true;//如果该子树为空，则一定是平衡的（因为没有左右子树）
		if (abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
		return isBalanced(root->left)&& isBalanced(root->right);
	}
	int getHeight(TreeNode* root)
	{
		if (root == NULL) return 0;
		int leftHeight = getHeight(root->left);
		int rightHeight = getHeight(root->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
};
```

#### 方法二
```cpp
/*后序遍历解题*/
/*
使用后序遍历的方式遍历二叉树的每个节点，那么在遍历到一个节点之前我们就已经
遍历了它的左右子树。只要在每个节点的时候记录它的深度(某一节点的深度等于它到叶节点的路径的长度）
就可以判断每个节点是不是平衡的
*/
class Solution {
public:
	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr) return true;
		int depth = 0;
		return isBalanced(root, depth);
	}
	bool isBalanced(TreeNode* root,int &pDepth) {
		if (root == nullptr) { pDepth = 0; return true; }
		int left=0,right=0;
		if (isBalanced(root->left, left) && isBalanced(root->right, right))
		{
			int diff = left - right;
			if (abs(diff) <= 1)
			{
				pDepth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}
};
```