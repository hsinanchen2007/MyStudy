## 思路一：自上到下

### 代码
时间复杂度：O(n^2)
空间复杂度：O(nlogn)
```c++
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if (abs(left-right) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        return max(left, right)+1;
    }
};
```

## 思路二：自下到上

### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int dfsdepth = depth(root);
        return dfsdepth != -1;
    }
    int depth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = depth(root->left);
        if (left == -1) {
            return -1;
        }
        int right = depth(root->right);
        if (right == -1) {
            return -1;
        }
        if (abs(left-right) > 1) {
            return -1;
        }
        return max(left, right)+1;
    }
};
```
