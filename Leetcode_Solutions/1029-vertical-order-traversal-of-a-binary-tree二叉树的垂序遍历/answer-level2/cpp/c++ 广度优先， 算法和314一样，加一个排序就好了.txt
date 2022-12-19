		class Solution {
		public:
			vector<vector<int>> verticalTraversal(TreeNode* root) {
				vector<vector<int>>res;
				if (root == nullptr) {
					return res;
				}
				map<int, vector<int>> resMap;
				map<int, vector<int>> tmpMap;
				queue<pair<TreeNode*, int>> offsetMap;
				offsetMap.emplace(make_pair(root, 0));
				int count = 0;
				while (!offsetMap.empty()) {
					count = offsetMap.size();
					while (count > 0) {
						auto node = offsetMap.front();
						offsetMap.pop();
						tmpMap[node.second].push_back(node.first->val);
						if (node.first->left) offsetMap.emplace(make_pair(node.first->left, node.second - 1));
						if (node.first->right) offsetMap.emplace(make_pair(node.first->right, node.second + 1));
						count--;
					}

					for (auto i : tmpMap) {
						sort(i.second.begin(), i.second.end());
						for (auto j : i.second) {
							resMap[i.first].push_back(j);
						}
						
					}

					tmpMap.clear();
				}
				for (auto i : resMap) {
					res.push_back(i.second);
				}
				return res;
			}
		};