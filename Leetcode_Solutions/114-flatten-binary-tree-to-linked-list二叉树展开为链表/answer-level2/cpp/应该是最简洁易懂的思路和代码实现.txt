思路见注释，一步步走下去就完成了
```cpp
class Solution
{
public:
	void flatten(TreeNode* root)
	{
		TreeNode* p = root;
		while (p)
		{
			if (p->left)
			{
				TreeNode* t = p->right;	//右节点摘下来放入t
				p->right = p->left;		//左节点挂到右边
				p->left = nullptr;		//左节点置空

				TreeNode* temp = p->right;
				while (temp->right)		//找到右节点最右侧
				{
					temp = temp->right;
				}
				temp->right = t;		//将t挂到右节点最右侧
			}
			p = p->right;	//向下走
		}
	}
};

```