![屏幕快照 2020-02-26 上午12.28.38.png](https://pic.leetcode-cn.com/9dcf0129154fe4933f04afd1d74cfcb5411330ae751c38fa71049d306db229d3-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-26%20%E4%B8%8A%E5%8D%8812.28.38.png)

设置三个指针，进行动态规划，分别比较a2,a3,a5三种指针所指的数的2，3，5倍，找出最小的数放入数组后，再更新被替换的指针（指针向后移一位）


```
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0]=1;
        int a2=0,a3=0,a5=0,min;
        for(int i=1;i<n;i++){
           min=Math.min(dp[a2]*2,Math.min(dp[a3]*3,dp[a5]*5));
           if(min==dp[a2]*2) a2++;
           if(min==dp[a3]*3) a3++;
           if(min==dp[a5]*5) a5++;
           dp[i]=min;
        }
        return dp[n-1];
    }
```

