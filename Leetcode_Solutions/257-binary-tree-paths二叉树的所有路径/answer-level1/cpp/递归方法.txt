分情况来进行递归；



```C++ []
class Solution {
public:

void rettree(TreeNode* root, string path, vector<string>& ret)
{
	if (root == NULL)
	{
        ret.push_back(path);
	}
	else if (root->left != NULL && root->right != NULL)
	{
        path.append("->");
		path.append(to_string(root->val));
		rettree(root->left, path, ret);
		rettree(root->right, path, ret);
	}
	else if (root->left == NULL)
	{
		path.append("->");
		path.append(to_string(root->val));
		rettree(root->right, path, ret);
	}
	else if (root->right == NULL)
	{
		path.append("->");
		path.append(to_string(root->val));
		rettree(root->left, path, ret);
	}
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> res;
	string path;
	if (root == NULL)
	{
	}
    else if (root->left == NULL && root->right == NULL)
	{
		path.append(to_string(root->val));
		res.push_back(path);
	}
	else if(root->left != NULL && root->right != NULL)
	{
		path.append(to_string(root->val));
		rettree(root->left, path, res);
		rettree(root->right, path, res);
	}
	else if(root->left ==NULL)
	{
		path.append(to_string(root->val));
		rettree(root->right, path, res);
	}
	else if(root->right == NULL)
	{
		path.append(to_string(root->val));
		rettree(root->left, path, res);
	}	else
	{
		path.append(to_string(root->val));
		res.push_back(path);
	}
	return res;
}
};```

