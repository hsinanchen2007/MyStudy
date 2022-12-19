``` C++
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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* dummy=new TreeNode(0);
        TreeNode* node=dummy;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size())
        {
            root=s.top();
            s.pop();
            node->right=root;
            node->left=NULL;
            node=node->right;
            if(root->right) s.push(root->right);
            if(root->left) s.push(root->left);            
        }
        root=dummy->right;
    }
};
```