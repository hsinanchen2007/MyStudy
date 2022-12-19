### 解题思路
前序遍历

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
    double last = -DBL_MAX;
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(isValidBST(root->left)){
            if(last < root->val){
                last = root->val;
                return isValidBST(root->right);
            }
        }
        return false;
    }
};
```