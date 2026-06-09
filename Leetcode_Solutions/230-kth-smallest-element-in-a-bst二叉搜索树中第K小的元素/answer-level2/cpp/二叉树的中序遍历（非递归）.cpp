
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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return -1;
        stack<TreeNode*> s;
        int index=0;
        int res=-1;
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
                index++;
                if(index==k)
                {
                    res=root->val;
                    break;
                }
                root=root->right;
            }
        }
        return res;
    }
};
```