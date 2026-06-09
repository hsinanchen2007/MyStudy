效率低
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = s.size();
        if (ns==0) return true;
        int nt = t.size();
        if (nt < ns) return false;
        if (s == t) return true;
        int dp[ns+1] = {0};
        dp[0] = 1;

        int k = 0;
        for (int i=0; i<ns; i++){
            for (int j=0+k; j<nt; j++){
                if (t[j] == s[i] && dp[i]==1){
                    //cout << j << ' ';
                    dp[i+1] = 1;
                    k = j+1;
                    break;
                }
            }
        }
        for (int i=1; i<=ns; i++){
            //cout << dp[i] << ' ';
            if (dp[i] == 0)
                return false;
        }
        return true;
    }
};
```
