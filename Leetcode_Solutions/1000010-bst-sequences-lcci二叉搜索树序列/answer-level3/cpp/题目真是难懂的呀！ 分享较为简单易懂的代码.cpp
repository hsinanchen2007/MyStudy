我是阅读了 题解 如何通过例子得出解，才明白题目到底是啥意思

就是让你 把左右子节点能够构成的所有子集，按照排列组合弄成一个集，只有一个限制条件就是不能改变左右子集在新集中的顺序。
我下面的dfs函数干的就是这个任务。
然后用了个 set<vector<int>>来去重..
这段代码效率不咋地.你们看着还可以优化不少地方.但是可读性还是不错的

如果看其他人的代码觉得太长 可以看看这个.
```
class Solution {
	void dfs(vector<int> &left, int l, vector<int>& right, int r, set<vector<int>>& temp , vector<int>& cur) {
		if (l == left.size() && r == right.size()) {
			temp.insert(cur);
		}
		//两种选择,要么l+1,要么r+1;
		if (l < left.size()) {
			cur.push_back(left[l]);
			dfs(left, l + 1, right, r, temp, cur);
			cur.pop_back();
		}
		if (r < right.size()) {
			cur.push_back(right[r]);
			dfs(left, l, right, r + 1, temp, cur);
			cur.pop_back();
		}
	}
public:
	vector<vector<int>> BSTSequences(TreeNode* root) {
		if (!root) return { {} };
		vector<vector<int>> lefts = BSTSequences(root->left);
		vector<vector<int>> rights = BSTSequences(root->right);
		set<vector<int>> temp;
		vector<int> cur = { root->val };
		for (auto left : lefts) {
			for (auto right : rights) {
				dfs(left, 0, right, 0, temp,cur); //该函数可以获取由lefts和right所组成的所有子数组。
			}
		}
		vector<vector<int>> res(temp.begin(), temp.end());
		return res;
	}
};
```
