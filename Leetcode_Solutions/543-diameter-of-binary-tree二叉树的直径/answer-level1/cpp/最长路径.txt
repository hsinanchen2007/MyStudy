### 解题思路
关键是得到以某节点为根，且经过该节点的路径，与左子树深度和右子树深度的关系。
在求深度的函数中，加入max_noode的比较取最大值即可。

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
private:
    int max_node;
public:
    int depth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        max_node = max(max_node, L+R+1);
        return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        max_node = 0;
        depth(root);
        return max_node - 1;

    }
};
```