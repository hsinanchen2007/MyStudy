

### 代码

```java
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int sum = 0;
        int len = customers.length;
        for(int i = 0 ; i < len ; i ++){
            if(grumpy[i] == 0) sum += customers[i]; 
        }
        int[] dp = new int[len-X+1]; //dp[i] : 以i开头的X长度内不满意变满意数量。
        for(int i = 0 ; i < X ; i ++){ 
            dp[0] += grumpy[i] == 1 ? customers[i] : 0;
        }
        int max = dp[0];
        for(int i = 1 ; i <= len - X; i ++){
            dp[i] = dp[i-1] + (grumpy[i+X-1] == 1 ? customers[i+X-1]:0) - (grumpy[i-1] == 1 ? customers[i-1] : 0);
            max = Math.max(max , dp[i]);
        }
        return max + sum;

    }
}
```