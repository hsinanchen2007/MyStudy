```
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> view;	//按层遍历的最后一个节点
		queue<pair<TreeNode*, int>> Q;	//广度优先搜索队列<节点，层数>

		if (root) {		//节点非空时，将<root,0>入队
			Q.push(make_pair(root, 0));
		}

		while (!Q.empty()) {
			TreeNode* node = Q.front().first;//搜索节点
			int depth = Q.front().second;	//待搜索节点的层数
			Q.pop();
			if (view.size() == depth) {
				view.push_back(node->val);
			}
			else {
				view[depth] = node->val;
			}
			if (node->left) {
				Q.push(make_pair(node->left, depth + 1));
			}
			if (node->right) {
				Q.push(make_pair(node->right, depth + 1));
			}
		}
		return view;
	}
};
```
