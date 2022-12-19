右根左遍历所有节点，并更新当前节点值为其与前一节点的值（初始为0）相加
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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return root;
        TreeNode* res=root;
        int pre=0;
        stack<TreeNode*> s;
        while(root||s.size())
        {
            if(root)
            {
                s.push(root);                
                root=root->right;
            }
            else
            {
                root=s.top();                
                root->val+=pre;
                pre=root->val;
                s.pop();
                root=root->left;
            }
        }
        return res;
        
    }
};
```