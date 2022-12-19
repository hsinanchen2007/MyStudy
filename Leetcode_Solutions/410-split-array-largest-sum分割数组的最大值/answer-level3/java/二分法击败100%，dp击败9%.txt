### 解题思路
此处撰写解题思路

### 代码
二分
```java
class Solution {
    public int splitArray(int[] nums, int m) {
        int n = nums.length;
        long start = 0, end = 0;
        for(int i = 0; i < n; i++){
            //直接把所有和加起来，作为end
            end += nums[i];
        }
        while(start + 1 < end){
            //枚举这个最小的
            long mid = start + (end - start)/2;
            //如果能满足条件，继续缩小范围
            if(check(nums,m,mid)){
                end = mid;
            }else{
                start = mid;
            }
        }
        //再判断下头和尾巴
        if(check(nums,m,start)){
            return (int)start;
        }else{
            return (int)end;
        }
    }
    
    //看能不能满足条件，也就是切成m段，每段的和不超过 limit（也就是上面的mid）
    private boolean check(int[] nums,int m, long limit){
        int cnt = 0;
        long val = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > limit) return false;
            if(val+ nums[i] > limit){
                cnt += 1;
                val = 0;
            }
            val += nums[i];
        }
        //段数是否小于m，从0开始的，所以到m-1，如果你cnt从1开始就看是不是<=m
        return cnt < m; 
    }
}
```

dp
```java
class Solution {
    public int splitArray(int[] nums, int m) {
        int n = nums.length;
        long[][] dp = new long[m+1][n+1];
        //初始化第一行
        for(int i = 1; i <= n; i++){
            dp[0][i] = 0x7fffffff;
        }
        dp[0][0] = 0;
        //枚举拆分段数
        for(int i = 1; i<=m; i++){
            //枚举前j个数字
            for(int j = 1; j <= n; j++){
                dp[i][j] = 0x7fffffff;
                long sum = 0;
                for(int k = j; k >= 0; k--){
                    dp[i][j] = Math.min(dp[i][j],Math.max(dp[i-1][k],sum));
                    if(k >0){
                        sum += nums[k-1];
                    }
                }
            }
        }
        return (int)dp[m][n];
    }
}
```