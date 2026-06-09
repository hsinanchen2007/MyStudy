
```cpp
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        if (a == 0) {
            for (auto x : nums) {
                res.push_back(b * x + c);
            }
            if (b < 0) {
                reverse(res.begin(), res.end());
            }
        } else {
            vector<int> helper;
            for (auto x : nums) {
                helper.push_back(a * x * x + b * x + c);
            }
            double m = -(double)b / (2 * a);
            int N = nums.size();
            int l = 0;
            int r = N - 1;
            while (l <= r) {
                if (m - nums[l] > nums[r] - m) {
                    res.push_back(helper[l++]);
                } else {
                    res.push_back(helper[r--]);
                }
            }
            if (a > 0) {
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```