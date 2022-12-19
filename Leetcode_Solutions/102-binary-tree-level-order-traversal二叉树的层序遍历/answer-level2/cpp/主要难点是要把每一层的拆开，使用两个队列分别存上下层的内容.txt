队列q1存上层的内容，q2存q1下一层的内容。
中间q1若为空表示上一层内容的子节点全都加入q2了，这时要把q2中非空的节点值全读出来，并且这些节点放到q1中去。

```C++ []
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q1, q2;
		q2.push(root);
		while (!q2.empty()) {
			vector<int> v;
			while (!q2.empty()) {
				if (!q2.front()) {
					q2.pop();
					continue;
				}
				v.push_back(q2.front()->val);
				q1.push(q2.front());
				q2.pop();
			}
			if(!v.empty())
				res.push_back(v);

			while (!q1.empty()) {
				if (!q1.front()) {
					q1.pop();
					continue;
				}
				q2.push(q1.front()->left);
				q2.push(q1.front()->right);
				q1.pop();
			}
		}
		return res;
	}
};
```
