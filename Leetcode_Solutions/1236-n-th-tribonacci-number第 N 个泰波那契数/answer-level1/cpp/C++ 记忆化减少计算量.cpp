```
class Solution {
public:
    vector<int> memo{0, 1, 1};
    int tribonacci(int n) {
        if (memo.size() > n)
            return memo[n];
        for (int i = memo.size(); i <= n; ++i) {
            memo.push_back(memo[i - 1] + memo[i - 2] + memo[i - 3]);
        }
        return memo[n];
    }
};
```
