```
class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode* root=NULL;
		bfs(&root, nums, 0, nums.size()-1);
		return root;
	}

	TreeNode* bfs(TreeNode**node, vector<int>& nums, int m, int n) {
		if (n<m) return NULL;
		int k = findMaxValue(nums, m, n);
		*node = new TreeNode(nums[k]);

		TreeNode* leftnode = bfs(&(*node)->left, nums, m, k-1);
		TreeNode* rightnode = bfs(&(*node)->right, nums, k+1, n);
		(*node)->left = leftnode;
		(*node)->right = rightnode;
		return *node;
	}

	int findMaxValue(vector<int>& nums, int m, int n) {
		int maxval = nums[m];
		int maxkey = m;
		for (int i = m; i <= n; i++) {
			if (nums[i]>maxval) {
				maxval = nums[i];
				maxkey = i;
			}
		}
		return maxkey;
	}
};
```
