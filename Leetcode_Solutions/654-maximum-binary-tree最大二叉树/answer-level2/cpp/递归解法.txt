```
class Solution {
public:
    TreeNode* findmax(vector<int>& nums, int L,int R)
    {
        if (L<=R)
        {
            //找最大值
            int max=nums[L];
            int i;
            for (i=L;i<=R;i++)
            {
                if (nums[i]>max)
                    max=nums[i];
            }
            i=L;
            //找最大值的索引
            while(true)
            {
                if (nums[i]!=max)
                    i++;
                else
                    break;
            }
            TreeNode* root=new TreeNode(max);
            //递去
            root->left=findmax(nums,L,i-1);
            root->right=findmax(nums,i+1,R);
            //归来
            return root;
        }
        else
            return nullptr;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int L=0;
        int R=nums.size()-1;
        return findmax(nums,L,R);
    }
};
```
