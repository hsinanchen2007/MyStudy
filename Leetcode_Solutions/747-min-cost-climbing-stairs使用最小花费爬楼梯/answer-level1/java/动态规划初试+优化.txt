**解法1，动态规划**
     最后一阶梯所最小花费取决于它前面的一阶或者两阶的花费，即 第n阶最小花费=min(dp[i - 1], dp[i - 2])+cost[i];
     又走完楼梯的最后一阶可以是最后一阶或者倒数第二阶（一次可以爬1或者2），所以只要比较第n阶和第n-1阶所花费的最小的代价就可以了。
    
```
 int length = cost.length;
       int length = cost.length;
        if (length <1) return 0;
        int dp[] = new int[length+1];
        /*设置dp边界值，为1阶的时候花费0*/
        dp[0] = 0;
        dp[1] = cost[0];
        for (int i = 2; i <=length; i++) {
            dp[i] = Math.min(dp[i - 1], dp[i - 2])+cost[i-1];
        }
        return  Math.min(dp[length ], dp[length - 1]);
```
**解法2**
      从动态规划解法可以得出，n阶花费最少只取决于前两阶，所以不用建立以为dp数组，直接设置两个参数更新相对的前两个花费最小

    
```
int length = cost.length;
        if (length <=1) return 0;
        int now=0;
        int previous=0;
        for (int i = 0; i <length; i++) {
            int temp=now;
            /*每次更新前一位和前两位的值*/
            now=Math.min(now,previous)+cost[i];
            previous=temp;
        }
        return  Math.min(now, previous);
```
