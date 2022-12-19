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
    TreeNode* pruneTree(TreeNode* root) {
        Cut(root);
        return root;
    }
    bool Cut(TreeNode*& root){
        if(root==NULL) return false;
        bool l=Cut(root->left);
        bool r=Cut(root->right);
        if(!l&&!r&&root->val==0) 
            {root=NULL;return false;}
        return true;
    }
};
```