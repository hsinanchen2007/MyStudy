```C++ []
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur||!st.empty()) {
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			cur = st.top();
			v.push_back(cur->val);
			st.pop();
			cur = cur->right;
		}
		return v;
	}
};
```
