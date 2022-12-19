    class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            
            int idx = 0;
            for(int i = 0;i < nums.size();i++)
            {
                //以nums[i]为索引对应的值乘以-1，如果该索引(或该数字)存在两次以上
                //那么遍历过程中，至少遍历两边其对应的值，当发现该值为负数时，记录该索引
                int j = nums[i]<0?-1*nums[i]:nums[i];
                if(nums[j] < 0)
                {
                    idx = i;//记录i
                    break;
                } 
                nums[j] *= -1;
            }
            //恢复原数组中的数据
            for(int i = 0;i < nums.size();i++)
            {
                if(nums[i] < 0)
                    nums[i] *= -1;
            }
            //返回查找到的数
            return nums[idx];
        }
    };