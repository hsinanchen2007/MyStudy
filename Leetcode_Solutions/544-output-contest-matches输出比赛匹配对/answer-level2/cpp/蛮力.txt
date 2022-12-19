
```cpp
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> dp;
        for (int i = 1; i <= n; i++) {
            dp.push_back(to_string(i));
        }
        while (n > 1) {
            for (int next = 0, last = n - 1; next < last; next++, last--) {
                dp[next] = "(" + dp[next] + "," + dp[last] + ")";
            }
            n = n >> 1;
            dp.resize(n);
        }
        return dp[0];
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```