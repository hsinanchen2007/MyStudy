### 解题思路
执行用时 :32 ms, 在所有 C++ 提交中击败了37.50% 的用户
内存消耗 :25 MB, 在所有 C++ 提交中击败了100.00%的用户

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
	void kthLargestTraverseTree(TreeNode* root, set<int, std::greater<int>>& s_nodes){
		if(!root) return;
		s_nodes.insert(root->val);
		kthLargestTraverseTree(root->left, s_nodes);
		kthLargestTraverseTree(root->right, s_nodes);
	}
    int kthLargest(TreeNode* root, int k) {
    	set<int, std::greater<int>> s_nodes;
    	kthLargestTraverseTree(root, s_nodes);
    	auto ind = s_nodes.begin();
    	std::advance(ind, k-1);
    	return *ind;
    }
};
```