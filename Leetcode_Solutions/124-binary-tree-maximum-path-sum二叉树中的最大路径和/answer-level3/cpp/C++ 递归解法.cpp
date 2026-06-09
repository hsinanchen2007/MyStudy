### 代码

```cpp
class Solution {
    int max_sum = INT_MIN;
public:
    int max_gain(TreeNode* node) {
        if(!node)  
            return 0;
        int left_gain = max(max_gain(node->left), 0);
        int right_gain = max(max_gain(node->right), 0);
        int newpath = node->val + left_gain + right_gain;
        max_sum = max(max_sum, newpath);
        return node->val + max(left_gain, right_gain);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};



```