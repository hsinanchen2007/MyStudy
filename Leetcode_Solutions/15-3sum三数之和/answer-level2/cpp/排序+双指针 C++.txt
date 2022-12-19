```
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 2) return res;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int sum = 0;
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            l = i + 1;
            r = nums.size() - 1;
            while(l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0)
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }
                else if(sum < 0) l++;
                else  r--;
            }
            
        }
        return res;
    }
```
