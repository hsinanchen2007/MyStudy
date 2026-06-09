### 代码

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return (!root)? NULL:(root->val==val? root :(root->val>val)?searchBST(root->left,val):searchBST(root->right,val));
    }
};
```