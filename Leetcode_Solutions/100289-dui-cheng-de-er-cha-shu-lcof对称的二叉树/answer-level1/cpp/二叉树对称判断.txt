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
        bool res=true;
        if(root!=NULL)
        {
           res=helper(root->left,root->right);
        }
        return res;
    }
    
    bool helper(TreeNode* A,TreeNode* B)
    {
        if(A==NULL && B==NULL)
        {
            return true;
        }
        if(A==NULL || B==NULL)
        {
            return false;
        }
        if(A->val != B->val)
        {
            return false;
        }
        return helper(A->left,B->right) && helper(A->right,B->left);
    }
};
```
//递归 若发现递归至空则为出口，若A左与B右不同则说明不对称