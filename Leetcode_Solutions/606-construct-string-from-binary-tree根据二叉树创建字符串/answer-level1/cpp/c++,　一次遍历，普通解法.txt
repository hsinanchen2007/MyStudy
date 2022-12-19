### 解题思路
根据题意，根节点不加括号，一有左子树就要加括号，右子树相同；
需要注意的是如果左子树为空右子树不为空，此时需要加一对圆括号即可；

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
        if (t == NULL) {
            return "";
        }
        string res;
        PreOrder(t, res);
        return res;
    }
    void PreOrder(TreeNode* root, string& res) {
        if (root == NULL) {
            return ;
        }
        res += to_string(root->val);
        if (root->left == NULL && root->right) {
            res += "()";
        }
        if (root->left) {
            res += "(";
            PreOrder(root->left, res);
            res += ")";
        }
        if (root->right) {
            res += "(";
            PreOrder(root->right, res);
            res += ")";
        }
    }
};
```