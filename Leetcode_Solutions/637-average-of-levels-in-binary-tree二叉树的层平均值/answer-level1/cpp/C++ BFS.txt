### 解题思路
层次遍历

### 代码

```cpp
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		queue<TreeNode* >q;
		if (root!=NULL)
		{
			q.push(root);
			while (!q.empty())
			{
				double s = 0.0;
				int qSize = q.size();
				for (int i=0;i<qSize;i++)
				{
					TreeNode* front = q.front();
					s += front->val;
					q.pop();
					if (front->left != NULL) q.push(front->left);
					if (front->right != NULL) q.push(front->right);
				}
				res.push_back(s / qSize);
			}
		}
		return res;
	}
};
```