### 解题思路
![leetcode.jpg](https://pic.leetcode-cn.com/8f87288dea996318b77703404bebe5ec8e710528fab424851325c29a718ee2ca-leetcode.jpg)

主要思路是数位dp：
以dp[i]表示n的1~i位组成的数字所包含2的个数，关键点在于推导出dp[i]与dp[i-1]的关系

例如：n = 3478    
```java
dp[1] == numberOf2sInRange(8)   
dp[2] == numberOf2sInRange(78)
dp[3] == numberOf2sInRange(478)
dp[4] == numberOf2sInRange(3478)

dp[i] = f(dp[i-1]) ? 
```

下面来分析一下dp[i]与dp[i-1]的关系
根据第i位的取值可分为4种情况：
1. 第i位是0
例如：n = 102, 分析dp[2]和dp[1]的关系，即numberOf2sInRange(02)与numberOf2sInRange(2) (02实际是2，写作02便于理解)
第i位是0，该位取值范围只有这一种可能，由此可得
```java
dp[2] = dp[1] 
numberOf2sInRange(02) = numberOf2sInRange(2)
```


2. 第i位是1
例如：n = 178，分析dp[3]和dp[2]的关系，即numberOf2sInRange(178)与numberOf2sInRange(78)
第3位是1，该位可能取0,1两种情况：
```java
dp[3] = 当第3位是0，1-2位取00~99时2的次数 + 当第3位是1, 1-2位取00~78时2的次数
dp[3] = numberOf2sInRange(99) + dp[2]
numberOf2sInRange(178) = numberOf2sInRange(99) + numberOf2sInRange(78)
```

3. 第i位是2
例如：n = 233, 分析dp[3]和dp[2]的关系，即numberOf2sInRange(233)与numberOf2sInRange(33)
```java
dp[3] = 第3位取0-1,1-2位取00~99时2的次数 + 第3位是2,1-2位取00~33时2在1-2位出现的次数 + 第3位是2,1-2位取00~33时2在第3位出现的次数
dp[3] = 2 *numberOf2sInRange(99) + dp[2] + 33 + 1
numberOf2sInRange(233) = 2 * numberOf2sInRange(99) + numberOf2sInRange(33) + 33 + 1
```

4. 第i位大于2
以 n = 478为例，分析dp[3]和dp[2]的关系，即numberOf2sInRange(478)与numberOf2sInRange(78)
```java
dp[3] = 第3位取0-3,1-2位取00-99时2出现在1-2位的次数 + 第3位取4,1-2位取00-78时2的次数 + 第3位取2,1-2位取00-99时2出现在第3位的次数
dp[3] = 4 * numberOf2sInRange(99) + dp[2] + 100
```

总结上面4种情况：
```java
dp[i]与dp[i-1]的关系，假设n的第i位的值为k
dp[i] = k * numberOf2sInRange(99..9){共i-1个9} + dp[i-1] + {n % 10^(i-1) + 1 }{若k == 2}  + { 10^(i-1) } {若k > 2}
```
根据递推公式可以发现，若计算dp[i]，不仅要知道dp[i-1]还要知道numberOf2sInRange(99..9)，所以要同时计算numberOf2sInRange(99..9)的值



### 代码

```java
class Solution {
    public int numberOf2sInRange(int n) {
        if(n == 0) {
            return 0;
        }
        int digit = (int)Math.log10(n) + 1;
        int[][] dp = new int[digit+1][2];  
        // dp[i][0] = numberOf2sInRange(n % pow(10, i)) 保存0~n的1-i位组成的数包含2的个数
        // dp[i][1] = numberOf2sInRange(99..9) 保存i位均为9包含2的个数
        dp[1][0] = n % 10 >= 2 ? 1:0;
        dp[1][1] = 1;
        for(int i = 2; i <= digit; i++) {
            int k = n/ ((int)Math.pow(10, i-1)) % 10;
            dp[i][0] = k * dp[i-1][1] + dp[i-1][0];
            if(k == 2) {
                dp[i][0] += n % (int)Math.pow(10, i-1) +1; 
            } else if(k > 2){
                dp[i][0] +=  (int)Math.pow(10, i-1);
            }
            dp[i][1] = 10 * dp[i-1][1] + (int)Math.pow(10, i-1); //计算1-i位均为9的值包含2的个数
        }
        return dp[digit][0];
    }
}
```