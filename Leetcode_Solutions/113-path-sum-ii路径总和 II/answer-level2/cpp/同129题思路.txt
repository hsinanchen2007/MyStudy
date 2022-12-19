### 解题思路
执行用时 :32 ms, 在所有 C++ 提交中击败了22.86% 的用户
内存消耗 :37 MB, 在所有 C++ 提交中击败了13.13%的用户

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void hasPathSumIIDFS(TreeNode* root, int path_sum, const int& target_sum, vector<int> path, vector<vector<int>>& valid_paths){
		if(!root) return;
		path_sum += root->val;
		path.push_back(root->val);
		if(!root->left && !root->right){
//			cout << "path_sum = " << path_sum << endl;
			if(path_sum == target_sum){
				valid_paths.push_back(path);
			}
			return;
		}
		hasPathSumIIDFS(root->left, path_sum, target_sum, path, valid_paths);
		hasPathSumIIDFS(root->right, path_sum, target_sum, path, valid_paths);
	}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	int path_sum = 0;
    	vector<int> path;
    	vector<vector<int>> valid_paths;
    	hasPathSumIIDFS(root, path_sum, sum, path, valid_paths);
    	return valid_paths;
    }
};
```