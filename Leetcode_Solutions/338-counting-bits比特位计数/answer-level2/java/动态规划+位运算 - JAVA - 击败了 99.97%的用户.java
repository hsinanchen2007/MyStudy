### 一. 枚举
先枚举几个值,找一下规律
0 1 2  3  4    5
0 1 10 11 100  111

### 二. 找规律
可以发现 第i个数跟 i/2(ps: 也就是i>>1) 的区别
当 i 是偶数 那 dp[i] = dp[i>>1];
当 i 是奇数 那 dp[i] = dp[i>>1] + 1;
本质: 一个数进行位运算的右移在二进制的表示其实就是加了个0,左移其实就是丢弃最后一位
i>>1 等价于 i/2
i<<1 等价于 1*2

### 三. 列方程
所以状态转移方程  dp[i] = dp[i>>1] + (i&1);

### 四. 代码

```
class Solution {
    public int[] countBits(int num) {
        if (num == 0){
            return new int[]{0};
        }
        int[] dp = new int[num+1];
        dp[0] = 0; 
        dp[1] = 1;
        for(int i = 2 ; i <= num ; i++){
            dp[i] = dp[i>>1] + (i&1);
        }
        return dp;
    }
}
```
