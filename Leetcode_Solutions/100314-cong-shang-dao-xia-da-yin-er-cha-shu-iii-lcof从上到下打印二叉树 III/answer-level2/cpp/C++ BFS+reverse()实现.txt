### 解题思路
BFS遍历
对于偶数层，进行reverse
对于奇数层，不进行
[reverse用法参考文章](https://blog.csdn.net/PiscesDAI/article/details/84528955)
### 代码

```cpp
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root!=NULL)
		{
			bool flag = true;//奇数层为false，偶数层为true
			queue<TreeNode*> q;
			q.push(root);
			while (!q.empty())
			{
				vector<int> temp;
				int qSize = q.size();
				flag = !flag;
				for (int i=0;i<qSize;i++)
				{
					
					TreeNode* front = q.front();
					temp.push_back(front->val);
					q.pop();
					if (front->left != NULL) q.push(front->left);
					if (front->right != NULL) q.push(front->right);
				}
				if (flag)
				{
					reverse(temp.begin(), temp.end());
				}
				res.push_back(temp);
			}
		}
		return res;
	}
};
```