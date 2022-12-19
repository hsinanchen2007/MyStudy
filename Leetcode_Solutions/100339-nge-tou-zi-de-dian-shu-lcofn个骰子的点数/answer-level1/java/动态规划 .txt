### 解题思路
n个骰子，每个骰子6个面，总情况数为$6^n$。
设$F(n,s)$为当骰子数为n，和为s的情况数量。
$当n=1时，F(1,s)=1,其中s=1,2,3,4,5,6$
$当n\ge2时，F(n,s)=F(n-1,s-1)+F(n-1,s-2)+F(n-1,s-3)+F(n-1,s-4)+F(n-1,s-5)+F(n-1,s-6)$
或者更准确的：$F(n,s)=\sum_{d=1}^{min(6,s-n+1)} F(n-1,s-d)$，为了使得$s-d\ge n-1$

时间复杂度：$O(n^2)$
空间复杂度：$O((n+1)(6n+1))=O(n^2)$
由于$n\le 11$，时间是不算长的
由于$6^{11}=362797056$没有超出int范围，故可以放心用int

最后概率为$P(n,s)=\frac{F(n,s)}{6^n}$

### 代码

```java
class Solution {
    public double[] twoSum(int n) {
        int [][]dp = new int[n+1][6*n+1];
        //边界条件
        for(int s=1;s<=6;s++)dp[1][s]=1;
        for(int i=2;i<=n;i++){
            for(int s=i;s<=6*i;s++){
                //求dp[i][s]
                for(int d=1;d<=6;d++){
                    if(s-d<i-1)break;//为0了
                    dp[i][s]+=dp[i-1][s-d];
                }
            }
        }
        double total = Math.pow((double)6,(double)n);
        double[] ans = new double[5*n+1];
        for(int i=n;i<=6*n;i++){
            ans[i-n]=((double)dp[n][i])/total;
        }
        return ans;
    }
}
```