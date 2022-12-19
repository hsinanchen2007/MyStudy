### 解题思路
其实只要i和j不重复就行，因为只有三个数相加，两个数相同第三个数必定相同
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<=2)
           return ans;
        for(int i=0;i<nums.size()-2;i++)
        {
           if (i > 0 && nums[i] == nums[i - 1]) continue;
           if(nums[i]>0)
             break;
           int j=i+1;
           int k=nums.size()-1;
           while(j<k)
           {
               int tar = nums[i]+nums[j]+nums[k];
               if(tar>0) k--;
               else if(tar<0)j++;
               else
               {
                 ans.push_back({nums[i],nums[j],nums[k]});
                 while (j < k && nums[j] == nums[++j]);
               }
           } 
        }
        return ans;
    }
};
```