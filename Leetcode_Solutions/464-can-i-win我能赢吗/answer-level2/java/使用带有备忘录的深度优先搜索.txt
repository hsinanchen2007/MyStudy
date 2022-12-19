
重点在于使用bit保存当前使用过的数字

```java
class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        int canReachTotal = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (canReachTotal < desiredTotal) { // 达不到
            return false;
        } else if (canReachTotal == desiredTotal) { // 刚好达到，maxChoosableInteger奇数赢
            return (maxChoosableInteger & 1) == 1;
        }
        
        return canWin(0, desiredTotal, maxChoosableInteger, new int[1 << maxChoosableInteger]);
    }
    
    private boolean canWin(int bits, int distance, int maxChoosableInteger, int[] dp) {
        if (dp[bits] != 0) { // 已经计算过。0：未计算，1：true，2：false
            return dp[bits] == 1;
        }
        
        boolean result = false;
        for (int cur = maxChoosableInteger; cur > 0; cur--) {
            int curBit = 1 << (cur - 1);
            if ((bits & curBit) == 0) { // 当前值没有被使用
                if (cur >= distance // 可以一步成功
                    || !canWin(bits | curBit, distance - cur, maxChoosableInteger, dp)) { // 如果能找到一步让对方无法赢
                    result = true;
                    break;
                }
            }
        }
        
        dp[bits] = result ? 1 : 2;
        return result;
    }
}
```
