记：F[i][j][a=0/1]表示第i到j个数字计算结果为a的方案数。
转移：枚举区间分割点，讨论左右区间计算结果，方案数增量为左右方案数相乘。
时间复杂度：O(n^3)  空间复杂度：O(n^2)
```
class Solution {
public:
    int countEval(string s, int result) {
        int len=s.size();
        vector<int> A;
        vector<char> opt;
        for (int i=0;i<len;++i)
            if (i&1) opt.push_back(s[i]);
            else A.push_back(s[i]-'0');
        int n=A.size();
        int F[n][n][2];
        for (int i=0;i<n;++i) F[i][i][A[i]]=1,F[i][i][A[i]^1]=0;
        for (int l=2;l<=n;++l)
        {
            for (int i=0;i+l-1<n;++i)
            {
                int j=i+l-1;
                F[i][j][0]=F[i][j][1]=0;
                for (int k=i;k<j;++k)
                    if (opt[k]=='&')
                    {
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
                    else if (opt[k]=='|')
                    {
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][1]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
                    else
                    {
                        F[i][j][0]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][1]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
            }
        }
        return F[0][n-1][result];
    }
};
```
