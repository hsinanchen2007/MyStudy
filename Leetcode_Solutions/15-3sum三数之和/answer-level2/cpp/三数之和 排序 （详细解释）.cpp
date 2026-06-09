排序思路：1.首先对nums数组从小到大排序。2.然后利用i对nums进行遍历，相当于暂时固定i,而j,k在i+1~nums.size()-1中选择,情况1：当nums[i]+nums[j]+nums[k]>0时，因为nums[k-1]<num[k],所以k--，当nums[i]+nums[j]+nums[k]<0时，因为nums[j+1]<num[j],所以j++。但这两情况都有前提j<k。3.优化,如果在对i的遍历过程，nums[i]已经大于0，那么因为 j,k不然大于i，且这是排序数组，肯定不符合题目要求，直接考虑i++,如果nums[j]==nums[j+1]和nums[i]==nums[i+1]这两种相邻元素重复情况，利用while循环跳过。

FROM XUEBI-IFCEN If this solution can help you, please click 'smile'.
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector <int>> result;
        if(nums.size()<3)
            return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]>0)
                break;
            int k=nums.size()-1;
            int j=i+1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]<0)
                {
                    j++;
                }   
                else if(nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                }
                else
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j<nums.size()-2&&nums[j]==nums[j+1])
                    {
                            j++;
                    }
                    j++;
                 }
            }
            while(nums[i]==nums[i+1]&&i<nums.size()-3)
                i++;    
        }
        return result;
            
    }
};
```
