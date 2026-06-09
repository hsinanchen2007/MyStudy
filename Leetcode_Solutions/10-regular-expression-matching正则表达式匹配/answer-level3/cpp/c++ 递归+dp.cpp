```
class Solution {
    unordered_map<int,unordered_map<int,bool>> dp;//动态规划、缓存，减少重复计算
public:
    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0);
    }
    bool isMatch(string s, string p, int si,int pi) {
        if(dp.count(si)&&dp[si].count(pi))return dp[si][pi];
        if(pi==p.size())return si==s.size();
        bool first_match=si<s.size()&&(s[si]==p[pi]||p[pi]=='.');//这里“si<s.size()”非常关键
        if(pi+1<p.size()&&p[pi+1]=='*'){
            auto res=isMatch(s,p,si,pi+2)||(first_match&&isMatch(s,p,si+1,pi));
            dp[si][pi]=res;
            return res;
        }
        auto res=first_match&&isMatch(s,p,si+1,pi+1);
        dp[si][pi]=res;
        return res;
    }
};
```
