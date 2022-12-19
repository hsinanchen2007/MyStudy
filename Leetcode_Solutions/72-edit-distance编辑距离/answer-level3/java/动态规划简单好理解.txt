### 解题思路
这题还算比较简单的动态规划，理解了就很容易了。

用`dp[i][j]`表示word1的前i个字符串转换为word2的前j个字符串所需要的最小步骤。
假设现在`dp[i][j]`表示"int"转换为"exec"的最小步骤，那么可以这样分析：
int->exec有三种方式：
1. 在int已经转换为exe的基础上，增加一个字符'c'
2. 在in已经转换成exec的基础上，如果int要转换为exec，显然应该删去一个字符't'
3. 在in已经转换成exe的基础上，如果int->exec，显然字符't'应该替换成'c'
这三种情况表示成代码分别为：
1. `dp[i][j]=dp[i][j-1]+1;`
2. `dp[i][j]=dp[i-1][j]+1;`
3. `dp[i][j]=dp[i-1][j-1]+1;`
具体取哪个值，当然是选取最小的那一个。
另外还得考虑另外一种简单的情况:
比如："inte"转换成"exe"
由于末尾字符相同皆为'e'，那么显然最小步骤就是等于"int"转换成"ex"的最小步骤。
即`dp[i][j]=dp[i-1][j-1];`

最后总结一下：
如果`word1[i]==word2[j]`
    `dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);`
如果`word1[i]!=word2[j]`
    `dp[i][j]=dp[i-1][j-1];`

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) 
    {
        
        int len1=word1.length(),len2=word2.length();
        if(len1==0||len2==0)return len1==0?len2:len1;
        int display[][]=new int[len1+1][len2+1];
        display[0][0]=0;
        for(int i=1;i<=len2;i++)display[0][i]=i;
        for(int i=1;i<len1;i++)display[i][0]=i;
        
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(word1.charAt(i-1)!=word2.charAt(j-1))
                {
                    display[i][j]=
                    Math.min(
                            display[i-1][j-1],
                            Math.min(display[i-1][j], display[i][j-1])
                    )+1;
                }
                else display[i][j]=display[i-1][j-1];
            }
        }
        
        return display[len1][len2];
    }
}
```