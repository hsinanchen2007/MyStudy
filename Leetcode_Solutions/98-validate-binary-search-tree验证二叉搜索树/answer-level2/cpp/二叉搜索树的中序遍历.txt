# 非递归
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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left==NULL&&root->right==NULL)
            return true;
        stack<TreeNode*> s;
        int pre;
        bool flag=false;
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
                if(root->val<=pre&&flag)
                    return false;
                pre=root->val;
                flag=true;
                root=root->right;
            }
                
        }
        return true;
    }
};
```

