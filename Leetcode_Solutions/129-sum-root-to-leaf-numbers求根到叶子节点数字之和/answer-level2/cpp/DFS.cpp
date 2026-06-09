### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了84.67% 的用户
内存消耗 :12.8 MB, 在所有 C++ 提交中击败了14.65%的用户

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
	void sumNumberDFS(TreeNode* root, int path_sum, int& all_path_sum){
		if(!root) return;
		path_sum = path_sum * 10 + root->val;
		if(!root->left && !root->right){
//			cout << "path_sum = " << path_sum << endl;
			all_path_sum += path_sum;
			return;
		}
		sumNumberDFS(root->left, path_sum, all_path_sum);
		sumNumberDFS(root->right, path_sum, all_path_sum);
	}
	int sumNumbers(TreeNode* root) {
		int path_sum = 0;
		int all_path_sum = 0;
		sumNumberDFS(root, path_sum, all_path_sum);
		return all_path_sum;
	}
};
```