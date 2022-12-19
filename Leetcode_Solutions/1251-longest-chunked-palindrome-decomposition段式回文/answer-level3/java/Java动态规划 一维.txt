### 解题思路
动态规划dp[i] 表示字符串[0:i-1]中段式回文有多少个。比较看是否前面的一段字符，是否对应于后面的一段字符
转移：通过枚举前面的每一个状态，比较每一个状态是否可以是段氏回文。如果dp[j]后面有一段j到i的段式回文，那么dp[i]则为dp[j]+1;
比如：dp[j]=3表示[0:j]有3个段式回文,那么我们可以在j的后面继续去比较是否有段式回文

### 代码

```java
class Solution {
    public int longestDecomposition(String text) {
        int n=text.length(),ans=1;
        int dp[]=new int[n/2+1];
        char[] char1=text.toCharArray();
        Arrays.fill(dp,-1);
        dp[0]=0;
        //设置比较回文的起点
        int left=0;
        for(int i=1;i<=n/2;i++)
            for(int j=left;j<i;j++){
                //[0:j]中没有段式回文，不用再去比较j后面的了
                if(dp[j]==-1) continue;
                if(!check(char1,j,i,n)) continue;
                dp[i]=dp[j]+1;
                //更新left起点,i前面的字符串是段氏回文了，已经处理好了。
                left=i;
            }
            //如果left*2<n说明最中间还有一段字符没有处理，就单独作为一个段氏回文。
        return Math.max(ans,dp[left]*2+(left*2<n?1:0));
    }
    //暴力比较是否是回文字符串
    boolean check(char[] char1,int j,int i,int n){
        //n-i为后面字符串的起点,(m-j)为每次增加的量
        for(int m=j;m<i;m++)
            if(char1[m]!=char1[n-i+(m-j)]) return false;
        return true;
    }
}
```