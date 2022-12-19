# 边界
n==1: return 1；
n==2: return 2；

# 递推方程
设F(i)为1~i之间数构成二叉搜索树的个数，初值F(0)=1,F(1)=1,F(2)=2;
则1...i这些节点中，有i种可能的头节点，设头节点为j时，则左子树个数F(j-1)，右子树个数F(i-j-1);
递推方程F(i)=Add(F(j-1)*F(i-j-1)),1<=j<=i。

```java []
class Solution {
    public int numTrees(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int[] dp=new int[n+1];
        dp[0]=1;dp[1]=1;dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=(dp[j]*dp[i-1-j]);
            }
        }
        return dp[n];
    }
}
```


