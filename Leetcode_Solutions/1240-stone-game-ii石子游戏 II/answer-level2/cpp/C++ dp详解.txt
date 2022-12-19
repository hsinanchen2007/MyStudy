```
    //f[i][j]表示在i~n-1堆石子中 且最多拿前2*j堆时先手能拿到的最大数量
    //则f[i][j] = max(sum_a[i~n-1] - f[i+k][max(j,k)])  1<=k<=2*j
    //即假设先手选了前k堆 则先手得到的最大数量= max(总量-对手最多拿到的数量)
    //边界条件 f[n-1][1~n] = a[n-1]
    //答案为 f[0][1]
    int stoneGameII(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> f(n+1,vector<int>(n+1));//注意第一维多开一位 防止越界
        int sum = 0;//后缀和
        for(int j = 1; j <= n; j++) f[n-1][j] = a[n-1];//边界条件初始化
        for(int i = n-1; i >= 0; i--){//在i~n-1堆石子中
            sum += a[i];
            for(int j = 1; j <= n; j++){//最多拿2*j个石子时
                for(int k = 1; k <= 2*j && k <= n-i; k++){//在i~n-1中 拿前k堆时
                    f[i][j] = max(f[i][j],sum-f[i+k][max(j,k)]);
                }
            }
        }
        return f[0][1];
    }
```
