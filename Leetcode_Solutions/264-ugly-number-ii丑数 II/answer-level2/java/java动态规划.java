在刚看到这个题目的时候可能会疑惑,如何找到顺序
因为是有三种乘的方法.
那么就让同一个数都乘一下这三个数字.
用三个指针同时对着第一个数字,i增加的时候查看此时三个指针指向的数字,
分别乘以这三个数字.找出其中最小的即为dp[i],并且这个数字对应的指针++

```
class Solution {
    public int nthUglyNumber(int n) {       
        if(n==0)
            return 0;
        if(n==1){
            return 1;
        }
        int []dp=new int[n+1];
        int p2=1;
        int p3=1;
        int p5=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int m2=dp[p2]*2;
            int m3=dp[p3]*3;
            int m5=dp[p5]*5;
            int m=Math.min(m2,Math.min(m3,m5));
            if(m==m3)p3++;
            if(m==m5)p5++;
            if(m==m2)p2++;
            dp[i]=m;
        }
        return dp[n]; 
    }
}
```
