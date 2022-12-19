```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int sum = 0;
        int min_len = INT_MAX;
        for(; r < nums.size(); ++r)
        {
            sum += nums[r];
            while(sum >= s)
            {
                min_len = min(min_len, r-l+1);
                sum -= nums[l];
                l++;
            }
        } 
        return (min_len==INT_MAX)?0:min_len;   
    }
};
```
