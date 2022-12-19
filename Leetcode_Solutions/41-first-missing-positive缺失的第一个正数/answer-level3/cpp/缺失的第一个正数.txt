利用已有数组来实现已存在的数值的标记
```C++ []
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()<1)return 1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==-1)nums[i]=-2;//利用-1来标识利用下标index来标识index+1是否存在，因而将原本就为-1的值改为-2，不影响结果
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0||nums[i]>nums.size())continue;//不在区间内的数不需要考虑
            else
            {
                int tmp=nums[i];
                //对于所有在区间内的值，将其对应的下标位置的值标为-1，标识存在
                //由于直接改变值就不管就有可能丢失信息，因而需要利用已有的信息一直改，直至丢失的信息为无用信息为止
                while(tmp-1>=0&&tmp-1<nums.size())
                {
                    int nextN=nums[tmp-1];
                    nums[tmp-1]=-1;
                    tmp=nextN;
                }
            }
        }
        
        for(int i=0;i<nums.size();i++)
        { 
            if(nums[i]!=-1)return i+1;//依次搜索数组，不为-1则i+1的值不存在，
        }
        
        return nums.size()+1;
    }
};

