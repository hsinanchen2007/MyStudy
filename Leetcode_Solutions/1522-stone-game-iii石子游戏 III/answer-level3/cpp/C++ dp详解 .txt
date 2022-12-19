```
    //f[i]表示对于i~n-1堆石子中,先手最多能赢出的分数
    //           f[i] = max(sum_a[i~i+j-1] - f[i+j]) 1<=j<=3
    //即 我能赢出的分数 = max(当前的得分 - 对手能赢出的分数)
    //边界条件f[n-1] = a[n-1],f[n] = 0;
    //则答案 f[0]>0 ? "Alice": (f[0]==0:"Tie":"Bob")
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vector<int> f(n+1,0xcfcfcfcf);
        f[n-1] = a[n-1],f[n] = 0;
        for(int i = n-1; i >= 0; i--){//对于i~n-1堆石子时
            int sum = 0;
            for(int j = 1; j <= 3&&j<=n-i; j++){//最多能取前j堆石子
                sum += a[i+j-1];
                f[i] = max(f[i],sum-f[i+j]);
            }
        }
        return f[0] > 0 ? "Alice" : (f[0]==0 ? "Tie":"Bob"); 
    }
```
