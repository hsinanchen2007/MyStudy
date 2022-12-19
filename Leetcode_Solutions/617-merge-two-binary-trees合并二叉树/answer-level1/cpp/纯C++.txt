### 解题思路
纯C++ 递归

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (nullptr == t1)
        {
            return t2;
        }

        if (nullptr == t2)
        {
            return t1;
        }

        auto root = t1;
        root->val += t2->val;

        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);

        return root;
    }
};
```