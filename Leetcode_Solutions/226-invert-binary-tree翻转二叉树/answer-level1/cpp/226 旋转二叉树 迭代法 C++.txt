### 解题思路
迭代法，将每个阶段入队列，对队列每个元素左右节点互换
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* l =invertTree(root->left);
        TreeNode* r =invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};
```