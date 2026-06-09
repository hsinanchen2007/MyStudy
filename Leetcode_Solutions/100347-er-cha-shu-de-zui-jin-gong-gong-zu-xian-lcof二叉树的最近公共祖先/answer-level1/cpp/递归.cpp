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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        if(root==p || root==q)return root;
        TreeNode* ln=lowestCommonAncestor(root->left,p,q);
        TreeNode* rn=lowestCommonAncestor(root->right,p,q);
        if(ln!=NULL&& rn!=NULL)return root;
        if(ln==NULL)return rn;
        if(rn==NULL)return ln;
        return NULL;
    }
};
```