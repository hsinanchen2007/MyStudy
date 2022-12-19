### 解题思路
此处撰写解题思路
利用水平遍历即可完成。
把二叉树p和q的水平遍历（包括NULL节点）分别存储到vector<int>a和b当中，
比较a和b是否相同就行了（NULL节点在vector中是用-0xfffffff替代的）
### 代码

```cpp
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		std::vector<int>a, b;
		levelorderTraversal(a, p);
		levelorderTraversal(b, q);
		if (a == b)
			return true;
		else return false;
	}
	void levelorderTraversal(std::vector<int>& ans, TreeNode* p)
	{
		std::queue<TreeNode*> q;
		q.push(p);
		while (!q.empty()) {
			TreeNode* u = q.front();
			q.pop();
			if (u == nullptr) {
				ans.push_back(-0xfffffff);
				continue;
			}
			ans.push_back(u->val);
			q.push(u->left);
			q.push(u->right);
		}
		return;
	}
};
```