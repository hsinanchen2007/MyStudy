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
    bool isSymmetric(TreeNode* root) {
        bool t = true;
        if(root!=NULL)
            t = test(root->left,root->right);
        return t;
    }
    bool test(TreeNode* a,TreeNode* b){
        if(a==NULL&&b==NULL)
            return true;
        if(a==NULL||b==NULL)
            return false;
        if(a->val!=b->val)
            return false;
        return test(a->left,b->right)&&test(a->right,b->left);
    }
};
```