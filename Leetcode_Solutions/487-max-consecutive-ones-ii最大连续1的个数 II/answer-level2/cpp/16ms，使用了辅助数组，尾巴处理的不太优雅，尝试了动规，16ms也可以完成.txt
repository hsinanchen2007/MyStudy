1、辅助数组
```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> hint{0, 0, 0};
        for (int i = 0; i < n;) {
            int cnt = 0;
            while (i < n && nums[i] == 1) {
                cnt++;
                i++;
            }
            if (cnt > 0) {
                hint.push_back(cnt);
            }
            cnt = 0;
            while (i < n && nums[i] == 0) {
                cnt++;
                i++;
            }
            if (cnt == 1) {
                hint.push_back(1);
            } else if (cnt > 1) {
                hint.push_back(0);
                hint.push_back(0);
                hint.push_back(0);
            }
        }
        int ans = n > 0 ? 1 : 0;
        for (int i = 3; i < hint.size(); i++) {
            if (hint[i] > 0) {
                hint[i] += hint[i - 1];
                ans = max(ans, hint[i] - hint[i - 3] + (hint[i - 1] ? 0 : 1));
            }
        }
        return min(ans, n);
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```
2、动归
```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int dp1 = 0;
        int dp0 = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                dp1 = dp1 + 1;
                dp0 = dp0 + 1;
            } else {
                dp1 = dp0 + 1;
                dp0 = 0;
            }
            res = max(dp1, res);
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
