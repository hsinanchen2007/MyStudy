### 解题思路
1. 思路参考的提示和其他人的解法才写出来，没什么特别的
2. 比较奇怪的是，这个函数其实是返回了包含2个或者只有1个的ancestor的情况。不用判断是否p、q在root里边，所以才能这么写。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        if (leftAns && rightAns) {
            return root;
        } else {
            return leftAns ? leftAns : rightAns;
        }
    }
};
```