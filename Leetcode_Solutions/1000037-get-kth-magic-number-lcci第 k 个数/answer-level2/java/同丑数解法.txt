三指针动态规划
```
class Solution {
    public int getKthMagicNumber(int k) {
        if(k==1) return 1;
        int[] dp = new int[k];
        dp[0]=1;
        int p3=0;
        int p5=0;
        int p7=0;
        int now = 1;
        while(now<k){
            int temp = Math.min(Math.min(dp[p3]*3,dp[p5]*5),dp[p7]*7);
            if(dp[p3]*3==temp)  p3++;
            if(dp[p5]*5==temp) p5++;
            if(dp[p7]*7==temp) p7++;
            dp[now++]=temp;
        }
        return dp[k-1];
    }
}
```
