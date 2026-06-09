### 解题思路
动态规划考虑最后一颗骰子的投掷情况
动态规划方程：p[i][k] += p[i-j][k-1]*1/6;(i表示总和，k为筛子数)

### 代码

```cpp
class Solution {
public:
    vector<double> twoSum(int n) {
        //p[i][j] 表示用i颗筛子得到总和为j的概率
        vector<vector<double>> p(n*6+1,vector<double>(n+1,0));
        //记录最终概率
        vector<double> fin_p;

        //初始化
        for(int i=1;i<=6;i++) p[i][1]=1.0/6.0;
        //n=1单纯讨论
        if(n==1) {
            for(int i=1;i<=6;i++)
            fin_p.push_back(p[i][1]);
            return fin_p;
        }
        //i为总和枚举
        for(int i=2;i<=n*6;i++)
        {
            //k为所用骰子数
            for(int k=2;k<=n && k<=i;k++){
                for(int j=1;j<=6&&(i-j>0);j++){
                    //得出总和为i，考虑最后一颗筛子的情况
                    p[i][k] += p[i-j][k-1]*1/6;
              }
            }
            if(i>=n) fin_p.push_back(p[i][n]);
            
        }
    return fin_p;
    }
    
    
    
};
```