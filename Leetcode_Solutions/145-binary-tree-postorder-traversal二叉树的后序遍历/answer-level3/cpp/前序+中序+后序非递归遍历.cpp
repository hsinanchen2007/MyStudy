前序遍历：中左右
```cpp
class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode* curr = root;
		while (curr || !s.empty())
		{
			if (curr)
			{
				res.push_back(curr->val);
				s.push(curr);
				curr = curr->left;
			}
			else
			{
				curr = s.top();
				s.pop();
				curr = curr->right;
			}
		}
		return res;
	}
};
```
中序遍历：左中右
```cpp
class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode* curr = root;
		while (curr || !s.empty())
		{
			if (curr)
			{
				s.push(curr);
				curr = curr->left;
			}
			else
			{
				curr = s.top();
				s.pop();
				res.push_back(curr->val);
				curr = curr->right;
			}
		}
		return res;
	}
};
```
后续遍历：左右中
前序遍历和中序遍历，都是先拿到节点的值，栈中删除此节点，再去它的左边或者右边。而后序遍历是先去它的左右，此时不能删除节点，然后再拿当前节点的值，再删除节点。这样就要考虑可能会重复循环遍历右子树节点，因此需要通过pre来判断
```cpp
class Solution
{
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode* curr = root, *pre = nullptr;
		while (curr || !s.empty())
		{
			if (curr)
			{
				s.push(curr);
				curr = curr->left;
			}
			else
			{
				curr = s.top();
				if (curr->right && curr->right != pre)
				{
					curr = curr->right;
				}
				else
				{
					s.pop();
					res.push_back(curr->val);
					pre = curr;		//记录此访问过的右节点
					curr = nullptr;	//否则下一步会重复把curr给push进去
				}
			}
		}
		return res;
	}
};
```