做这种题一定要画图，找转移方程，一点都不难
就怕你眼高手低，企图用脑子想想就想出转移方程，
不排除有大佬可以做到，但是如果没有一定的积累并且脑子也不太聪明（比如我）最好动笔画一画哈
样例画图
![image.png](https://pic.leetcode-cn.com/173c33de64e4d7f10b0f116f9f5e02fb19dd7ceb8bdbc9c211048fe2f9ab01f1-image.png)
![image.png](https://pic.leetcode-cn.com/8e3cc290d96547ffa517eb377e871bddab2fef7c52dfc838801f785a10c2cc24-image.png)
考虑第二个比较复杂 t1： ezupkr和t2：ubmrapg
dp[i][j]的含义是t1的[0:i-1]和t2的[0:j-1]的最长公共子序列

思路就是：
先选出t1的第一个字符e和t2去比对，发现没有符合的，所以图的第一排都是0
再选t1的第二个字符z和t2区比对，同理第二排全是0
*再选t1的第三个字符u，发现t2第一个字符是u，所以出现相同的字符了，第三排都是1，因为至少`dp[i][j]=dp[i][j-1]`;  如 t1: u    t2:uabc dp[1][4]=dp[1][3]=dp[1][2]=dp[1][1]=1;
*再选t1的第四个字符p，发现当t2只有一个字符u的时候，t1的前四个字符ezup与它的最长公共序列为1，不管t1有多长至少是1， 所以`dp[i][j]=dp[i-1][j];` 如  t1：ezup t2：u dp[4][1]=dp[3][1]=1;当t2选到倒数第二个字符，也就是t2：ubmrap  ，t1:ezup   即text1.charAt(i-1)==text2.charAt(j-1)，我们把t2和t1的最后一个字符删除  t2:ubmra  t1:ezu  发现dp[3][4]=1，再加上p，dp[4][5]=1+1=2, 这又是另一种情况了   `dp[i][j]=1+dp[i-1][j-1]；`
根据上边两条，我们可以得到当`text1.charAt(i-1)！=text2.charAt(j-1)`时：`dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1])`;
                    当`text1.charAt(i-1)==text2.charAt(j-1)`时，`dp[i][j]=1+dp[i-1][j-1]；`


```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        
        if(text2.length()==0||text1.length()==0)return 0;
        int[][] dp=new int[text1.length()+1][text2.length()+1];
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                dp[i][j]=text1.charAt(i-1)==text2.charAt(j-1)?(1+dp[i-1][j-1]):Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
}

```
