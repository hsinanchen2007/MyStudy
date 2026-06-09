### 解题思路
对于左右展开合并，一种方法是遍历，找到左子树最后一个可用的点
另一种思路是，每次返回当前展开队列的最后一个可用点

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
    TreeNode* merge(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* l = merge(root->left);
        TreeNode* r = merge(root->right);   
        if (root->left) {
            l->right = root->right;
            root->right = root->left;
            root->left= NULL;
        }
        if (r) return r;
        if (l) return l;
        return root;
    }
    void flatten(TreeNode* root) {
        merge(root);
    }
};
```