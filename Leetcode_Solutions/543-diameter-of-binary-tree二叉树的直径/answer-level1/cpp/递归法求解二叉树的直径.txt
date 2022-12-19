### 解题思路
递归法：从根节点出发，递归分别遍历其左子树与右子树的最大节点数量；
那么以当前节点为根节点的子树的最大节点数为max(其左子树的最大节点数, 其右子树的最大节点数) + 当前节点，即max(left, right) + 1；
此子树所构成的路径中，包含的最多节点数量为  其左子树的最大节点数 + 其右子树的最大节点数 + 当前节点，即left + right + 1。
依次递归二叉树中的每一个节点，求得包含最多节点数量的路径。此路径的长度为节点数量 - 1，即二叉树的直径。
![捕获.JPG](https://pic.leetcode-cn.com/652c00b66dfba698ead520fbc2810b5b865daa06b87355a8cf8b04303808fc6f-%E6%8D%95%E8%8E%B7.JPG)

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
    int result = 1;
public:
    int backtrack(TreeNode* root) {
        if (root == NULL) {return 0;}
        int left = backtrack(root->left);
        int right = backtrack(root->right);
        result = max(result, left + right + 1);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        backtrack(root);
        return result - 1;
    }
};
```