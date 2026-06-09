递归解法：
```
class Solution {
public:
    TreeNode* genBST(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        if(left == right) return new TreeNode(nums[left]);
        int mid = (left+right)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = genBST(nums, left, mid-1);
        root->right = genBST(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return genBST(nums, 0, nums.size()-1);
    }
};
```
