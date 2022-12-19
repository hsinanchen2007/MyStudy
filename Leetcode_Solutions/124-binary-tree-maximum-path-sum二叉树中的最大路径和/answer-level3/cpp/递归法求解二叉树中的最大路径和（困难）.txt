### 解题思路
递归法

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
    int maxPathSum(TreeNode* root, int& result) {
        if (root == NULL) {return 0;}
        int leftMax = maxPathSum(root->left, result);
        int rightMax = maxPathSum(root->right, result);
        // 左中右
        int lmr = max(0, leftMax) + root->val + max(0, rightMax);
        // 左中、右中
        int ret = root->val + max(0, max(leftMax, rightMax));
        result = max(result, max(lmr, ret));
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxPathSum(root, result);
        return result;
    }
};
```