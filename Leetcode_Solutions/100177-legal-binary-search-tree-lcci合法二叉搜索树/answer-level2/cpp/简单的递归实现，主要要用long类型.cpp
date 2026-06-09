### 解题思路
递归实现

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
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL) return true;
        return isValid(root,LONG_MIN,LONG_MAX);
    }

    bool isValid(TreeNode* root,long min,long max){
        if(root==NULL) return true;
        else if(root->val<=min) return false;
        else if(root->val>=max) return false;
        return isValid(root->left,min,root->val)&&isValid(root->right,root->val,max);
    }
};
```