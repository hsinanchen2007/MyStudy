
主要是在解决重复的数据上进优化，在算法整体复杂度上改变不是太大

```
class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
        int res = 99999;
        sort(nums.begin(),nums.end()); 
        for (int i = 0; i < nums.size(); ++i) { 
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum==target)
                    return target;
                if (abs(sum - target) < abs(res - target)) 
                    res = sum;
                if (sum <= target)
                {
                    l++;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                }
                else
                {
                    r--;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
                
            }
        }
        return res;
    }
};
```

