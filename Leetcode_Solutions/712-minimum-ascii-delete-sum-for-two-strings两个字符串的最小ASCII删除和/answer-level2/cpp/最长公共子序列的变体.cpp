### 解题思路
最长公共子序列的变体，dp记录的公共部分的最大ascii值，最后减去这个就是最小需要删除的ascii值

### 代码

```cpp
class Solution {
public:
    //
    int dp[1010][1010];//记录最大的ascii码和
    int minimumDeleteSum(string s1, string s2) {
        s1=' '+s1;
        s2=' '+s2;
        int max_ascii=0;
        int sum_ascii=0;//总的ASCII码值
        for(int i=1;i<=s1.size();i++) sum_ascii+=s1[i];
        for(int i=1;i<=s2.size();i++) sum_ascii+=s2[i];

        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else{
                    if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+s1[i];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                max_ascii=max(max_ascii,dp[i][j]);
            }
        }
        return sum_ascii-max_ascii*2;
    }
};
```