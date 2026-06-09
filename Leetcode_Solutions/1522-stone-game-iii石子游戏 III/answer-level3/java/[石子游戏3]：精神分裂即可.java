
其实这是 Alice 一个人的精分游戏，你老想着有两个人在博弈就会很难下手。

一开始，Alice 面临取1、2、3 堆的抉择，**Alice 此刻总共能拿多少分，取决于取完 1 or 2 or 3 堆之后面对剩下的这堆石子精分出来的 Bob能拿多少分，因为剩下的分就是 Alice 的。**

也就是 $dp[i]=Max(sum-dp[i+1],sum-dp[i+2],sum-dp[i+3])$ ，dp[i]为石碓 i……n 得最高分数，sum 为 i……n 的石碓分数之和。

那 Alice 的得分即为：dp[0] ，Bob 得分为 sumAll-dp[0]。

这其实是个非常简单的动规。

---

- 平时我们写的大多数 dp 都是 0 到 n，这里是 n 到 0，可能会有些不习惯。
- 有童鞋还是想不清为啥明明两个人，可以用一个 dp[] 解决。你这样想，dp 代表的不是人，而代表的是那个最优策略。



### 附 java

```java
class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n=stoneValue.length;
        int[] dp=new int[n+1];
        
        dp[n]=0;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            //由于有负值分数，这里注意一下
            dp[i]=Integer.MIN_VALUE;
            sum+=stoneValue[i];
            for(int j=i;j<i+3 && j<n;j++){
                dp[i]=Math.max(dp[i],sum-dp[j+1]);
            }
        }
        int alice=dp[0];
        int bob=sum-dp[0];
        if(alice==bob) return "Tie";
        if(alice>bob) return "Alice";
            return "Bob";
    }
}
```


