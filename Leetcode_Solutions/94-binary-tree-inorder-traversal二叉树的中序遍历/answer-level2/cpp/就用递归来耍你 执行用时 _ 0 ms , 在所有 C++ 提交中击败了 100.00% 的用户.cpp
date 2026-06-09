### 解题思路
此处撰写解题思路

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
private:
    vector<TreeNode*> m_nodes;
public:
	void inorderTraversalCore(TreeNode* root){
		if(!root) return;
		inorderTraversalCore(root->left);
		m_nodes.push_back(root);
		inorderTraversalCore(root->right);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> vals;
		inorderTraversalCore(root);
		for(auto& iter:m_nodes){
			vals.push_back(iter->val);
		}
		return vals;
	}
};
```