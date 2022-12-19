传入paths时要引用，当时郁闷了很长时间。。。
### 代码

```cpp
class Solution 
{
public:
	void construct_path(TreeNode* root, string path, vector<string>&paths)
	{
		if (root!=NULL)
		{
			path.append(to_string(root->val));
			if (root->left == NULL && root->right == NULL)
				paths.push_back(path);
			else
			{
				path.append("->");
				construct_path(root->left, path, paths);
				construct_path(root->right, path, paths);
			}
		}
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) 
	{
		vector<string> paths;
        string path;
		construct_path(root, path, paths);
		return paths;
	}
};
```