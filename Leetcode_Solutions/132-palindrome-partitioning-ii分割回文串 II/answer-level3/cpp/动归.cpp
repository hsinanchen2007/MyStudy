```
class Solution {
public:
    int minCut(string s) {
        if(s.empty() || s.size()==1) return 0;
        int cnt=INT_MAX;
        const int n=s.size();
        vector<int> f(n+1);
        for(int i=n;i>=0;--i)
            f[i]=n-i-1;
        vector<vector<int>> v(n,vector<int>(n,0));
        for(int i=n-1;i>=0;--i)
        {
            for(int j=i;j<n;++j )
            {
                if(s[i]==s[j] && (j-i<2 || v[i+1][j-1]))
                {
                    v[i][j]=1;
                    f[i]=min(f[i],f[j+1]+1);
                }
            }
        }
        return f[0];
    }
};
```
