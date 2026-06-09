方法一，向队列中push节点时，记录其深度，根据深度判断节点的层次
```cpp
class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		queue<pair<TreeNode*, int>> q;
		vector<vector<int>> res;
		if(!root)
		{
			return res;
		vector<int> temp;
		q.push({ root, 0 });
		int curr_length = 0;
		while (!q.empty())
		{
			TreeNode* t = q.front().first;
			int length = q.front().second;
			q.pop();

			int next_length;
			if (t)
			{
				if (length != curr_length)
				{
					curr_length = length;
					res.push_back(temp);
					temp.clear();
				}
				temp.push_back(t->val);
				if (t->left)
				{
					q.push({ t->left, length + 1 });
				}
				if (t->right)
				{
					q.push({ t->right, length + 1 });
				}
			}
		}
		res.push_back(temp);
		return res;
	}
};
```
方法二，每一次均将一层的节点拿出来
```cpp
class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		if (!root)
		{
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int n = q.size();
			vector<int> temp;
			for (int i = 0; i < n; ++i)
			{
				TreeNode* t = q.front();
                q.pop();
				temp.push_back(t->val);
				if (t->left)
				{
					q.push(t->left);
				}
				if (t->right)
				{
					q.push(t->right);
				}
			}
			res.push_back(temp);
		}
		return res;
	}
};
```