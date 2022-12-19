## 思路
**注意：递归返回值并不是我们最终需要的值**
递归返回值为包含当前节点值的单边最大路径和，可能存在三种情况：
- 只有root
- root+left
- root+right

在递归过程中需要更新最大值，因为最大值路径可能经过当前节点包含两边。在`maxSum = max(maxSum, left + right + root->val)`中，第二个maxSum包含root->left和root->right的最大值，如果 `left + right + root->val < maxSum` ,则说明最大值不包含root节点，也就是说最大值就是root->left或root->right。

### 代码
```c++
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;       
    }
    int helper(TreeNode* root, int &maxSum) {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0, helper(root->left, maxSum));
        int right = max(0, helper(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return root->val + max(left, right);
    }
};
```

#### 另一种写法
```c++
class Solution {
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        maxSum = max(maxSum, left + right + root->val);
        return root->val + max(left, right);
    }
};
```

