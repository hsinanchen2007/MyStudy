```
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            s.emplace(arr[i], i);
        }
        vector<int> dp(n, 1);
        for (auto &[a, i] : s) {
            int left = i-1, right = i+1;
            while (left >= 0 && arr[left] < a && i - left <= d) 
                --left;
            while (right < n && arr[right] < a && right - i <= d) 
                ++right;
            for (int j = left + 1; j < right; ++j) {
                if (j == i) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};
```