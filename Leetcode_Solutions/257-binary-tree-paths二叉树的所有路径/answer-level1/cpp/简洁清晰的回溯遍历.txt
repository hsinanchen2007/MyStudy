遍历至叶节点时，将path放入所有路径中即可
```cpp
class Solution 
{
public:
	vector<string> binaryTreePaths(TreeNode* root) 
	{
		if (root == nullptr)
		{
			return {};
		}
		vector<string> res;
		backtrack(root, res, "");
		return res;
	}
	
	void backtrack(TreeNode* root, vector<string>& res, string path)
	{
		/*叶节点*/
		if (((root->left == nullptr) && (root->right == nullptr)))
		{
			path += to_string(root->val);
			res.push_back(path);
		}
		else
		{
			path += to_string(root->val) + "->";
			/*左子树*/
			if (root->left != nullptr)
			{
				backtrack(root->left, res, path);
			}
			/*右子树*/
			if (root->right != nullptr)
			{
				backtrack(root->right, res, path);
			}
		}
	}
};
```