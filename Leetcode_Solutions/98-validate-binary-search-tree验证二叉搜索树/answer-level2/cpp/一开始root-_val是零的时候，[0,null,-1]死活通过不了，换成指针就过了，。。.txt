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
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
    bool helper(TreeNode* root,int* low,int* high){
        if(root==NULL) return true;
        int* val;
        val=&root->val;

        if(low!=NULL && *val<=*low) return false;
        if(high!=NULL && *val>=*high) return false;

        if(!helper(root->right,val,high)) return false;
        if(!helper(root->left,low,val)) return false;
        return true; 
    }
};
```