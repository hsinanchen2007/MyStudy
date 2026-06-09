```
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return mksub(nums, 0, nums.size()-1);
    }
    TreeNode *mksub(vector<int>&nums, int i, int j)
    {
        int m = (i+j)/2;
        if (i>j)
        {
            return NULL;
        }
       else
        {
            TreeNode *root = new TreeNode(nums[m]);
            root->left = mksub(nums, i, m-1);
            root->right = mksub(nums, m+1, j);
            return root;
        }
    }
};
```
