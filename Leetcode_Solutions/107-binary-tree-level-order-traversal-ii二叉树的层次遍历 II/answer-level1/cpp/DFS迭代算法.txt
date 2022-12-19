/*解法二：DFS迭代，
根据题104所做
*/
```
class Solution2 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res = vector<vector<int>>();
		stack<pair<TreeNode*, int>> st; //int代表每个节点有对应的深度
		int currdepth = 0;  //记录当前深度
		while (!st.empty() || root != nullptr) {
			while (root != nullptr) {
				st.push(pair<TreeNode* ,int>(root, ++currdepth));
				int curr = st.top().second - 1; //记录当前节点深度，减一是因为容器vector下标从0开始
				if (res.size() <= curr)
					res.push_back(vector<int>());
				res[curr].push_back(root->val); 
				root = root->left;
			}
			root = st.top().first;
			currdepth = st.top().second;
			st.pop();
			root = root->right;
		}
		return vector<vector<int>> (res.rbegin(),res.rend());
	}
};


