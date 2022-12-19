### 1.递归（超时）
这里递归的做法我们拿题目中的一个例子来看：horse，ros
![image.png](https://pic.leetcode-cn.com/5fe3297f1c80530708d0c53c4f266abc433322ae7546a30e07e27ad5c9c2439b-image.png)
比较这三种情况所需的步数，返回一个最小者，当然如果遇到两个字符串的某一位是相同的情况，此时直接跳过这个字符，去看剩下字符所需的最小的步数
```java
class Solution {
    int exange(int i,int j,char[] o,char[] t){
        //如果i，j都为0，则返回0
        if(i==0&&j==0){
            return 0;
        }
        
        //如果i为0或者j为0,直接返回较长的那个的长度
        if(i==0||j==0) return i==0? j:i;
        
        //如果o[i]==t[j],则继续看剩下的
        if(o[i-1]==t[j-1]) return exange(i-1,j-1,o,t);
        
        int one=exange(i-1,j,o,t)+1;
        int two=exange(i,j-1,o,t)+1;
        int three=exange(i-1,j-1,o,t)+1;
        
        return Math.min(one,Math.min(two,three));
    }
        
    public int minDistance(String word1, String word2) {
        int i=word1.length();
        int j=word2.length();
        
        char[]o=word1.toCharArray();
        char[]t=word2.toCharArray();
        
        return exange(i,j,o,t);
    }
}
```
### 2. 递归+记忆化（通过）
从上一个例子，我们画一下它所对应的递归树
![image.png](https://pic.leetcode-cn.com/715babf5bb43a889de6bc4be09b92421abefcd528e524407756660129a1b0b6c-image.png)
可以看到，对于word1长度为i和word2长度为j的情况会有一些重复的计算，由此这里使用一个二维数组memo[i][j]保存对于word1长度为i，word2长度为j所对应的最小的转变步数
```java
class Solution {
    int[][]memo;
    
    int exange(int i,int j,char[] o,char[] t){
        //如果i，j都为0，则返回0
        if(i==0&&j==0){
            return 0;
        }
        
        //如果i为0或者j为0,直接返回较长的那个的长度
        if(i==0||j==0) return i==0? j:i;
        
        //如果o[i]==t[j],则继续看剩下的
        if(o[i-1]==t[j-1]) return exange(i-1,j-1,o,t);
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        int one=exange(i-1,j,o,t)+1;
        int two=exange(i,j-1,o,t)+1;
        int three=exange(i-1,j-1,o,t)+1;
        
        memo[i][j]=Math.min(one,Math.min(two,three));
        return memo[i][j];
    }
        
    public int minDistance(String word1, String word2) {
        int i=word1.length();
        int j=word2.length();
        
        memo=new int[i+1][j+1];
        for(int k=0;k<=i;k++) Arrays.fill(memo[k],-1);
        
        char[]o=word1.toCharArray();
        char[]t=word2.toCharArray();
        
        return exange(i,j,o,t);
    }
}
```
### 3. 动态规划（通过）
从上面的递归树可以看出，该问题具有重叠子问题，而且具有最优子结构，也就是对于父问题的最优解来自于子问题的最优解，所以这里可以使用动态规划来解决，我们这里定义状态dp[i][j]表示word1长度为i，word2长度为j所对应的最小的移动步数，那么dp[i-1][j]+1就表示的是word1的前i-1个字符转变为word2,然后再删除word1的第i个字符，也就是删除操作，dp[i][j-1]+1表示的是word1的前i个字符转变为word2的前j-1个字符，然后再插入word2的第j个字符，也就是插入操作，dp[i-1][j-1]+1表示的是word1的前i-1个字符转变为word2的前j-1个字符，然后将word1的第i个字符替换为word2的第j个字符，也就是替换操作，故最后的状态转移方程变为
> dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1

当然这里同递归的思路一样，如果word1的第i个字符与word2的第j个字符相同，那么dp[i][j]=dp[i-1][j-1]，也就是此时的这个字符无需操作，继续看剩下的字符
```java
class Solution {
    public int minDistance(String word1, String word2) {
        int n=word1.length();
        int m=word2.length();
        
        //设置一个dp表示word1长度为i，word2长度为j的最小的操作数
        int[][]dp=new int[n+1][m+1];
        
        char[]w1=word1.toCharArray();
        char[]w2=word2.toCharArray();
        
        //初始化
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++) dp[i][0]=i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //如果i和j相同，则此时的最小的步数与dp[i-1][j-1]相同
                if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=Math.min(dp[i-1][j],Math.min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }
        
        return dp[n][m];
    }
}
```