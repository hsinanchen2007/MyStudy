设dp[i] 表示字符串s[0]~s[i]之间的子序列个数，这里先包含空序列
对于一个字符串，假设每个字符都不同，那么dp[i]=dp[i-1]*2;
为什么是乘2呢？因为走到当前位置，有两种选择：
1. 将当前字符s[i]添加到之前的所有子序列中,有dp[i-1]种新序列
2. 舍弃当前字符，还有之前dp[i-1]个旧序列
考虑到重复字符，在情况1中，需要去掉dp[last[i]]个重复的序列，last[i]表示上次s[i]出现的位置
```
class Solution {
public:
    
    int distinctSubseqII(string s) {
        int n=s.size();
        int mod=1e9+7;
        vector<int> dp(n+1,0);
        vector<int> last(n+1,-1);
        int dict[26];
        memset(dict,-1,sizeof(dict));
        for(int i=0;i<n;i++){
            if(dict[s[i]-'a']!=-1)
                last[i]=dict[s[i]-'a'];
            dict[s[i]-'a']=i;
        }
        dp[0]=1;
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i]*2%mod;
            //cout<<dp[i]<<endl;
            if(last[i]!=-1)
                dp[i+1]=(dp[i+1]-dp[last[i]])%mod;
        }
        dp[n]--;
        if(dp[n]<0) dp[n]+=mod;
        return dp[n];
    }
};
```
