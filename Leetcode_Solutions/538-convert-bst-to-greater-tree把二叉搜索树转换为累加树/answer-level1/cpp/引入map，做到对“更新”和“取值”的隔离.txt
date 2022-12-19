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
    map<TreeNode*, int> m_updated_nodes;
public:
	void convertBSTPreOrder(TreeNode* root){
		if(!root) return;
		m_nodes.push_back(root);
		convertBSTPreOrder(root->left);
		convertBSTPreOrder(root->right);
	}
	void convertBSTUpdateMap(TreeNode* root){
		if(!root) return;
		auto ind = std::find(m_nodes.begin(), m_nodes.end(), root);
		if(ind != m_nodes.end()){
			int sum = root->val;
			int ind_begin = ind - m_nodes.begin() + 1;
			for(size_t i=ind_begin;i<m_nodes.size();++i){
				sum += m_nodes[i]->val;
				//cout << " += " << m_nodes[i]->val << endl;
			}
			m_updated_nodes[root] = sum;
		}
		convertBSTUpdateMap(root->left);
		convertBSTUpdateMap(root->right);
	}
	void convertBSTRefreshTree(TreeNode* root){
		if(!root) return;
		root->val = m_updated_nodes[root];
		convertBSTRefreshTree(root->left);
		convertBSTRefreshTree(root->right);
	}
    TreeNode* convertBST(TreeNode* root) {
    	convertBSTPreOrder(root);
    	std::sort(m_nodes.begin(), m_nodes.end(), [](const TreeNode* l, const TreeNode* r){
    		return l->val <= r->val;
    	});
    	convertBSTUpdateMap(root);
    	convertBSTRefreshTree(root);

    	return root;
    }
};
```