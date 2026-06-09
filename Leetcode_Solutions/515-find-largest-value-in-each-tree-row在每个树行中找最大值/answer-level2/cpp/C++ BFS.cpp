### 解题思路
BFS（层序遍历）

### 代码

```cpp
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		if (root!=NULL)
		{
			queue<TreeNode*> q;
			q.push(root);
			while (!q.empty())
			{
				int qSize = q.size();
				int max = -2147483648;
				for (int i=0;i<qSize;i++)
				{
					TreeNode* front = q.front();
					if (max<front->val)//如果该值比max大
					{
						max = front->val;
					}
					q.pop();//顶端结点弹出
					if (front->left != NULL) q.push(front->left);
					if (front->right != NULL)q.push(front->right);
				}
				res.push_back(max);
			}
		}
		return res;
	}
};
```