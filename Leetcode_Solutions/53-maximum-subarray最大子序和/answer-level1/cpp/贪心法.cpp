```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        assert(!nums.empty());
        int maxsum=nums[0];
        int cursum=0;
        for(auto& e:nums){
            cursum=max(cursum+e,e);
            maxsum=max(cursum,maxsum);
        }
        return maxsum;
    }
};
```
