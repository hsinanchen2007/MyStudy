### 解题思路
这道题参考了官方解题，数学公式非常简单，但是程序实现较难，官方解题很巧妙啊。
但是最后排除长度为2的数量的时候没用官方的方法，还是选择了排列组合的方法。

### 代码

```java
/*
 * Author: xiaoweixiang
 */
import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        /**
         * 这道题参考了官方解题，数学公式非常简单，但是程序实现较难，官方解题很巧妙啊。
         * 但是最后排除长度为2的数量的时候没用官方的方法，还是选择了排列组合的方法。
         */
        int cnt = 0;
        HashMap<Long, Integer>[] dp = new HashMap[A.length];
        for (int i = 0; i < A.length; i++) {
            dp[i]=new HashMap<Long, Integer>();
            for (int j = 0; j < i; j++) {
                long diff = (long)A[i] - (long)A[j];
                int a = dp[j].getOrDefault(diff, 0);
                int b = dp[i].getOrDefault(diff, 0);
                dp[i].put(diff, a + b + 1);
            }
            for (Map.Entry<Long, Integer> entry : dp[i].entrySet()) {
                cnt += entry.getValue();
            }
        }
        return cnt - (A.length) * (A.length - 1) / 2;
    }
}
```