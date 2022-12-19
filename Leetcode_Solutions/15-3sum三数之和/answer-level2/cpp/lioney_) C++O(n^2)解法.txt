```
static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n<3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            if(nums[i] + nums[n-1] + nums[n-2] < 0) continue;
            if(nums[i] + nums[i+1] + nums[i+2] > 0) break;
            int target = -nums[i];
            int j = i+1, k = n-1;
            while(j < k) {
                if(nums[j] + nums[k] < target) 
                    j++;
                else if(nums[j] + nums[k] == target) {
                    res.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++, k--;
                }
                else
                    k--;
            }
        }            
        return res;
    }
};
```
