### 解题思路
遍历背包容量的部分改成遍历两个背包，转移公式也做相应的修改

### 代码

```cpp
class Solution {
public:


    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp[i][j]表示i个0，j个1能够拼出的数组中的最大的字符串数量
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        vector<vector<int>> weight(strs.size(),vector<int>(2,0));
        //cout<<dp[1][1]<<endl;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') weight[i][0]++;
                else weight[i][1]++;
            }
            //cout<<weight[i][0]<<" "<<weight[i][1]<<endl;
        }
        for(int k=0;k<strs.size();k++){//从上到下每个物品选与不选
            //cout<<weight[k][0]<<" "<<weight[k][1]<<endl;
            for(int i=m;i>=weight[k][0];i--){//遍历0的背包容量
                for(int j=n;j>=weight[k][1];j--){//遍历1的背包容量
                    dp[i][j]=max(dp[i][j],dp[i-weight[k][0]][j-weight[k][1]]+1);
                    //cout<<dp[i][j]<<endl;
                }
            }
        }
        return dp[m][n];
    }
};
```