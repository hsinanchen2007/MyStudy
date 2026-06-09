### 解题思路
类似于背包问题，n种物品和空间大小为m的资源；
这里就是x个字符，和m个0与n个1，0和1相当于资源，每取出一个字符串，就在其【zeros,ones】矩阵之外更新元素，
    状态方程：dp[i][j]=Math.max(dp[i][j],1+dp[i-zeros][j-ones])判断当前字符串是加  or   不加

### 代码

```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        if(strs==null||strs.length==0) return 0;
        int[][] dp=new int[m+1][n+1];
        for(String str:strs){
            int zeros=0,ones=0;
            for(char c:str.toCharArray()){
                if(c=='1') ones++;
                if(c=='0') zeros++;
            }
            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j]=Math.max(dp[i][j],1+dp[i-zeros][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
}
```