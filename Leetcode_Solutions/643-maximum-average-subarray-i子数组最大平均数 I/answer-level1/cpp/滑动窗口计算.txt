```
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double n = 0;
        double mx = 0;
        int i = 0;
        for(i=0; i<k; i++)
        {
            n += nums[i];
        }
        mx = n;
        for(i=k; i<nums.size(); i++)
        {
            n += nums[i];
            n -= nums[i-k];
            if(n>mx)
            {
                mx = n;
            }
        }
        return mx/k;
    }
};
```
