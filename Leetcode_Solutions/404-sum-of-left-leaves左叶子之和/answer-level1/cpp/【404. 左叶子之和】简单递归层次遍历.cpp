### 思路一：递归


### 代码

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return sum;
    }

    void helper(TreeNode *root, int &sum) {
        if (root) {
            if (root->left) {
                if (!root->left->left && !root->left->right) {
                    sum += root->left->val;
                }             
            }
            helper(root->left, sum);
            helper(root->right, sum);
        }        
    }
};
```