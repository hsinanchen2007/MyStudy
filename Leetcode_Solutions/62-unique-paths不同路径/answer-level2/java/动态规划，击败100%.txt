### 解题思路
![image.png](https://pic.leetcode-cn.com/9145c8e5d19c575a22b23709ba6706e5b03c3597a031f2395195a3a74436a1fe-image.png)

容易想到回溯法，每一步可选向下或者向右，但是超时
换个思路自顶向下分析，最后一步有两种方式到达，即dp[i][j]=dp[i-1][j]+dp[i][j-1]，因此有了自底向上的动态规划求解

### 代码

```java
class Solution {
    long count;
    public int uniquePaths(int m, int n) {
        //trace(m-1,n-1,0,0);
        int[][] dp=new int[n][m];
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int i=0;i<m;i++) dp[0][i]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }


    //回溯法，超时
    public void trace(int m,int n,int x,int y){
        //System.out.println(x+" "+y);
        if(x==m&&y==n) count++;
        else{
            if(x<m) trace(m,n,x+1,y);
            if(y<n) trace(m,n,x,y+1);
        }
    }
}
```