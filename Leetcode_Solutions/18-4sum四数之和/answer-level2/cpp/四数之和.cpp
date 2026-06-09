### 解题思路
固定两个数，然后用双指针法，主要是如何去重

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for(int j = i+1; j < n-2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int p = j+1;
                int q = n-1;
                while( p < q) {
                    if (nums[i] + nums[j] + nums[p] + nums[q] < target) {
                        ++p;
                    } else if (nums[i] + nums[j] + nums[p] + nums[q] > target) {
                        --q;
                    } else {
                        res.push_back({nums[i],nums[j],nums[p],nums[q]});
                        while(p < q && nums[p+1] == nums[p]) {
                            ++p;
                        }
                        while(p < q && nums[q] == nums[q-1]) {
                            --q;
                        }
                        ++p;
                        --q;
                    }
                }
            }
        }
        return res;
    }
};
```