每一层都翻转一次，定义一个临时的TreeNode指针辅助操作实现左右子树交换
```cpp
class Solution 
{
public:
	TreeNode* temp;
	TreeNode* invertTree(TreeNode* root) 
	{
		inverTreeHelper(root);
		return root;
	}

	void inverTreeHelper(TreeNode* root)
	{
		if (root != nullptr)
		{
		    temp = root->left;
			root->left = root->right;
			root->right = temp;

			inverTreeHelper(root->left);
			inverTreeHelper(root->right);
		}
	}
};
```