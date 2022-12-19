```
    //区间dp 设 f[i][j] 在有第i~j堆石子时 先手最多能赢出的分数
    //       则f[i][j] = max(a[i]-f[i+1][j],a[j]-f[i][j-1])
    //即 我能赢出的分数 = max(当前的得分-对手能赢出的分数)
    //边界条件 f[i][i] = a[i]
    //目标只需要 f[0][n-1] > 0 即可胜利
    //由于转移方程中仅涉及相邻两个数组的转移 故而可以优化为n*n的数组优化为2*n
    //此时的状态转移只需要无脑&1即可 表示前后转移关系  f[i&1][j] = max(a[i]-f[(i+1)&1][j],a[j]-f[i&1][j-1])
    bool stoneGame(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> f(2,vector<int>(n));
        for(int len = 1; len <= n; len++){//区间长度
            for(int i = 0; i + len - 1 < n; i++){//区间左端点
                int j = i + len -1;//区间右端点
                if(i==j) f[i&1][i] = a[i];
                else f[i&1][j] = max(a[i]-f[(i+1)&1][j], a[j]-f[i&1][j-1]);
            }
        }
        return f[0&1][n-1]>0;
    }
```
