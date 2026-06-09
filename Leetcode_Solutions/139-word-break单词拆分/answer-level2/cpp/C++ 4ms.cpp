```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(), m = wordDict.size();
        vector<int> str_len(m);
        for(int i=0;i<m;i++) str_len[i]=wordDict[i].length();
        vector<bool> f(n,false);f[0] = true;
        for(int i=1;i<=n;i++)
            for(int j=0;j<m;j++)
                if(i>=str_len[j]&&f[i-str_len[j]])
                    f[i]=f[i]||(wordDict[j]==s.substr(i-str_len[j],str_len[j]));
        return f[n];
    }
};
```
复杂度: $O(nml)$(不是nmsl)
快仅限于$ml$小于$n$的情况, 标答复杂度是$O(n^2l)$.