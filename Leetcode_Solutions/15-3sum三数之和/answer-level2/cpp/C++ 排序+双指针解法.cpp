这道题和之前做过的twosum有点相似，只不过从twosum变成了threesum。回顾之前做twosum的做法，排序号数组后，我使用双指针头尾遍历数组，找到target值。但很显然我们没办法直接应用这个解法。需要一点变通。

什么变通呢？其实我们只要先把数组排序好，然后先固定一个值，之后把target取这个值的相反数，就能用双指针来找到我们需要的target值了，就变成和twosum一样了。

固定一个值的时候，我们可以做个剪枝优化，有以下几种情况需要优化。
1. 遍历到正数直接break，因为数字已经是有序的了，如果第一个要固定的数是正的话，那之后的数字也必然是正的，无需考虑。其次，如果在前几个固定的数中已经使用到后面为正数的数了，我们也不需要把这些正数作为固定的数，因为这些数在之前的解使用过了。

2. 从第二个数起，如果和前面的数字相等，就跳过。我们不想把相同数字固定两次。

AC代码：
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        if(nums.empty()||nums.back()<0||nums.front()>0) return {};
        
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]>0) break;
            if(k>0&&nums[k]==nums[k-1]) continue;
            int target=0-nums[k];
            int left=k+1, right=nums.size()-1;
            while(left<right)
            {
                if(nums[left]+nums[right]==target)
                {
                    res.push_back({nums[k],nums[left],nums[right]});
                
                while(left<right&&nums[left]==nums[left+1])++left;
                while(left<right&&nums[right]==nums[right-1])--right;
                
                ++left;--right;
                }
                else if(nums[left]+nums[right]<target) ++left;
                else
                    --right;
            }
            
        }
        
        return res;
    }
};
```