整型就是32位，每次判断最后一位是否为1（与1做&与运算），然后向右移位运算，来代替除2，移动32位后结束，不需要考虑正负数。
```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        if(n == 0) return 0;
        int count = 0;
        for(int i = 0; i < 32; i++){
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
}
```