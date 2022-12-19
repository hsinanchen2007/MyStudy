### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了97.19% 的用户
内存消耗 :17.3 MB, 在所有 C++ 提交中击败了13.26%的用户

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
	void sumRootToLeafDFS(TreeNode* root, int path_sum, int& all_path_sum){
		if(!root) return;
		path_sum = (path_sum << 1) + root->val;
		if(!root->left && !root->right){
			//cout << "path_sum = " << path_sum << endl;
			all_path_sum += path_sum;
			return;
		}
		sumRootToLeafDFS(root->left, path_sum, all_path_sum);
		sumRootToLeafDFS(root->right, path_sum, all_path_sum);
	}
    int sumRootToLeaf(TreeNode* root) {
    	int path_sum = 0;
    	int all_path_sum = 0;
    	sumRootToLeafDFS(root, path_sum, all_path_sum);
    	return all_path_sum;
    }
};
```