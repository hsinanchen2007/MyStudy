# **这里注意边界条件，度为1时直接返回1，不用找啦！！！**

class Solution {
```C++ []
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        unordered_map<int, int> hash;
        int du = 0;
        for (auto x: nums) {
            hash[x]++;
            du = max(du, (int)hash[x]);
        }
        if (du == 1) {
            return 1;
        }
        int n = du;
        int l = 0;
        int r = 0;
        int res = INT_MAX;
        for (auto x : hash) {
            if (x.second == du) {
                for (int i = 0;i<nums.size();i++){
                    if (nums[i] == x.first && n == du) {
                        l = i;
                        n--;
                        continue;
                    }
                    if (nums[i] == x.first)
                        n--;
                    if (n == 0) {
                        r = i;
                        res = min(res, r - l + 1);
                        n = du;
                        break;
                    }
                }
            }
        }
        return res;
    }
};