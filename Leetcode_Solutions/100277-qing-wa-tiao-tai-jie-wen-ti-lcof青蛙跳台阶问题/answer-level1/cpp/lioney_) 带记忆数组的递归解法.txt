```
class Solution {
public:
    int numWays(int n) {
        unordered_map<int,int> memo;
        memo[0] = 1;
        memo[1] = 1;
        return helper(n, memo);
    }
    int helper(int n, unordered_map<int,int>& m) {
        if(m.count(n)) return m[n];
        int res = helper(n-1, m) + helper(n-2, m);
        res %= 1000000007;
        m[n] = res;
        return res;
    }
};
```
