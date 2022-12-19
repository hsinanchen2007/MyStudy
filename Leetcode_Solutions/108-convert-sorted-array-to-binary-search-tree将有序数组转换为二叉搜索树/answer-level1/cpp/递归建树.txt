执行用时 :16 ms, 在所有 cpp 提交中击败了97.68%的用户
内存消耗 :20.9 MB, 在所有 cpp 提交中击败了92.97%的用户

这个递归建树的方法和二分查找十分类似

    TreeNode* CreateBST(vector<int>& nums,int i,int j){
        if(i>=j){
            return nullptr;
        }
        int mid=(i+j)/2;
        TreeNode* current=new TreeNode(nums[mid]);
        current->left=CreateBST(nums,i,mid);
        current->right=CreateBST(nums,mid+1,j);
        return current;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return nullptr;
        }
        return CreateBST(nums,0,nums.size());
    }