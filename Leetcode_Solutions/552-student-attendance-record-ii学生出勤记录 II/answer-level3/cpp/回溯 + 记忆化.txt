### 解题思路

回溯 + 记忆化

### 代码

```cpp

class Solution {
private:
    //int res = 0;
    const int mod = 1000000007;
    //unordered_map<int, unordered_map<int, unordered_map<int, ll>>> memo;
    vector<vector<vector<int>>> memo;
public:
    int checkRecord(int n) {
        vector<char> init;
        memo.assign(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return dfs(0, n, 0, 0);
    }
    
    // cur: 出勤记录长度
    // aCount: A数量
    // lCount: 连续的L数量
    int dfs(int cur, int n, int aCount, int lCount) {
        int& ans = memo[cur][aCount][lCount];
        if(ans > -1)
            return ans;
        
        if(cur == n) {
            // res++;
            return ans = 1;
        }
        
        ans = 0;
        
        // push 'A'
        if(aCount < 1) {
            ans += dfs(cur + 1, n, aCount + 1, 0);
            ans %= mod;
        }
        
        // push 'L'
        if(lCount < 2) {
            ans += dfs(cur + 1, n, aCount, lCount + 1);
            ans %= mod;
        }
        
        // push 'P'
        ans += dfs(cur + 1, n, aCount, 0);
        ans %= mod;
        
        return ans;
    }
};
```