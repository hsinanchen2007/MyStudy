```
超内存限制，多亏评论区大佬AC"aaaaabaaaa"样例
class Solution {
public:
     vector<string> wordBreak(string s, vector<string>& wordDict) {
        //dp[i][j][MAX]表示[i][j]区间内的所有满足题意的单词集
        //map加快查询速度
        //O(K+n^3+N)
        //一个三维维数组dp[i][j][max]表示[i~j]区间组成的句子
        //dp[0][j][]=dp[0][k][0~max]+dp[k+1][j][0~max]
        //return dp[0][j][0~max];
        map<string,int>mp;
        for(int i=0;i<wordDict.size();i++)mp[wordDict[i]]=1;
        int m=s.size();
        vector<vector<vector<string>>>dp(m+1,vector<vector<string>>(m+1));
        if(!word(s,wordDict))return dp[0][m-1];
        for(int i=0;i<m;i++){
            if(dp[0][i].empty()&&mp[s.substr(0,i+1)])dp[0][i].push_back(s.substr(0,i+1)+" ");//选择符合字典的前缀字符串
            for(int j=0;j<=i;j++){      
                if(mp[s.substr(j+1,i-j)]){
                for(int k=0;k<dp[0][j].size();k++){
                        dp[0][i].push_back(dp[0][j][k]+s.substr(j+1,i-j)+" ");
                }
            }
           }
        }
        for(int i=0;i<dp[0][m-1].size();i++){
            dp[0][m-1][i].pop_back();
        }
        return dp[0][m-1];
    }
    //139代码水过测试样例
    bool word(string s, vector<string>& wordDict) {
        int m=s.size();
        map<string,int>mp;
        if(wordDict.empty())return false;
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]=1;
        }
        vector<vector<bool>>dp(m+1,vector<bool>(m+1));
        dp[0][0]=mp[wordDict[0]]==1?true:false;
        for(int i=0;i<m;i++){
            dp[0][i]=mp[s.substr(0,i+1)]==1;
            if(dp[0][i])continue;
            for(int j=0;j<=i;j++){
                if(!dp[0][i])                        
                dp[0][i]=dp[0][j]&&mp[s.substr(j+1, i-j)]==1;
            }
        }
        return dp[0][m-1];
    }
   
};
```
