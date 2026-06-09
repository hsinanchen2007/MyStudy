C++递归写法：按照思路来，用一个函数求出数组的最大值，然后利用最大值将数组分为两部分，递归求解
 int maxAndIndex(vector<int>& nums)
    {
       if(nums.size()==0)
           return 0;
       int maxValue=nums[0];
       for(int i=0;i<nums.size();i++)
       {
           if(maxValue<=nums[i])
           {
               maxValue=nums[i];
           }
          
       }
        return maxValue;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        if(nums.size()==1)
            return new TreeNode(nums[0]);
        
        //首先找到数组的最大值
        int maxValue=maxAndIndex(nums);
        //找到最大元素对应的索引
        int k;
        for(int i=0;i<nums.size();i++)
        {
            if(maxValue==nums[i])
            {
                k=i;
                break;
               
            }
        }
        //i是最大索引
        TreeNode* root=new TreeNode(maxValue);
        vector<int> leftVector;
        leftVector.assign(nums.begin(),nums.begin()+k);
        vector<int> rightVector;
        rightVector.assign(nums.begin()+k+1,nums.end());
        root->left=constructMaximumBinaryTree(leftVector);
        root->right=constructMaximumBinaryTree(rightVector);
        return root;
    }