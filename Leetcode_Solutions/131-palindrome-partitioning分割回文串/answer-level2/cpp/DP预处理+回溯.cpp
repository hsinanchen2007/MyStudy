这个问题，很显然是回溯做。

从当前位置i开始查找，找到一个位置j满足s[i:j]是回文串
进如下一层，从j开始查找，找到一个位置k满足s[j:k]是回文串。
………………

我们要做的过程是：
找到回文子串，往下递归。
到查找位置到达终点（s.size()）时停止查找，将路径处理，加入到答案中。
回溯，继续查找。

那么这么做时间消耗很大,原因是我们在不断地判断子串是不是回文的。
因此我们可以通过DP预处理，从而将判断子串的时间复杂度降低为O(1)。

因此代码如下：
```
class Solution {
public:
    void dfs(int idx,string s,vector<vector<bool>>&dp,vector<int>&t,vector<vector<string>>&res){
        if(idx==s.size()){
            vector<string>tmp;
            for(int i=0;i<t.size()-1;i++){
                tmp.push_back(s.substr(t[i],t[i+1]-t[i]));
            }
            res.push_back(tmp);
            return;
        }
        int n=s.size();
        for(int i=idx+1;i<=n;i++){
            if(dp[idx][i]){
                t.push_back(i);
                dfs(i,s,dp,t,res);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //先用dp判断是不是子串，然后再用dfs
        int n=s.size();
        vector<vector<bool>>dp(s.size()+1,vector<bool>(s.size()+1));
        vector<vector<string>>res;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            dp[i][i+1]=true;
        }
        dp[n][n]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<=n;j++){
                dp[i][j]=dp[i][j]||(s[i]==s[j-1]&&dp[i+1][j-1]);
            }
        }
        vector<int>t;
        t.push_back(0);
        dfs(0,s,dp,t,res);
        return res;
    }
};
```

