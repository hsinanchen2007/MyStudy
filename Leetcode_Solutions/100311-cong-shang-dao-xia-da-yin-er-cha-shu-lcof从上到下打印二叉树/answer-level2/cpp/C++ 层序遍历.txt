### 解题思路


### 代码

```cpp
class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		queue<TreeNode* > q;
		vector<int> v;
		if(root!=NULL) 
		{
			q.push(root);//首结点不为null则入队
			while (!q.empty())
			{
				TreeNode* front = q.front();
				v.push_back(front->val);
				q.pop();//出队
				if (front->left != NULL) q.push(front->left);
				if (front->right != NULL) q.push(front->right);
			}
		}
		return v;
	}
};
```