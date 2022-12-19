题目虽然简单，但是一不留神就会出错
上代码
```
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL && root->val == sum) return true;
        if (root->left != NULL && hasPathSum(root->left, sum - (root->val))) return true;
        if (root->right != NULL && hasPathSum(root->right, sum - (root->val))) return true;
        return false;
    }
};
```
![image.png](https://pic.leetcode-cn.com/0979f5a9d5308b55c7f1c421b1685c225b9b2abd607a7df39fe275521508ca0a-image.png)
