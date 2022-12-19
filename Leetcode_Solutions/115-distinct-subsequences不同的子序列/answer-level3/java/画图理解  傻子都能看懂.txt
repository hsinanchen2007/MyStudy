![image.png](https://pic.leetcode-cn.com/e42035e60a10e3396628c798d20d1634f3bf7693443b1835535a39db6100f91f-image.png)
无论如何 dp[i][j]至少都等于dp[i][j-1]也就是S的第j个字符我不用了我也是总冠军 （你没来之前我们已经是总冠军了）可能比喻不恰当哈
如果下标i和j的字符又相等了，那我加上去掉S的第j个字符和t的第i个字符后的子序列个数 

有人会担心 dp[i][j]=dp[i-1][j-1]+dp[i][j-1] 相加以后不会有重合的嘛
仔细看图你会发现并不会，
每个值都依赖左侧和左上，
而并不依赖上方的值，
所以左侧和左上并不会相互依赖，
所以并不会出现重复的情况

```java
class Solution {
    public int numDistinct(String s, String t) {
        //s串能找到多少个t 假设t为null那么能找到1个
        //dp[i][j]表示 s串[0:i]可以找到多少个t串[0:j];
        //当t串比s串还长肯定找不到，所以矩阵左下角全是0
        //为了方便 当s和t都是空串时即dp[0][0]=1。
        int[][] dp=new int[t.length()+1][s.length()+1];
        for(int i=0;i<dp[0].length;i++){
            dp[0][i]=1;
        }
        
        for(int i=1;i<dp.length;i++){
            for(int j=i;j<dp[0].length;j++){
                if(s.charAt(j-1)==t.charAt(i-1)){
                    if(i==j)dp[i][j]=dp[i-1][j-1];//当长度相等只可能是0或1 如rab和rab （1）  如rcb和rab  （0）
                    if(i!=j)dp[i][j]=dp[i-1][j-1]+dp[i][j-1];//当长度不等  如rab和rabbb (3) = ra和rabb(2) 加上 ra和rabbb (1)
                    //dp[i][j]=dp[i-1][j-1]+i==j?0:dp[i-1][j];
                }else dp[i][j]=dp[i][j-1];//当前两个字符不等， 如rab和rabbbi i!=b  所以看rab和rabbb (3)
            }
        }
        return dp[t.length()][s.length()];
    }
}
```
