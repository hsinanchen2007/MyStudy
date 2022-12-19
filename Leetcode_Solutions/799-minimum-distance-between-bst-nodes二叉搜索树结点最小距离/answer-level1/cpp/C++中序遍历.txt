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
    int pre=NULL,ans=INT_MAX;
    int minDiffInBST(TreeNode* root) {
       if(root==NULL) return NULL;
       minDiffInBST(root->left);
       if(pre!=NULL)
        ans=min(ans,root->val-pre);
        pre=root->val;
        minDiffInBST(root->right);
        return ans;
    }
};
```