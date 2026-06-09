1. 通过map记录每个节点的下一距离节点（父节点或子节点）
2. 用标记记录每个节点的是否访问过，避免重复访问
3. dfs搜索搜索长度符合的结点，放进数组
```
class Solution {
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		map<int, vector<int>>dis;
		map<int, bool>flags;
		vector<int>ans;
		if (root) creat_hash(root, dis);
		for (auto d : dis) flags[d.first] = false;
		dfs(dis, ans, flags, target->val, K);
		return ans;
	}
	void creat_hash(TreeNode* root, map<int, vector<int>>& dis) {
		if (root->left) {
			dis[root->val].push_back(root->left->val);
			dis[root->left->val].push_back(root->val);
			creat_hash(root->left, dis);
		}
		if (root->right) {
			dis[root->val].push_back(root->right->val);
			dis[root->right->val].push_back(root->val);
			creat_hash(root->right, dis);
		}
		return;
	}
	void dfs(map<int, vector<int>>& dis, vector<int>& ans, map<int, bool>& flags, int target, int K) {
		flags[target] = true;
		if (K == 0) {
			ans.push_back(target);
			flags[target] = true;
		}

		if (K > 0) {
			if (!dis.count(target)) return;
			for (int num : dis[target]) {
				if(flags[num]==false) dfs(dis, ans, flags, num, K - 1);
			}
		}
	}
};
```
