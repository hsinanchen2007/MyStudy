```
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums,0,nums.size()-1);
    }
    
    TreeNode* func(vector<int>& nums,int l,int r){
        if(l>r)
            return NULL;
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = func(nums,l,mid-1);
        root->right = func(nums,mid+1,r);
        return root;
    }
};
```
