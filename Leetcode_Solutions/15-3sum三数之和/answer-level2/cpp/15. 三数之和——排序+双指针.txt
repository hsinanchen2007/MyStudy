排序可以简化查询方向，同时达到去重的效果。
最坏情况下:时间复杂度O(n^2)+O(nlog(n)),空间复杂度O(1)
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int count = nums.size();
        for(int i = 0; i < count; i++) {
            if(nums[i] > 0) {
                return res;
            }
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = count - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    res.emplace_back(vector<int>({nums[i],nums[l],nums[r]}));
                    while(l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while(l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                } else if(sum > 0) {
                    r--;
                } else if(sum < 0) {
                    l++;
                }
            }
        }
        return res;
    }
};
```
