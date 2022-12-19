### 解题思路
树的所有节点与根节点的值进行比较  需要根节点、左子树、右子树 都等于该值

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
    bool isUnivalTree(TreeNode* root) {

        return is_unival_tree(root, root->val);
    }

    bool is_unival_tree(TreeNode* root, int val) {
        if(root == nullptr)
            return true;

        if(val != root->val)
            return false;

        return is_unival_tree(root->left, val) && is_unival_tree(root->right, val);
    }
};
```