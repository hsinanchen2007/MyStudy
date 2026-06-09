### 解题思路
每次res向左移一位，然后加上n最右边的数字，n再右移一位。

### 代码

```java
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++){
            res <<= 1;  // 每次res都左移一位
            res |= (n & 1); // 然后加上n最右边的数字
            n >>= 1;    // n再右移一位
        }
        return res;
    }
}
```