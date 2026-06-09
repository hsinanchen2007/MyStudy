方法二： 动态规划： dp[i] 表示操作i步后能输出的'A'的最大个数

方法一的问题，在于缓冲区的大小可以很大，所以状态中不应该包含缓冲区。
方法二，在求解dp[i]中，可以选择press key1来直接输出1个'A',也可以选择复制缓冲区中的内容，
但是缓冲区的大小不可知，所以需要遍历为与它之前的状态；
每次把i当成是最后一次操作，最后一次操作显然不可能是key2 or key3
在某个位置按key2,key3后， 按key3带来的增加值一定大于按key1带来的增加值
```
vector<int> dp(N+1,0);
        dp[0] = 0;
        for(int i=1; i<=N; i++){
            // 第i个操作为key1
            dp[i] = dp[i-1]+1;
            // 第i个操作为key4
            for(int j=2; j+1<i; j++){
                // j,j+1
                dp[i] = max(dp[i], dp[j-1]*(i-j));
            }
        }
        return dp[N];
```

方法一： 动态规划： dp[i][j]第i次操作后且缓冲区大小为j时能输出的'A'的最大的个数
最优解情况下，key2和key3操作一定是紧挨着
```
        // 容易想到状态（操作ID，缓冲区大小），但是不可行，缓冲区可以很大
        vector<vector<int>> dp(N+1, vector<int>(20*N+1, -1));
        dp[0][0] = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(dp[i][j]!=-1){
                    // press key1
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j]+1);
                    // press key4
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j]+j);
                    // press key2+key3
                    if(i+2<N+1)
                        dp[i+2][dp[i][j]] = dp[i][j];
                }
            }
        }
        int ans = dp[N][0];
        for(auto val : dp[N]) ans = max(ans, val);
        return ans;
```