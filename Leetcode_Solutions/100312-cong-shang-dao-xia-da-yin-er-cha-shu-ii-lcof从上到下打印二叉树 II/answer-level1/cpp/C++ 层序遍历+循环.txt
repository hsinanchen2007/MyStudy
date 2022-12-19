### 解题思路
对每一层根据数量，进行循环输出

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> res;
		if (root != NULL)//根节点不为空
		{
			q.push(root);
			while (!q.empty())
			{
				vector<int> layer;
				int qSize = q.size();//此时的q.size()即该层节点个数
				for (int i=0;i<qSize;i++)
				{
					TreeNode* front = q.front();
					layer.push_back(front->val);//每一层结点先压入到r中
                    cout<<front->val<<" ";
					q.pop();//出队
					//将其该结点的左右子树（下一层节点）压入
					if (front->left != NULL) q.push(front->left);
					if (front->right != NULL) q.push(front->right);
				}
				res.push_back(layer);//将存放该层所有结点的r压入到v中
			}
		}
		return res;
	}
};
```