### 解题思路
此处撰写解题思路
写出来一看和大家一样的吧
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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return rever(root->left,root->right);
    }
    bool rever(TreeNode *L,TreeNode *R){
        if(L==NULL&&R==NULL) return true;
        if(L==NULL||R==NULL) return false;
        if(L->val!=R->val) return false;
        return rever(L->left,R->right)&&rever(L->right,R->left);
    }

};
```