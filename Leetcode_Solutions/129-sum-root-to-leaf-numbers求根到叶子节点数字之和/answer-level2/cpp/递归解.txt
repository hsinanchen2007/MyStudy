### 解题思路
此处撰写解题思路

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
    int sumNumbers(TreeNode* root) {

        if (!root) return 0;

        function<void(TreeNode*, int, vector<int>&)> helper = 
                [&](TreeNode* node, int num, vector<int>& nums) {

            if (node) {
                num = num * 10 + node->val;
                if (!node->left && !node->right) {
                    nums.emplace_back(num);
                    return;
                }
                helper(node->left, num, nums);
                helper(node->right, num, nums);
            }
        };

        vector<int> nums;
        helper(root, 0, nums);

        return accumulate(nums.begin(), nums.end(), 0);
    }
};
```