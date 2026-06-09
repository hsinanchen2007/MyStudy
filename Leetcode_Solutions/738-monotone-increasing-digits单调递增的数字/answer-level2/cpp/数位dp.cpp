```
const int p[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
class Solution {
private:
    int n;
    string pattern;
    unordered_map<int,int> dp;
    int dfs(bool zero,bool limit,int pos,int pre) {
        if(pos == n){
            return 0;
        }
        int hash = pos * 32 + pre;
        if(!limit && !zero && dp.count(hash)) {
            return dp[hash];
        }
        int up = limit ? pattern[pos] - '0' : 9,mx = INT_MIN;
        for(int i = pre;i <= up; ++i) {
            int lat = dfs(zero && i == 0, limit && i == up, pos + 1, i);
            if(lat == INT_MIN)continue;
            int now = i * p[n - 1 - pos] + lat;
            mx = max(mx, now);
        }
        if(!limit && !zero) {
            dp[hash] = mx;
        }
        return mx;
    } 
public:
    int monotoneIncreasingDigits(int N) {
        //初始化变量
        pattern = to_string(N);
        n = pattern.size();
        return dfs(1,1,0,0);
    }
};
```
