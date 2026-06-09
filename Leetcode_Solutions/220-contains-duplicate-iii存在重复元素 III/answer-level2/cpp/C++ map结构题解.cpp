```
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0 || nums.empty()) return false;
        int N = nums.size();
        map<long, int> m{{nums[0], 1}};
        for (int i = 1; i < N; ++i) {
            auto it = m.lower_bound(nums[i]);
            if (it != m.end() && abs(it->first - (long)nums[i]) <= t) return true;
            if (it != m.begin() && abs((--it)->first - (long)nums[i]) <= t)  return true;
            ++m[nums[i]];
            if (i - k >= 0 && --m[nums[i - k]] == 0) m.erase(nums[i - k]);
        }
        return false;
    }
};
```
![image.png](https://pic.leetcode-cn.com/dbef2cbd7a3d9cb934c2181bfcfe5c17a13bb78ecd0f61c94279cdd23f0a3af2-image.png)

