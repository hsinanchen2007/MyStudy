

```
        #T的最后加一个超大的数
        T += [float('inf')]
        l = len(T)
        #dp指向在T[i+1:]中首个大于T[i]的元素
        dp = [0 for _ in range(l)]
        dp[l-1] = l-1
        for i in range(l-2,-1,-1):
            n = i+1
            while T[n] <= T[i]:
                n = dp[n]
            dp[i] = n
        #将dp变成符合题意的输出
        for i in range(l-1):
            if dp[i] == l-1:
                dp[i] = 0
            else:
                dp[i] = dp[i]-i
        return dp[:-1]
```
