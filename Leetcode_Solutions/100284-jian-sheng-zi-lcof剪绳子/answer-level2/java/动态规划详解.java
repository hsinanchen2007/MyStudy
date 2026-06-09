### 解题思路
仿照《剑指offer》的动态规划：

我们用长度10作为例子
- 第一个循环是用于求出i长度的最大值
- 第二个循环是剪得长度。

当i = 4, j = 1时表示长度为4，剪成1，3的情况。而我们知道长度为1和3的最大值，只要将他们相乘即可。
当i = 4, j = 2时表示长度为4，剪成2，2的情况。而我们知道长度为2和2的最大值，只要将他们相乘即可。
最后我们可以得出长度为4的绳子的最大值。只要按照这种方式求到10即可得出答案。

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n < 2) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;
        
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        int max = 0;
        for(int i = 4; i <= n; i++){
            for(int j = 1; j <= i / 2; j++){
                int temp = dp[j] * dp[i - j];
                if(max < temp){
                    max = temp;
                }
                dp[i] = max;
            }
        }

        return dp[n];
    }
}
```