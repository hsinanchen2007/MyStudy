```
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        while(left < right) {
            int mid = left + (right-left) / 2;
            TreeNode* p = new TreeNode(nums[mid]);
            p->left = dfs(nums, left, mid);
            p->right = dfs(nums, mid+1, right);
            return p;
        }
        return nullptr;
    }
};
```
