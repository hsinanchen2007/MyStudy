### 解题思路
递归注意判断条件：不能直接用1 + min(left, right)，不然会出现单边子树为空则直接返回0了。这是不符合题意的：题意为到叶子节点的距离，即两个子树均为空才行，一个子树为空不算叶子

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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        if (root->left == NULL)
            return 1 + minDepth(root->right);
        else if (root->right == NULL)
            return 1 + minDepth(root->left);
        else
            return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
```