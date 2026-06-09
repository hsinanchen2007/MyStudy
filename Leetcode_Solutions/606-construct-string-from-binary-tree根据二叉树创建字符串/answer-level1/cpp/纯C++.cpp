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
    string tree2str(TreeNode* t) {
        if (nullptr == t)
        {
            return "";
        }

        const string s = std::to_string(t->val);
        const string left = tree2str(t->left);
        const string right = tree2str(t->right);

        if (nullptr == t->left && nullptr == t->right)
        {
            return s;
        }

        if (nullptr == t->right)
        {
            return s + "(" + left + ")";
        }

        return s + "(" + left + ")" + "(" + right + ")";
    }
};
```