BFS 一般都是用queue  这个题目用queue 不大合适，改用deque

```
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> ret;
		deque<TreeNode*> mydeque;
		mydeque.push_back(root);
		bool ltor = true;		
		while (!mydeque.empty()) {
			int length = mydeque.size();
			vector<int> curlevel;
			for (int i = 0; i < length; i++) {
				TreeNode* cur = mydeque[0];
				mydeque.pop_front();
				if (cur->left) mydeque.push_back(cur->left);
				if (cur->right) mydeque.push_back(cur->right);
				if (ltor) {
					curlevel.push_back(cur->val);
				}
				else {
					curlevel.insert(curlevel.begin(),cur->val);
				}				
			}
			ltor = !ltor;
			ret.push_back(curlevel);
		}
		return ret;
	}
```
