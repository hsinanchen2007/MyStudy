### 解题思路
怎么全是递归的题，主要是找最大值

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
int Max=0x80000000;
    int Sum(TreeNode* root) {
        if(!root)return 0;
        int nl=Sum(root->left),nr=Sum(root->right);
        root->val+=max(nl,nr);
        Max=max(Max,root->val);
        Max=max(Max,min(nl,nr)+root->val);
        if(root->val<=0)return 0;
        return root->val;
    }
    int maxPathSum(TreeNode* root){
        Sum(root);
        return Max;
    }
};
```