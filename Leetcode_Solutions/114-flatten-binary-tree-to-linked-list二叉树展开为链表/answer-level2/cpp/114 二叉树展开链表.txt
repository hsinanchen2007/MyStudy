### 解题思路
1.左子树展开
2.右子树展开
3.合并
ps:别忘了把左子树置空
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
    void flatten(TreeNode* root) {
        if (!root) return;
        cout << root->val << endl;
        flatten(root->left);
        flatten(root->right);   
        if (root->left) {
            TreeNode * cur = root->left;
            while (cur->right) {
                cur = cur->right;
            }
            cur->right = root->right;
            root->right = root->left;
            root->left= NULL;
        }
    }
};
```