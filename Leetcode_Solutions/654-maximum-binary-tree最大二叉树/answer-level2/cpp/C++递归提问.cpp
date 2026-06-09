```
class Solution {
public:
    TreeNode* maxtree(vector<int>& nums, int L, int R)
    {
        if(nums.empty()) return nullptr;
        if(L<=R)
        {
            int m_max = 0;
            int record = L;
            for(int i = L; i <= R; i++)
            {
                if(nums[i] > m_max)
                {
                    m_max = nums[i];
                    record = i;
                }
            }
            
          
            TreeNode* node = new TreeNode(m_max);
            node -> left = maxtree(nums, L, record - 1);
            node -> right = maxtree(nums, record+1, R);
            
            return node;
        }
        else return nullptr;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        int L = 0;
        int R = nums.size() - 1;
        return maxtree(nums, L, R);
    }
    
};
```
请问大家，为什么第一个函数里 int record = L 改成 int record = 0 就不行呢？按理来说作用应该是一样的啊