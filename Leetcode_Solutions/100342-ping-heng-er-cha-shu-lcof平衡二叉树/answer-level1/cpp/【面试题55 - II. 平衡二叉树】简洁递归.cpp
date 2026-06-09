## 思路一：自顶向下


### 代码
时间复杂度：O(n^2)，每个点访问两次
空间复杂度：O(nlogn)
```cpp
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = helper(root->left);
        int right = helper(root->right);
        if (abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int helper(TreeNode *root) {
        if (!root) return 0;
        return max(helper(root->left), helper(root->right)) + 1;
    }
};
```