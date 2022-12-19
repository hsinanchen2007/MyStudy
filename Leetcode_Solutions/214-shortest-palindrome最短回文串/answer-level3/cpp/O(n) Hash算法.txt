思路：寻找最长的回文前缀。
```
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "") return s;
        int len = s.size(), ans=0;
        unsigned long long seed = 233LL, base = 1LL, pre = 0, suf = 0;
        for(int i=0; i<len; ++i){
            pre += base * s[i];
            base = base * seed;
            suf = suf *seed + s[i];
            if(pre == suf) ans = i;
        }
        string t = s.substr(ans+1);
        reverse(t.begin(), t.end());
        return t + s;
    }
};
```
