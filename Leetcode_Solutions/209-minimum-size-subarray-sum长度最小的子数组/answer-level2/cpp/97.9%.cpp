```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 0, r = 0, cur = 0, ans = INT_MAX;
        while (r < nums.size()) { // [)
            while (r < nums.size() && cur < s) {
                cur += nums[r];
                r ++;
            }
            while (cur >= s) {
                ans = min(ans, r - l);
                if (l <= r) {
                    cur -= nums[l];
                    l ++;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};