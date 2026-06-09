### 解题思路
dp[i] = 1 + dp[i - n]; （n为小于i的最大2的倍数）
dp[7] = 1 + dp[7 - 4];

### 代码

```java
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num + 1];
        res[0] = 0;

        int cur = 1, next = cur << 1;
        for (int i = 1; i <= num; i++) {
            if (i == next) {
                cur = next;
                next = next << 1;
            }
            res[i] = 1 + res[i - cur];
        }
        return res;
    }
}
```