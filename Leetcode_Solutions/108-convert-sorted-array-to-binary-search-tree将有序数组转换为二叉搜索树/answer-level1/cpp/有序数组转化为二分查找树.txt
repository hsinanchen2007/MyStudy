### 解题思路
二分加递归，主要是边界条件不好控制，摸索了很多遍

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int beg, int end){
        int mid = beg + (end - beg) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        if(beg < mid)
            node->left = sortedArrayToBST(nums, beg, mid - 1);
        if(mid < end)
            node->right = sortedArrayToBST(nums, mid + 1, end);
        return node;
    }
};
```