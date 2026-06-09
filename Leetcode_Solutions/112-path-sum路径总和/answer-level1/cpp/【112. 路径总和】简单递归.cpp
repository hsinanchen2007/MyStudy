## 思路
向下递归中不断递减目标和，当遇到叶子节点时判断减去之和是否等于0。
### 代码
```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return sum-root->val == 0;
        }
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
```
#### 另一种写法
不断累加和
```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, sum, 0);
    }
    bool helper(TreeNode *root, int sum, int start) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return start+root->val == sum ? true : false;
        }
        bool left = false;
        if (root->left != nullptr) {
            left = helper(root->left, sum, start + root->val);
        }
        bool right = false;
        if (root->right != nullptr) {
            right = helper(root->right, sum, start + root->val);
        }        
        return left || right;
    }
};
```

