### 解题思路
执行用时 : 12 ms, 在所有 C++ 提交中击败了93.99%的用户
内存消耗 : 22.7 MB, 在所有 C++ 提交中击败了100.00%的用户

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
private:
    int i {0};
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size());
    }
    TreeNode* helper(vector<int>& nums, int bgn, int end)
    {
        if(bgn >= end) return nullptr;
        int mid = (bgn + end) / 2;        
        TreeNode* node = new TreeNode(0);
        node->left = helper(nums, bgn, mid);
        node->val = nums[i++];
        node->right = helper(nums, mid + 1, end);
        return node;
    }
};
```