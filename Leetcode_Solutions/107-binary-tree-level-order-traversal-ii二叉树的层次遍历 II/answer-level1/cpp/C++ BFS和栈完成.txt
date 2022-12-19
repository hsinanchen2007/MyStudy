### 解题思路
此题和之前一题（102题）相同，只不过此题要求逆序输出
对于逆序输出，第一个想到的就是栈，因此在BFS中，对于每一层的序列，先加入到栈中，待队列为空后，将栈中元素一一弹出并压入到res中即可

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;//存储结果
		queue<TreeNode*> q;
		stack<vector<int>> s;//栈，先进后出
		if (root!=NULL)
		{
			q.push(root);
			while (!q.empty())
			{
				vector<int> temp;
				int qSize = q.size();
				for (int i=0;i<qSize;i++)
				{
					TreeNode* front = q.front();
					temp.push_back(front->val);
					q.pop();
					if (front->left != NULL) q.push(front->left);
					if (front->right != NULL) q.push(front->right);
				}
				s.push(temp);//先加入到栈中
			}
			while (!s.empty())
			{
				res.push_back(s.top());
				s.pop();
			}
		}
		return res;
	}
};
```