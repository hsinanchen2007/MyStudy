### 解题思路
先处理==的情况，若a==b，则令dp['a'-'a']['b'-'a']=1，再处理!=的情况，对于x!=y，通过dfs判断x与y是否连通，flag[]为辅助数组标记节点是否遍历过以方便回溯

### 代码

```cpp
class Solution {
public:
    int dp[26][26];
    int flag[26];
    bool dfs(int x,int y){
        if(dp[x][y]==1)
            return true;
        else{
            bool res=false;
            flag[x]=1;
            for(int i=0;i<26;i++)
                if(dp[x][i]==1&&flag[i]==0){
                    flag[i]=1;
                    res=res||dfs(i,y);
                    if(res==true)
                        return true;
                    flag[i]=0;
                }
            flag[x]=0;
            return res;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                if(i==j)
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
        for(int i=0;i<26;i++)
            flag[i]=0;
        for(int i=0;i<equations.size();i++)
            if(equations[i][1]=='='){
                dp[equations[i][0]-'a'][equations[i][3]-'a']=1;
                dp[equations[i][3]-'a'][equations[i][0]-'a']=1;
            }
        for(int i=0;i<equations.size();i++)
            if(equations[i][1]=='!')
                if(dfs(equations[i][0]-'a',equations[i][3]-'a'))
                    return false;
        return true;   
    }
};
```