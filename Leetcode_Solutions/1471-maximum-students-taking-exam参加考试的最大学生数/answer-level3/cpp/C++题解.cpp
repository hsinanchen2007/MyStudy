### [1349. 参加考试的最大学生数](https://leetcode-cn.com/problems/maximum-students-taking-exam/)

#### 题解
  + 状压DP
  + $dp[i][j]$ 表示统计前i行，（且第i行状态为j时的）所坐的最大学生数。
  + 状态转移方程： $dp[i][j] = max(dp[i-1][k] + count(j))\\ k 为第i-1行的状态, count(j) 为状态j的学生数，即二进制1的个数$
  + 第一行单独初始化， 注意边界条件和判断状态是否能存在，判断状态是否能转移，相互矛盾则不能转移。
  + 注意二进制统计时 x & y 判断 非0 而不是 判断是1
  + 时间复杂度: $O(m * x^n * 2^n)$
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:

    bool check(int r, int x, int y, int p, vector<vector<char>>& seat)
    {
        int xa[8], ya[8];
        int t = 1;
        for(int i = 0; i < p; i++, t <<= 1)
        {
            xa[i] = (t & x);
            ya[i] = (t & y);
            if(xa[i] != 0 && seat[r][i] == '#') return false;
            if(ya[i] != 0 && seat[r-1][i] == '#') return false;
        }
        for(int i = 0; i < p; i++)
        {
            if(xa[i] != 0)
            {
                if(i == 0)
                {
                    if((xa[i+1] || ya[i+1]) != 0)
                        return false;
                }
                else if(i == p-1)
                {
                    if((xa[i-1] || ya[i-1]) != 0)
                        return false;
                }
                else
                {
                    if((xa[i-1] || xa[i+1] || ya[i-1] || ya[i+1]) != 0)
                        return false;
                }
            }
        }
        return true;
    }

    bool check1(int r, int x, int p, vector<vector<char>>& seat)
    {
         int xa[8];
         int t = 1;
         for(int i = 0; i < p; i++, t <<= 1)
           {
                xa[i] = (t & x);
                if(xa[i] != 0 && seat[r][i] == '#') return false;
                if(xa[i] != 0 && i > 0 && xa[i-1] != 0) return false;
           }
        return true;
    }

    int count(int x)
    {
        int res = 0;
        while(x)
        {
            res += (x & 1);
            x >>= 1;
        }
        return res;
    }

    int maxStudents(vector<vector<char>>& seat) {
        int m = seat.size(), n = seat[0].size();
        int dp[9][1<<9];
        int p = min(n,8);
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < (1<<p); j ++)
            {
                if(i == 0)
                {
                    if(check1(i, j, p, seat))
                        dp[i][j] = count(j);
                }
                else
                    for(int k = 0; k < (1<<p); k++)
                        if(check(i,j,k,p,seat))
                        {
                            dp[i][j] = max(dp[i][j], dp[i-1][k] + count(j));
                        }
                if(i == m-1) res = max(res, dp[i][j]);
            }
       return res;
    }
};
```
