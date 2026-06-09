### 解题思路
![QQ截图20200315215937.png](https://pic.leetcode-cn.com/88ddbdf6ca5565f24c834d3899e89029c96c741d90a0ca13cc3c40c827b6f859-QQ%E6%88%AA%E5%9B%BE20200315215937.png)

递归方程：
dp_len[i][j]={
0       if:i==0 or j==0
dp_len[i-1][j-1]+1      if:text1[i-1]==text2[j-1]
max(dp_len[i-1][j],dp_len[i][j-1])    if:text1[i-1]!=text2[j-1]
}
### 代码

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        char [] chars_text1=text1.toCharArray();
        char [] chars_text2=text2.toCharArray();
        int [][] dp_len=new int[chars_text1.length+1][chars_text2.length+1];
        for(int i=0;i<=chars_text1.length;i++){
            dp_len[i][0]=0;
        }
        for(int i=0;i<=chars_text2.length;i++){
            dp_len[0][i]=0;
        }
        for(int i=1;i<=chars_text1.length;i++){
            for(int j=1;j<=chars_text2.length;j++){
                if(chars_text1[i-1]==chars_text2[j-1]) dp_len[i][j]=dp_len[i-1][j-1]+1;
                else if(dp_len[i][j-1]>=dp_len[i-1][j]) dp_len[i][j]=dp_len[i][j-1];
                else dp_len[i][j]=dp_len[i-1][j];    
            }
        }
        return dp_len[chars_text1.length][chars_text2.length];

    }
}
```