
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
    bool ans = true;
    long prevVal = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if(!root || ans == false)
            return true;
        isValidBST(root->left);
        if(root->val <= prevVal)
            ans = false;
        else
            prevVal = root->val;
        isValidBST(root->right);
        return ans;
    }
};
```