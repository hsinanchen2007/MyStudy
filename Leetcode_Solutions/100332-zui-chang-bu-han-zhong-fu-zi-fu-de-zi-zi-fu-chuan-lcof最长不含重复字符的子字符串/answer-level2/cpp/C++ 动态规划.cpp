剑指offer上的思路
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        if(s.length()==1) return 1;
        vector<int> dp(s.length(),0);
        dp[0]=1;
        unordered_map<char,vector<int>> mp;
        
        mp[s[0]].push_back(0);
        int res=1;
        for(int i=1;i<s.length();++i){
            if(mp.find(s[i])==mp.end()){
                dp[i]=dp[i-1]+1;
            }
            else{
                int len=mp[s[i]].size();
                int last=mp[s[i]][len-1];
                if(i-last<=dp[i-1]){
                    dp[i]=i-last;
                }
                else{
                    dp[i]=dp[i-1]+1;
                }
            }
            mp[s[i]].push_back(i);
            res=max(res,dp[i]);
        }
        return res;
    }
};
```
