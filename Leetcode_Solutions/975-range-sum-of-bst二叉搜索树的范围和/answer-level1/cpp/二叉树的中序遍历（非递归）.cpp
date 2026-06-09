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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL||L>R) 
            return 0;
        stack<TreeNode*> s;
        int res=0;
        while(s.size()||root)
        {
            if(root)
            {
                s.push(root);
                root=root->left;                
            }
            else
            {
                root=s.top();
                s.pop();
                if(root->val>=L&&root->val<=R)
                    res+=root->val;
                if(root->val>R)
                    return res;
                root=root->right;
            }
        }
        return res;
        
    }
};
```