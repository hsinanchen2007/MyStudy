思路：利用二分法每次递归的将数组分别分为两部分，其中每次中间节点为根元素，左边为左子树，右边为右子树。返回为根节点，终止条件为子数组长度为1。有序链表的转换方法类似。
TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        if(nums.size()==1)
            return new TreeNode(nums[0]);
        TreeNode* root=new TreeNode(nums[nums.size()/2]);
        vector<int> left;
        left.assign(nums.begin(),nums.begin()+nums.size()/2);
        vector<int> right;
        right.assign(nums.begin()+nums.size()/2+1,nums.end());
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }