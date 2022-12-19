小白参考了陈乐乐的三数之和，自己写了一下，性能上不太理想，希望大神可以批评指正
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l, r;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3)
            return {};
        for(int i=0; i<nums.size()-2; ++i)
        {
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            l = i + 1;
            r = nums.size()-1;
            while(l < r)
            {
                if(nums[l] + nums[r] == -nums[i])
                {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    if(l >= r)
                        break;
                    while(nums[l] == nums[l-1] && l < r)
                    {
                        ++l;
                    }
                    while(nums[r] == nums[r+1] && l < r)
                    {
                        --r;
                    }
                }
                else if(nums[l] + nums[r] > -nums[i])
                    --r;
                else 
                    ++l;
            }
        }
        return res;
    }
};
```

