### 解题思路
每次都只能向下或者向右下，对于对于每个节点(i,j),都能通过dp[i-1][j]和dp[i-1][j-1]得到

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int> (m,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                if(i==0&&j==0){
                    dp[i][j]=triangle[i][j];
                    continue;
                }
                //上和左上的值，即上一步的位置
                int up=INT_MAX,left_up=INT_MAX;
                if(i>=j){//此时上方存在元素
                    up=dp[i-1][j];
                }
                if(j-1>=0){////此时左上方存在元素
                    left_up=dp[i-1][j-1];
                }
                dp[i][j]=min(up,left_up)+triangle[i][j];
                //cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
            }
        }
        //遍历最后一行，找到总路径和最小的出口
        for(int j=0;j<triangle[m-1].size();j++){
            if(dp[m-1][j]<ans) ans=dp[m-1][j];
        }
        return ans;
    }
};
```