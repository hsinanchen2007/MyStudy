### 解题思路
极简思想，如标题接着来做差即可！！！

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
    int max1=INT_MIN;
    void preorder(TreeNode* root,int premin,int premax)
    {
        if(root)
        {
            if(premin==-1||root->val<premin)
                premin=root->val;
            if(premax==-1||root->val>premax)
                premax=root->val;
            if(abs(root->val-premax)>max1)
                max1=abs(root->val-premax);
            if(abs(root->val-premin)>max1)
                max1=abs(root->val-premin);
            preorder(root->left,premin,premax);
            preorder(root->right,premin,premax);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        preorder(root,-1,-1);
        return max1;
    }
};
```