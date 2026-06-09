### 解题思路
对于root节点到叶节点产生的数字，每次将当前结点的值加入到之前已有的整数中，组成新的数字
递归遍历当前结点的左右子树，同时携带本次新的数值

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
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode* root, int sum) {
        if (root == nullptr) {
            return sum;
        }
        sum = sum * 10 + root->val;
        if (root->left && !root->right) {
            return sumNumbers(root->left, sum);
        } else if (!root->left && root->right) {
            return sumNumbers(root->right, sum);
        } else if (root->left && root->right) {
            return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
        }
        return sum;
    }
};
```