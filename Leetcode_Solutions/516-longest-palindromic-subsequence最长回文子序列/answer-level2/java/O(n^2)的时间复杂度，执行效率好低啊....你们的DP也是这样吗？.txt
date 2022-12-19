### 解题思路
![QQ截图20200330164006.png](https://pic.leetcode-cn.com/fa0a40822d603455f0d7ae9cb28061e6ee0eab8dc556009ea5e5f08c885d44df-QQ%E6%88%AA%E5%9B%BE20200330164006.png)

执行出来好慢啊，裂开

比较简单的一道题，建议类比5.最长回文子串的问题：在最长回文子串中,dp[i][j]是True或False,表示子串s[i...j]是不是回文，每当True的时候就更新最大的(j-i)值，而在本问题中，**dp[i][j]代表子串s[i...j]中的最长回文子序列的长度**，因为s[i...j]可能本身不是回文，但是它肯定含能构成回文的子序列（长度至少为1），原问题的解就存放于dp[0][n-1]中

状态转移方程：
dp[i][j]={

**1**...if i==j     //一个字符

**2**...if j=i+1 and s[i]==s[i+1]   或 **1**...if j=i+1 and s[i]==s[i+1]      //两相邻字符

**dp[i+1][j-1]+2**...if s[i]==s[j]   //注意这时不必再考虑s[i+1...j-1]本身是不是回文了，只要两端字符相等，就加2

**max(dp[i+1][j],dp[i][j-1])**...else      //其他情况，长度为r的子串的最长回文子序列是它其中的两个长为(r-1)的子串的最长回文子序列之一，比如bba的最长回文子序列是bb，abb的最长回文子序列是bb

}

填表方向与矩阵连乘积问题、多边形的三角刨分问题、最长回文子串等一致，均沿着对角线向右上位置填表

这个暴力肯定是不可取的，因为是子序列不是子串，一个长为n的序列，其子序列为2^n个，指数级的
### 代码

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n=s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        int [][]dp_len_seq=new int[n][n];//dp_len_seq[i][j]表示字符串s[i...j]的最长回文子序列的长度
        for(int i=0;i<n;i++) dp_len_seq[i][i]=1;//单个字符是一个回文

        for(int r=2;r<=n;r++){//待检查字符串的长度，最长时即整个字符串
            for(int i=0;i<n-r+1;i++){
                if(r==2){//相邻两个字符的情况
                    if(s.charAt(i)==s.charAt(i+1)) dp_len_seq[i][i+1]=2;
                    else dp_len_seq[i][i+1]=1;
                }else{
                    //r>=3的情况
                    int j=i+r-1;
                    if(s.charAt(i)==s.charAt(j)) dp_len_seq[i][j]=dp_len_seq[i+1][j-1]+2;//两端相等
                    //两端不等时，长度为r的最长回文子序列的长度为max(长度为r-1的两个最长回文子序列的长度）
                    else if(dp_len_seq[i+1][j]>dp_len_seq[i][j-1]) dp_len_seq[i][j]=dp_len_seq[i+1][j];
                    else dp_len_seq[i][j]=dp_len_seq[i][j-1];
                }
            }

        }
        return dp_len_seq[0][n-1];

    }
}
```