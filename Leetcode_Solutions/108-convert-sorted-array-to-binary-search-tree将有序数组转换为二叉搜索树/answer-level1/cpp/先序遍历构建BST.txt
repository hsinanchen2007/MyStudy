```
class Solution {
    TreeNode *preorder(vector<int> &nums, int begin, int back){
        if(begin>back) return NULL;
        int mid = (begin+back)/2;
        TreeNode *r = new TreeNode(nums[mid]);
        r->left = preorder(nums, begin, mid-1);
        r->right = preorder(nums, mid+1, back);
        return r;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return preorder(nums, 0, nums.size()-1);
    }
};
```
