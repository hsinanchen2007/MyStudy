### 解题思路
动态规划的算法：应为绳子的每个子长度的最优解是最后总长度的最优解，所以先求出子长度的最优解，使用dp数组存放各子长度的最优解

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n<2)
            return 0;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        //当长度超过4时
        int[] dp = new int[n+1];//存放各个子长度的最优解
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;

        int max =0;
        for (int i = 4; i <= n; i++) {//以此计算子长度4，5，6...n的各子长度最优解
            max=0;
            int temp=0;
            for (int j = 1; j <=i/2 ; j++) {
                 temp= dp[j]*dp[i-j]; //各种子长度相乘的临时解
                if(max<temp){
                    max=temp;
                }
            }
            dp[i]=max;
        }
        max=dp[n];
        return max;
    }
}
```