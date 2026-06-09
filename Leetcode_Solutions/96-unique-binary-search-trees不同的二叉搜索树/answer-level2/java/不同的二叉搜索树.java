### 解题思路
   动态规划法，官方题解上写的非常好

### 代码

```java
class Solution {
    public int numTrees(int n) {
        //本题采用的方法：动态规划
        int [] G=new int[n+1];
        G[0]=1;
        G[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                G[i]=G[i]+G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
}
```