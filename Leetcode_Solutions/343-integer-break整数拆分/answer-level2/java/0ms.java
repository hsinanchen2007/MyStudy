class Solution {
    public int integerBreak(int n) {
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        int k = n / 3;
        int m = n % 3;
        if(n%3==0)
            return (int) Math.pow(3,k);
        else if((n+1)%3==0)
            return (int) (2*Math.pow(3,k));
        else
            return (int) (4*Math.pow(3,k-1));
    }
}
![Q\]~ND0)SF409@EELLISC@`S.png](https://pic.leetcode-cn.com/9fd9e0b9b4f27812d6ad53ad8c534904605dd3929705a5bdba62b9aa8cc5abda-Q%5D~ND0\)SF409@EELLISC@%60S.png)
根据关系式推出如何计算
