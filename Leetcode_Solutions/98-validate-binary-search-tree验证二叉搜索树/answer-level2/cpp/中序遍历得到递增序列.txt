### 解题思路
此处撰写解题思路

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
    long long preValue = -INT_MAX;
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        // 遍历左子树
        if (!isValidBST(root->left)) {
            return false;
        }
        //判断preValue是否为空
        if (preValue != -INT_MAX && (root->val <= preValue)) {
            return false;
        }
        // 更新preValue的值
        preValue = root->val;

        return isValidBST(root->right);
    }
};
```