### 解题思路
判断一步是否可以跳到另一步，可以用dp求解
对于状态方程中，我们要从题目保留的是：
1.**当前的位置**
2.**上一次跳跃的距离**
**dp[i][j] 中 i表示当前的位置，j表示上一次跳跃的距离**
转移：
**每次都和前面每一个石头比较，看是否能跳过来**

由于每次只能比上一次跳跃多一步，所以隔一个跳一个，最多只能跳n的最长距离（n为数组长度）

### 代码

```java
class Solution {
    public boolean canCross(int[] stones) {
        int n=stones.length,dis;
        if(n<=1) return true;
        boolean dp[][]=new boolean[n][n+1];
        dp[0][0]=true;
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++){
                dis=stones[i]-stones[j];
                if(dis>=n) continue;
                if(dp[j][dis]||dp[j][dis+1]||(dis>0&&dp[j][dis-1]))
                    dp[i][dis]=true;
            }
        for(int i=0;i<=n;i++)
            if(dp[n-1][i])  return true;
        return false;
    }
}
```