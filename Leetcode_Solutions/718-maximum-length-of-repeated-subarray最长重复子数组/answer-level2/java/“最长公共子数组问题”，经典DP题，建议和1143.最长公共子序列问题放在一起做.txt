### 解题思路
![QQ截图20200403170046.png](https://pic.leetcode-cn.com/767444b04436da5c4eb4a0bfc385a31a304c093ff9cc48759fb22ef7cebdd9f1-QQ%E6%88%AA%E5%9B%BE20200403170046.png)
十分经典的动态规划题了啊，想好怎么定义状态就好说了

定义dp[i][j]表示以A[i]和B[j]为结尾的公共子数组的最长长度（注意公共子数组一定分别包含A[i]和B[j]作为末元素，类比最大子段和问题）
当A[i]!=B[j]时，dp[i][j]=0,    因为以A[i]和B[j]结尾的公共子数组不存在，因为它们的末元素不等
当A[i]==B[j]时，dp[i][j]=dp[i-1][j-1]+1,    因为A[i]和B[j]相等，以它们俩为结尾的最长公共子数组的长度就是**以A[i-1]和B[j-1]结尾的最长公共子数组的长度加1**

之所以这样定义状态是因为原问题所要求的最长公共子数组如果存在，它一定是以某一个A的元素结尾，也以某一个B的元素结尾，现在就是遍历所有可能的**分别以哪两个元素结尾的情况**，取其中的最长的情况即可

类比1143.最长公共子序列问题：因为该问题中是子数组，元素要求是连续的，所以当A[i]!=B[j]时，直接置dp[i][j]=0即可，此时以A[i]和B[j]结尾的最长子数组压根不存在，而最长公共子序列问题中，即使A[i]!=B[j]，也要将前面求出来的最长子序列长度继承下来


时间复杂度O(n^2)

### 代码

```java
class Solution {
    public int findLength(int[] A, int[] B) {
        int len_a=A.length;
        int len_b=B.length;
        if(len_a==0||len_b==0) return 0;
        int res=0;
        int [][] dp=new int[len_a][len_b];
        for(int i=0;i<len_a;i++) {
            if(A[i]==B[0]) {res=1;dp[i][0]=1;}
        }
        for(int j=1;j<len_b;j++) {
            if(A[0]==B[j]) {res=1;dp[0][j]=1;}
        }
        for(int i=1;i<len_a;i++){
            for(int j=1;j<len_b;j++){
                if(A[i]==B[j]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(dp[i][j]>res) res=dp[i][j];
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return res;


    }
}
```