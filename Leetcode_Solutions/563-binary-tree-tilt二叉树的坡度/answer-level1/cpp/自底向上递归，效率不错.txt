
关于树的题目大部分都要用到递归，这道题也不例外
```cpp
class Solution {
public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        return helper(root, sum);
    }
    // sum是子树节点之和
    int helper(TreeNode* root, int &sum) {
        if(root == nullptr) {
            sum = 0;
            return 0;
        }
        int left, right;
        int a = helper(root->left, left);
        int b = helper(root->right, right);
        sum = left + right + root->val;
        return a + b + abs(left-right);
    }
};
```
