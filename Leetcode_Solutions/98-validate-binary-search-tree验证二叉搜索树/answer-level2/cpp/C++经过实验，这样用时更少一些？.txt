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
        if(root==NULL) return 1;
        return Jg(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
    bool Jg(TreeNode* root, long lowbd, long higbd) {
        if (root==NULL)
           return true;
        long num = root->val;
        if (num<=lowbd||num>=higbd) 
            return false;
        return Jg(root->left,lowbd,num) && Jg(root->right, num, higbd);
    }
};  
```