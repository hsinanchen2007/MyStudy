### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int sum1=0;
        int sum2=0;
        for(auto e:nums) sum1+=e;
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum2+=nums[i];
            ans.push_back(nums[i]);
            if(sum2>sum1-sum2) break;
        }
        return ans;
    }
};
```