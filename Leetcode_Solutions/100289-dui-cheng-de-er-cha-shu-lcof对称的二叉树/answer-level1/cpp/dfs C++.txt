### 解题思路


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
        if(root==nullptr) return true;
        return helper(root->left,root->right);    
    }
    bool helper(TreeNode* L,TreeNode* R){
        if(L==nullptr && R==nullptr) return true;
        if(L==nullptr || R==nullptr) return false;
        if(L->val == R ->val){
            return helper(L->left,R->right) && helper(L->right,R->left);
        }else return false;
    }
};
```