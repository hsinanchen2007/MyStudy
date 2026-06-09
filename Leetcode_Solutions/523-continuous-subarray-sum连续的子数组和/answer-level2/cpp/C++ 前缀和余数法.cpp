```C++ []
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (k == 0) {
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] == 0 && nums[i - 1] == 0) {
                    return true;
                }
            }
            return false;
        }
        k = abs(k);
        unordered_set<int> s{0};
        int t = nums[0] % k;
        for (int i = 1; i < nums.size(); ++i) {
            int t1 = t;
            t = (t + nums[i]) % k;
            if (s.count(t) > 0) {
                return true;
            }
            s.insert(t1); // 延迟更新，为了保证子数组长度至少为2
        }
        return false;
    }
};
```
![image.png](https://pic.leetcode-cn.com/de2708023de3fbff86f986369beae147c9f96630e66b882cca959fa1356c1322-image.png)
