首先得排序，满意度高的应该使用更多的时间。这个很好证明，如果最优解不是有序的，我们按照将最优解调整顺序，一定会得到一个更加好的解。
可以采用动态规划来写,有点0-1背包的意味：
dp[i][j]表示前i个物体中，选中j个菜，可以达到的最大值。
按照i道菜选还是不选，将问题一分为二：
dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+(i的满意度*j))
特殊情况：
当j==0时，dp[i][0] = 0;
当i==j时，必须选i号菜，dp[i][j]=dp[i-1][j-1]+(i的满意度*j)


```
int dp[550][550];
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        for(int i=0; i<550; i++){
            for(int j=0; j<550; j++)
                dp[i][j] = 0;
        }
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        dp[1][0] = 0;
        dp[1][1] = satisfaction[0];
        for(int i=2; i<=n; i++){
            for(int j=0; j<=i; j++){
                if(j==0) dp[i][j] = 0;
                else{
                    if(i==j) 
                        dp[i][j]= dp[i-1][j-1]+satisfaction[i-1]*j;
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+satisfaction[i-1]*j);
                }
                
            }
        }
        int ans = 0;
        for(int i=0; i<=n; i++)
            ans = max(ans, dp[n][i]);
        return ans;


    }
};
```


![haha.png](https://pic.leetcode-cn.com/8bab8d4fe39f54fcee91ce721949649e82ae802b2dddaf9c81bdfe430641f9c0-haha.png)


