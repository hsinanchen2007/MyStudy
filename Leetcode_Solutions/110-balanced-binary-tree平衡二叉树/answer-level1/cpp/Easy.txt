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
    Solution(){flag=true;}
    bool flag;
    int maxlength(TreeNode *root){
       if(root==NULL)
           return 0;
        else
            return max(maxlength(root->left),maxlength(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root!=NULL&&abs(maxlength(root->left)-maxlength(root->right))>1)
            flag=false;
        isBalanced(root->left);
        isBalanced(root->right);
        if(flag==false)
            return false;
        else
            return true;
    }
};
```