
### 代码

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        
        set<vector<int>> s;

        for(int i=0;i<nums.size()-1;i++)
            for(int j=i+1;j<nums.size();j++)
                if(abs(nums[i]-nums[j])==k)
                {
                    if(nums[i]<nums[j]) s.insert({nums[i],nums[j]});
                    else s.insert({nums[j],nums[i]});
                }
        
        return s.size();
    }
};
```