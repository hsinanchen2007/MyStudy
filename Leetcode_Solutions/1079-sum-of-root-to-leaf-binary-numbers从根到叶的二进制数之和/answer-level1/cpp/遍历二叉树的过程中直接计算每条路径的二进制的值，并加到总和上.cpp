执行用时 : 4 ms, 在所有 C++ 提交中击败了 98.10% 的用户
内存消耗 : 16.9 MB, 在所有 C++ 提交中击败了 100.00% 的用户
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
    int sum = 0;
    void preAccess(TreeNode* root, int curSum)
    {
        if(root == NULL) return ;
        
        curSum = curSum * 2 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += curSum;
        }
        
        preAccess(root->left,curSum);
        
        preAccess(root->right,curSum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        preAccess(root,0);
        
        return sum;
    }
};
```