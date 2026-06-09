if(nums.size()==0){
            return NULL;
        }
        int max=nums[0]; 
        int max_idex=0;//开始的时候假设max是第0个元素
        for(int i=0;i<nums.size();i++){  //找到nums中max以及它的下标
            if(max<nums[i]){
                max=nums[i];
                max_idex=i;//假如找到新的max就更换
            }
        }
        vector<int> left(nums.begin(),nums.begin()+max_idex);   //nums左边复制到left
        vector<int> right(nums.begin()+max_idex+1,nums.end());
        TreeNode* root=new TreeNode(max);  //根的val是max
        root->left=constructMaximumBinaryTree(left);
        root->right=constructMaximumBinaryTree(right);
        return root;