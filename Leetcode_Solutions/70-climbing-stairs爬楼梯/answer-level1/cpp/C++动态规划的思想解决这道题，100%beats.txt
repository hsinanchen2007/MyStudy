分析题目,动态规划的要义就是充分利用前面的答案来帮助后面
```
    int climbStairs(int n) {
        int * a = new int [n+1];
        a[0]=1;
        a[1]=1;
        for(int i=2;i<n+1;++i)
        {
            a[i]=a[i-1]+a[i-2];
        }
        return a[n];
    }
```

