
![image.png](https://pic.leetcode-cn.com/be160ddb0ae59adebcf4e83715400caac99bd3eaf2c796206729f9b7080df369-image.png)
```c++
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
   // 目前的全局最优解
int recuMaxPathSum(TreeNode* root, int & global_max_path) {
	if (root == NULL)
		return 0;

	int left_path_sum = recuMaxPathSum(root->left, global_max_path);
	int right_path_sum = recuMaxPathSum(root->right, global_max_path);
	int local_max_path = root->val + max(0,max(left_path_sum, right_path_sum));
	global_max_path = max(left_path_sum + right_path_sum + root->val, global_max_path);
	global_max_path = max(local_max_path, global_max_path);
	return local_max_path;
}
int maxPathSum(TreeNode* root) {
	int global_val = INT_MIN;
	return max(recuMaxPathSum(root, global_val),global_val);
}
};
```
