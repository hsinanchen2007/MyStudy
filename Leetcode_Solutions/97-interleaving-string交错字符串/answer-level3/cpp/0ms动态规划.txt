动态规划

```
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int N = s1.length(), M = s2.length();
        int f[N+1][M+1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        int nn = s3.length();
        if (nn != N+M)
            return false;
        
        for (int i = 1; i <= nn; ++i) {
            char ch = s3[i-1];
            for (int k = 0; k <= min(i-1, N); ++k) {
                int l = i-1-k;
                if (k < N && l <= M && ch == s1[k])
                    f[k+1][l] |= f[k][l];
                if (k <= N && l < M && ch == s2[l])
                    f[k][l+1] |= f[k][l];
            }
        }
        return f[N][M];
    }
};
```
