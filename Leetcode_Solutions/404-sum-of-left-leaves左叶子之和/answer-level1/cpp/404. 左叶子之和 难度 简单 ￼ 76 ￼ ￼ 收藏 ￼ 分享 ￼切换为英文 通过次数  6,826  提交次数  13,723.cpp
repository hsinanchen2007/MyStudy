具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/404.sum_of_left_leaves)  

```
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
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0;
        if(!root) return res;
        if(!root->left && !root->right) return res;
        if(root->left && !root->left->left && !root->left->right  ) 
            res+=root->left->val;
        else if(root->left)
            res+=sumOfLeftLeaves(root->left);
        if(root->right)
            res+=sumOfLeftLeaves(root->right);
        return res;
    }
};
```

> 执行用时 : 8 ms, 在Sum of Left Leaves的C++提交中击败了93.86% 的用户  
内存消耗 : 13.6 MB, 在Sum of Left Leaves的C++提交中击败了78.97% 的用户