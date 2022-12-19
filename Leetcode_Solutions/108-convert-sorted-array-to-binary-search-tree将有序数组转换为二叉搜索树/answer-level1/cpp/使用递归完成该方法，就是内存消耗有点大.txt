```
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getNewTree(0, nums.size()-1, nums);
    }
    TreeNode * getNewTree(int start, int end, vector<int> nums){
        if(start > end) return NULL;
        else if(start == end)
            return new TreeNode(nums[start]);
        else {
            int mid = (end+start)/2 ;
            TreeNode * root = new TreeNode(nums[mid]);
            root->left = getNewTree(start, mid-1, nums);
            root->right = getNewTree(mid+1, end, nums);
            return root;
        }
    }
};
```
