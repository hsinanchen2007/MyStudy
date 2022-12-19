### 代码

```cpp
class Solution {
public:
    TreeNode* changeToBST(vector<int>& nums, int l, int r) {
        if (l > r)return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = changeToBST(nums, l, mid - 1);
        root->right = changeToBST(nums, mid + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return changeToBST(nums, 0, nums.size() - 1);
    }
};
```