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
    vector<TreeNode*> m_nodes;
public:
	void preOrder(TreeNode* root){
		if(!root) return;
		m_nodes.push_back(root);
		preOrder(root->left);
		preOrder(root->right);
	}
    void flatten(TreeNode* root)
    {
    	if(!root) return;
    	preOrder(root); // push the sorted nodes into vector<TreeNode*> m_nodes
    	root->left = NULL;
    	for(size_t i=1;i<m_nodes.size();++i){
    		TreeNode* new_node = new TreeNode(m_nodes[i]->val);
    		root->right = new_node;
    		root = root->right;
    	}
    }
    /*void flatten(TreeNode* root)
    {
    	if(!root) return;
    	preOrder(root); // push the sorted nodes into vector<TreeNode*> m_nodes
    	TreeNode* root_bak = root;
    	root_bak->left = NULL;
    	for(size_t i=1;i<m_nodes.size();++i){
    		TreeNode* new_node = new TreeNode(m_nodes[i]->val);
    		root_bak->right = new_node;
    		root_bak = root_bak->right;
    	}
    }*/
};
```