### 解题思路
注意本题要跟树的子结构区分开来

因为判断子树的函数hasSubTree，返回true或false的条件也略有不同

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
    bool hasSubTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) {
            return true;
        }
        if ((s != nullptr && t == nullptr) || (s == nullptr && t != nullptr) ) {
            return false;
        }

        if (s->val != t->val) {
            return false;
        }

        return hasSubTree(s->left, t->left) && hasSubTree(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {

        bool res = false;
        if (s != nullptr && t != nullptr) {
            if (s->val == t->val) {
                res = hasSubTree(s, t);
            }
            if (!res) {
                res = isSubtree(s->left, t);
            }
            if (!res) {
                res = isSubtree(s->right, t);
            }
        }
        return res;
    }
};
```