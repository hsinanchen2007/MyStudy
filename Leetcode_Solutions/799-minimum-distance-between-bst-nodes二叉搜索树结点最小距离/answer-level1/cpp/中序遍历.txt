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
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 0;
        int minN=(1<<31)-1;
        stack<TreeNode*> s;
        TreeNode* pre=NULL;
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
                if(pre)
                {
                    int temp=(root->val>pre->val)?(root->val-pre->val):(pre->val-root->val);
                    minN=(minN<temp)?minN:temp;
                }
                pre=root;//更新pre
                root=root->right;
            }
        }
        return minN;
    }
};
```