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
public:
    void isSymmetricCore(TreeNode* root1, TreeNode* root2, bool& is_symmetric){
    	if(!root1 && !root2) return;
    	if((root1 && !root2) || (!root1 && root2)){
    		is_symmetric = false;
    		return;
    	}
    	if(root1->val != root2->val){
    		is_symmetric = false;
    		return;
    	}
    	isSymmetricCore(root1->left, root2->right, is_symmetric);
    	isSymmetricCore(root1->right, root2->left, is_symmetric);
    }
    bool isSymmetric(TreeNode* root){
    	if(!root) return true;
    	TreeNode* root1 = root->left;
    	TreeNode* root2 = root->right;
    	bool is_symmetric = true;
    	isSymmetricCore(root1, root2, is_symmetric);
    	return is_symmetric;
    }
};
```