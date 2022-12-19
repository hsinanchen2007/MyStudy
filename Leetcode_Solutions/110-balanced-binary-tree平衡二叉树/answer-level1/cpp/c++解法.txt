

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        if(heightHelper(root) == -1)return false;
        return true;
    }
    int heightHelper(TreeNode* root){
        if(root == NULL) return 0;
        int leftHeight = heightHelper(root->left);
        int rightHight = heightHelper(root->right);
        if(leftHeight == -1 || rightHight == -1) return -1;
        if(abs(leftHeight - rightHight) > 1) return -1;
        return max(leftHeight,rightHight) + 1;
    }
};
```