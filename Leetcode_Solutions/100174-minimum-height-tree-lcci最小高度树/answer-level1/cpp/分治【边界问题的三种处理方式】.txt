
老边界问题了。
改mid-1还是mid+1，边界处要改等号，递归开始前的范围也要挪动，mid也要向上取整或者向下取整

```
TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
    TreeNode* build(vector<int>& nums,int left,int right)
    {
        if(left>right)  return NULL;
        int mid=(left+right)/2;
        TreeNode* cur=new TreeNode(nums[mid]);
        cur->left=build(nums,left,mid-1);
        cur->right=build(nums,mid+1,right);
        return cur;
    }

TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,-1,nums.size()-1);
    }
    TreeNode* build(vector<int>& nums,int left,int right)
    {
        if(left==right)  return NULL;
        int mid=(left+right+1)/2;
        TreeNode* cur=new TreeNode(nums[mid]);
        cur->left=build(nums,left,mid-1);
        cur->right=build(nums,mid,right);
        return cur;
    }

TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size());
    }
    TreeNode* build(vector<int>& nums,int left,int right)
    {
        if(left==right)  return NULL;
        int mid=left+(right-left)/2;
        TreeNode* cur=new TreeNode(nums[mid]);
        cur->left=build(nums,left,mid);
        cur->right=build(nums,mid+1,right);
        return cur;
}
```