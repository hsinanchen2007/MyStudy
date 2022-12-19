感觉答案有问题，root为空时，如果和是0，应该返回true，答案返回false
正确应是 
``` c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (nullptr == root) return 0 == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val)
    }
};
```
