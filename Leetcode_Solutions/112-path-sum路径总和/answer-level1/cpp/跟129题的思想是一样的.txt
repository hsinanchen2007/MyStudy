### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了99.92% 的用户
内存消耗 :20 MB, 在所有 C++ 提交中击败了5.09%的用户

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
	void hasPathSumDFS(TreeNode* root, int path_sum, const int& target_sum, bool& has_path_sum){
		if(!root) return;
		path_sum += root->val;
		if(!root->left && !root->right){
            //cout << "path_sum = " << path_sum << endl;
			if(path_sum == target_sum)
				has_path_sum = true;
//			cout << "path_sum = " << path_sum << endl;
			return;
		}
		hasPathSumDFS(root->left, path_sum, target_sum, has_path_sum);
		hasPathSumDFS(root->right, path_sum, target_sum, has_path_sum);
	}
    bool hasPathSum(TreeNode* root, int sum) {
    	int path_sum = 0;
    	bool has_path_sum = false;
    	hasPathSumDFS(root, path_sum, sum, has_path_sum);
    	return has_path_sum;
    }
};
```