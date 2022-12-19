```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int len=nums.size();
        if(len==0||len==1)
            return;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==0)
            {
                int j=i+1;
                bool flag=true;
                while(flag&&j<len)
                {
                    if(nums[j]!=0)
                    {
                        swap(nums[i],nums[j]);
                        flag=false;
                    }
                j++;
                }
            }
        }
        return;
    }
};