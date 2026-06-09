### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //初步感觉是dfs,dfs超出时间限制？动态规划？
        int length = s.length();
        vector<bool> dp(length+1,false);
        dp[0]=true;

        for(int i=0;i<s.length();i++){
            int flag=0;
            for(int j=i;j>=0;j--){
                if(dp[j]){
                    string curr = s.substr(j,i-j+1);
                    for(int k=0;k<wordDict.size();k++){
                        if(curr==wordDict[k]){
                            dp[i+1]=true;
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag==1) break;
            }
        }
        return dp[length];
    }

};
```