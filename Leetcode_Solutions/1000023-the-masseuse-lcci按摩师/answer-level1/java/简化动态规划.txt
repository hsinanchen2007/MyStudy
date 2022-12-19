### 解题思路
dp[i]表示[0:i]区间内，所取的最大值。
则状态转移方程为：dp[i] = max(dp[i-1], dp[i-2]+nums[i])

由状态转移方程可以看到，每次dp[i]的取值，只与其前面两个值dp[i-1]和dp[i-2]有关，
所以在递推的时候，只需要用两个变量a, b 分别保存dp[i-2]和dp[i-1]的值即可。
在每次更新dp[]的时候，顺便更新a、b的值。

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int a = 0, b = 0;
        int len = nums.length;
        for(int i = 0; i < len; i++){
            int c = Math.max(b, a+nums[i]);
            a = b;
            b = c;              //更新a、b作为下一次递推计算的dp[i-2]、dp[i-1]。
        }
        return b;               //迭代结束后，b的值为新被赋值的更新后的值，即最终结果。
    }
}
```